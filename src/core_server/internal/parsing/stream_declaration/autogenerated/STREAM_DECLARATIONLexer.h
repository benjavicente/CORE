
// Generated from STREAM_DECLARATION.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"




class  STREAM_DECLARATIONLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, K_ALL = 14, 
    K_AND = 15, K_ANY = 16, K_AS = 17, K_BY = 18, K_CONSUME = 19, K_DECLARE = 20, 
    K_DISTINCT = 21, K_EVENT = 22, K_EVENTS = 23, K_FILTER = 24, K_FROM = 25, 
    K_HOURS = 26, K_IN = 27, K_LAST = 28, K_LIKE = 29, K_MAX = 30, K_MINUTES = 31, 
    K_NEXT = 32, K_NONE = 33, K_NOT = 34, K_OR = 35, K_PARTITION = 36, K_SECONDS = 37, 
    K_SELECT = 38, K_STREAM = 39, K_STRICT = 40, K_UNLESS = 41, K_WHERE = 42, 
    K_WITHIN = 43, PERCENT = 44, PLUS = 45, MINUS = 46, STAR = 47, SLASH = 48, 
    LE = 49, LEQ = 50, GE = 51, GEQ = 52, EQ = 53, NEQ = 54, SEMICOLON = 55, 
    IDENTIFIER = 56, FLOAT_LITERAL = 57, INTEGER_LITERAL = 58, NUMERICAL_EXPONENT = 59, 
    STRING_LITERAL = 60, REGEXP = 61, SINGLE_LINE_COMMENT = 62, MULTILINE_COMMENT = 63, 
    SPACES = 64, UNEXPECTED_CHAR = 65
  };

  explicit STREAM_DECLARATIONLexer(antlr4::CharStream *input);

  ~STREAM_DECLARATIONLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

