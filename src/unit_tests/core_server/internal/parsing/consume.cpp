#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

#include "core_server/internal/ceql/query/query.hpp"
#include "core_server/internal/parsing/ceql_query/autogenerated/CEQLQueryLexer.h"
#include "core_server/internal/parsing/ceql_query/autogenerated/CEQLQueryParser.h"
#include "core_server/internal/parsing/ceql_query/autogenerated/CEQLQueryParserBaseVisitor.h"
#include "core_server/internal/parsing/ceql_query/visitors/consume_visitor.hpp"

namespace CORE::Internal::CEQL::UnitTests {

std::string create_consume_query(std::string consumption_policy) {
  if (consumption_policy != "") {
    consumption_policy = "CONSUME BY " + consumption_policy;
  }
  // clang-format off
  return "SELECT ALL * \n"
         "FROM S, S2\n"
         "WHERE S>T \n"
         "--WHERE H+ OR H+\n"
         "FILTER\n"
         "    all_events[id NOT IN { 123, 125 }]\n"
         "    AND\n"
         "    ( t2[temp > 50 or temp < 20] OR H[income > 2 * cost] )\n"
         "WITHIN 4 EVENTS\n"
         + consumption_policy;
  // clang-format on
}

ConsumeBy parse_consume(std::string query) {
  antlr4::ANTLRInputStream input(query);
  CEQLQueryLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  CEQLQueryParser parser(&tokens);
  antlr4::tree::ParseTree* tree = parser.parse();
  Parsing::ConsumeByVisitor consume_visitor;
  consume_visitor.visit(tree);
  return consume_visitor.get_parsed_consume();
}

TEST_CASE("Consume captures consumption policy correctly", "[Consume, Policy]") {
  // clang-format off
  REQUIRE(parse_consume(create_consume_query("NONE")).policy == ConsumeBy::ConsumptionPolicy::NONE);
  REQUIRE(parse_consume(create_consume_query("ANY")).policy == ConsumeBy::ConsumptionPolicy::ANY);
  REQUIRE(parse_consume(create_consume_query("")).policy == ConsumeBy::ConsumptionPolicy::NONE);
  // clang-format on
}

}  // namespace CORE::Internal::CEQL::UnitTests
