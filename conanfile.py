from os import path
from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps, cmake_layout

def create_script(grammar_name, antlr4_version):
    script = f"""#!/bin/bash

    #################################################################
    # Auto-generated by conanfile.py when running conan install .   #
    # DO NOT MODIFY DIRECTLY, modify it inside conanfile.py instead.#
    #################################################################

    RED='\\033[0;31m'
    GREEN='\\033[0;32m'
    NORMAL_OUTPUT='\\033[0m'

    # Work at the scripts directory
    cd "$(dirname "$0")"

    export ANTLR_HOME="~/.local/bin"
    export ANTLR_JAR="$ANTLR_HOME/antlr-VERSION-complete.jar"
    export CLASSPATH=".:$ANTLR_JAR:$CLASSPATH"
    alias antlr4="java -jar $ANTLR_JAR"
    alias grun="java org.antlr.v4.gui.TestRig"

    on_error() {{
        echo -e "${{RED}}An error occurred, script has aborted.$NORMAL_OUTPUT"
    }}

    set -e
    trap on_error ERR

    echo -e "${{GREEN}}Installing antlr-{antlr4_version}" if it is not installed already.$NORMAL_OUTPUT
    cd ~/.local/bin && [ ! -f "antlr-{antlr4_version}-complete.jar" ] && wget https://www.antlr.org/download/antlr-{antlr4_version}-complete.jar
    cd -

    echo -e "${{GREEN}}Generating antlr files.$NORMAL_OUTPUT"

    if [ -d "autogenerated" ]; then
        rm -r "autogenerated"
    fi
    mkdir -p autogenerated
    java -jar ~/.local/bin/antlr-VERSION-complete.jar -o autogenerated -no-listener -visitor -Dlanguage=Cpp {grammar_name}.g4
    echo -e "${{GREEN}}Fishing the auto-generation of {grammar_name} successfully.$NORMAL_OUTPUT"
    """
    return script.replace('VERSION', antlr4_version)

def create_antlr_autogeneration_scripts(antlr4_version):
    parsing_dir = path.join("src", "core_server", "internal", "parsing")
    with open(path.join(parsing_dir, "ceql_query", "autogenerate_script.sh"),
              "w", encoding="utf-8") as f:
        f.write(create_script("CEQL_QUERY", antlr4_version))
    with open(path.join(parsing_dir, "stream_declaration", "autogenerate_script.sh"),
              "w", encoding="utf-8") as f:
        f.write(create_script("STREAM_DECLARATION", antlr4_version))

class CORE(ConanFile):
    name = "core"
    version = "0.0"

    # Binary Configurations
    settings = "os", "compiler", "build_type", "arch"
    # options = ...
    # default_options = ...

    exports_sources = "CMakeLists.txt", "src/*"

    generators = "CMakeDeps" , "CMakeToolchain"

    # Optional metadata
    # license = ...
    author = "Pontificia Universidad Católica de Chile"
    description = "A Complex Event Recognition Engine Library Developed at PUC"
    # url = "<Package recipe repository url here, for issues about the package>"
    homepage = "https://github.com/CER-CORE/CORE"
    # topics = ("<Put some tag here>", "<here>", "<and here>")

    # Specific versions of the used code
    ANTLR4_VERSION = "4.12.0"
    CATCH2_VERSION = "3.3.2"

    def layout(self):
        cmake_layout(self)

    def package_info(self):
        # self.cpp_info.system_libs = ["dl", "rt", "pthread"]
        self.cpp_info.libs = ["CORE"]

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def requirements(self):
        self.requires("antlr4-cppruntime/" + CORE.ANTLR4_VERSION)
        create_antlr_autogeneration_scripts(CORE.ANTLR4_VERSION)
        self.requires("catch2/" + CORE.CATCH2_VERSION)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
