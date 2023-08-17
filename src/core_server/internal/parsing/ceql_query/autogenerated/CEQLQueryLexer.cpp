
// Generated from CEQLQueryLexer.g4 by ANTLR 4.12.0


#include "CEQLQueryLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct CEQLQueryLexerStaticData final {
  CEQLQueryLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CEQLQueryLexerStaticData(const CEQLQueryLexerStaticData&) = delete;
  CEQLQueryLexerStaticData(CEQLQueryLexerStaticData&&) = delete;
  CEQLQueryLexerStaticData& operator=(const CEQLQueryLexerStaticData&) = delete;
  CEQLQueryLexerStaticData& operator=(CEQLQueryLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag ceqlquerylexerLexerOnceFlag;
CEQLQueryLexerStaticData *ceqlquerylexerLexerStaticData = nullptr;

void ceqlquerylexerLexerInitialize() {
  assert(ceqlquerylexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<CEQLQueryLexerStaticData>(
    std::vector<std::string>{
      "K_ALL", "K_AND", "K_ANY", "K_AS", "K_BY", "K_CONSUME", "K_DISTINCT", 
      "K_EVENT", "K_EVENTS", "K_FILTER", "K_FROM", "K_HOURS", "K_IN", "K_LAST", 
      "K_LIKE", "K_MAX", "K_MINUTES", "K_NEXT", "K_NONE", "K_NOT", "K_OR", 
      "K_PARTITION", "K_RANGE", "K_SECONDS", "K_SELECT", "K_STREAM", "K_STRICT", 
      "K_UNLESS", "K_WHERE", "K_WITHIN", "PERCENT", "PLUS", "MINUS", "STAR", 
      "SLASH", "LE", "LEQ", "GE", "GEQ", "EQ", "NEQ", "SEMICOLON", "COMMA", 
      "DOUBLE_DOT", "LEFT_PARENTHESIS", "RIGHT_PARENTHESIS", "LEFT_SQUARE_BRACKET", 
      "RIGHT_SQUARE_BRACKET", "LEFT_CURLY_BRACKET", "RIGHT_CURLY_BRACKET", 
      "IDENTIFIER", "DOUBLE_LITERAL", "INTEGER_LITERAL", "NUMERICAL_EXPONENT", 
      "STRING_LITERAL", "SINGLE_LINE_COMMENT", "MULTILINE_COMMENT", "SPACES", 
      "UNEXPECTED_CHAR", "DIGIT", "A", "B", "C", "D", "E", "F", "G", "H", 
      "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", 
      "W", "X", "Y", "Z", "REGEX_START", "REGEX_END", "REGEX_END_ESCAPED", 
      "REGEX_PIPE", "REGEX_EXCLAMAITON", "REGEX_L_CURLY", "REGEX_R_CURLY", 
      "REGEX_L_PAR", "REGEX_R_PAR", "REGEX_COMMA", "REGEX_QUESTION", "REGEX_PLUS", 
      "REGEX_STAR", "REGEX_HAT", "REGEX_HYPHEN", "REGEX_L_BRACK", "REGEX_R_BRACK", 
      "REGEX_BACKSLASH", "REGEX_ALPHA", "REGEX_DOT", "REGEX_DOUBLED_DOT", 
      "UNRECOGNIZED", "REGEX_DECIMAL_DIGIT", "REGEX_NOT_DECIMAL_DIGIT", 
      "REGEX_WHITESPACE", "REGEX_NOT_WHITESPACE", "REGEX_ALPHANUMERIC", 
      "REGEX_NOT_ALPHANUMERIC", "REGEX_DIGIT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE", "REGEX"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "'%'", "", 
      "", "", "'/'", "'<'", "'<='", "'>'", "'>='", "", "", "';'", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "'<<'", 
      "'>>'", "'\\>'", "'|'", "'!'", "", "", "", "", "", "'\\u003F'", "", 
      "", "'^'", "", "", "", "'\\'", "", "'.'", "", "", "'\\d'", "'\\D'", 
      "'\\s'", "'\\S'", "'\\w'", "'\\W'"
    },
    std::vector<std::string>{
      "", "K_ALL", "K_AND", "K_ANY", "K_AS", "K_BY", "K_CONSUME", "K_DISTINCT", 
      "K_EVENT", "K_EVENTS", "K_FILTER", "K_FROM", "K_HOURS", "K_IN", "K_LAST", 
      "K_LIKE", "K_MAX", "K_MINUTES", "K_NEXT", "K_NONE", "K_NOT", "K_OR", 
      "K_PARTITION", "K_RANGE", "K_SECONDS", "K_SELECT", "K_STREAM", "K_STRICT", 
      "K_UNLESS", "K_WHERE", "K_WITHIN", "PERCENT", "PLUS", "MINUS", "STAR", 
      "SLASH", "LE", "LEQ", "GE", "GEQ", "EQ", "NEQ", "SEMICOLON", "COMMA", 
      "DOUBLE_DOT", "LEFT_PARENTHESIS", "RIGHT_PARENTHESIS", "LEFT_SQUARE_BRACKET", 
      "RIGHT_SQUARE_BRACKET", "LEFT_CURLY_BRACKET", "RIGHT_CURLY_BRACKET", 
      "IDENTIFIER", "DOUBLE_LITERAL", "INTEGER_LITERAL", "NUMERICAL_EXPONENT", 
      "STRING_LITERAL", "SINGLE_LINE_COMMENT", "MULTILINE_COMMENT", "SPACES", 
      "UNEXPECTED_CHAR", "REGEX_START", "REGEX_END", "REGEX_END_ESCAPED", 
      "REGEX_PIPE", "REGEX_EXCLAMAITON", "REGEX_L_CURLY", "REGEX_R_CURLY", 
      "REGEX_L_PAR", "REGEX_R_PAR", "REGEX_COMMA", "REGEX_QUESTION", "REGEX_PLUS", 
      "REGEX_STAR", "REGEX_HAT", "REGEX_HYPHEN", "REGEX_L_BRACK", "REGEX_R_BRACK", 
      "REGEX_BACKSLASH", "REGEX_ALPHA", "REGEX_DOT", "REGEX_DOUBLED_DOT", 
      "UNRECOGNIZED", "REGEX_DECIMAL_DIGIT", "REGEX_NOT_DECIMAL_DIGIT", 
      "REGEX_WHITESPACE", "REGEX_NOT_WHITESPACE", "REGEX_ALPHANUMERIC", 
      "REGEX_NOT_ALPHANUMERIC", "REGEX_DIGIT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,88,687,6,-1,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,
  	2,6,7,6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,
  	13,2,14,7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,
  	20,2,21,7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,
  	27,2,28,7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,
  	34,2,35,7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,
  	41,2,42,7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,
  	48,2,49,7,49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,
  	55,2,56,7,56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,2,62,7,
  	62,2,63,7,63,2,64,7,64,2,65,7,65,2,66,7,66,2,67,7,67,2,68,7,68,2,69,7,
  	69,2,70,7,70,2,71,7,71,2,72,7,72,2,73,7,73,2,74,7,74,2,75,7,75,2,76,7,
  	76,2,77,7,77,2,78,7,78,2,79,7,79,2,80,7,80,2,81,7,81,2,82,7,82,2,83,7,
  	83,2,84,7,84,2,85,7,85,2,86,7,86,2,87,7,87,2,88,7,88,2,89,7,89,2,90,7,
  	90,2,91,7,91,2,92,7,92,2,93,7,93,2,94,7,94,2,95,7,95,2,96,7,96,2,97,7,
  	97,2,98,7,98,2,99,7,99,2,100,7,100,2,101,7,101,2,102,7,102,2,103,7,103,
  	2,104,7,104,2,105,7,105,2,106,7,106,2,107,7,107,2,108,7,108,2,109,7,109,
  	2,110,7,110,2,111,7,111,2,112,7,112,2,113,7,113,2,114,7,114,1,0,1,0,1,
  	0,1,0,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,4,1,4,1,4,1,5,1,5,
  	1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,
  	7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,
  	1,10,1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,3,11,298,8,11,1,12,
  	1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,15,1,15,
  	1,15,1,15,1,16,1,16,1,16,1,16,1,16,1,16,1,16,3,16,324,8,16,1,17,1,17,
  	1,17,1,17,1,17,1,18,1,18,1,18,1,18,1,18,1,19,1,19,1,19,1,19,1,20,1,20,
  	1,20,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,22,1,22,1,22,
  	1,22,1,22,1,22,1,23,1,23,1,23,1,23,1,23,1,23,1,23,3,23,366,8,23,1,24,
  	1,24,1,24,1,24,1,24,1,24,1,24,1,25,1,25,1,25,1,25,1,25,1,25,1,25,1,26,
  	1,26,1,26,1,26,1,26,1,26,1,26,1,27,1,27,1,27,1,27,1,27,1,27,1,27,1,28,
  	1,28,1,28,1,28,1,28,1,28,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,30,1,30,
  	1,31,1,31,1,32,1,32,1,33,1,33,1,34,1,34,1,35,1,35,1,36,1,36,1,36,1,37,
  	1,37,1,38,1,38,1,38,1,39,1,39,1,39,3,39,432,8,39,1,40,1,40,1,40,1,40,
  	3,40,438,8,40,1,41,1,41,1,42,1,42,1,43,1,43,1,43,1,44,1,44,1,45,1,45,
  	1,46,1,46,1,47,1,47,1,48,1,48,1,49,1,49,1,50,1,50,1,50,1,50,5,50,463,
  	8,50,10,50,12,50,466,9,50,1,50,1,50,1,50,5,50,471,8,50,10,50,12,50,474,
  	9,50,3,50,476,8,50,1,51,1,51,1,51,1,51,1,51,3,51,483,8,51,1,51,1,51,4,
  	51,487,8,51,11,51,12,51,488,1,51,3,51,492,8,51,1,51,1,51,4,51,496,8,51,
  	11,51,12,51,497,1,51,1,51,3,51,502,8,51,1,52,4,52,505,8,52,11,52,12,52,
  	506,1,53,1,53,3,53,511,8,53,1,53,4,53,514,8,53,11,53,12,53,515,1,54,1,
  	54,1,54,1,54,5,54,522,8,54,10,54,12,54,525,9,54,1,54,1,54,1,55,1,55,1,
  	55,1,55,5,55,533,8,55,10,55,12,55,536,9,55,1,55,1,55,1,56,1,56,1,56,1,
  	56,5,56,544,8,56,10,56,12,56,547,9,56,1,56,1,56,1,56,3,56,552,8,56,1,
  	56,1,56,1,57,1,57,1,57,1,57,1,58,1,58,1,59,1,59,1,60,1,60,1,61,1,61,1,
  	62,1,62,1,63,1,63,1,64,1,64,1,65,1,65,1,66,1,66,1,67,1,67,1,68,1,68,1,
  	69,1,69,1,70,1,70,1,71,1,71,1,72,1,72,1,73,1,73,1,74,1,74,1,75,1,75,1,
  	76,1,76,1,77,1,77,1,78,1,78,1,79,1,79,1,80,1,80,1,81,1,81,1,82,1,82,1,
  	83,1,83,1,84,1,84,1,85,1,85,1,86,1,86,1,86,1,86,1,86,1,87,1,87,1,87,1,
  	87,1,87,1,88,1,88,1,88,1,89,1,89,1,90,1,90,1,91,1,91,1,92,1,92,1,93,1,
  	93,1,94,1,94,1,95,1,95,1,96,1,96,1,97,1,97,1,98,1,98,1,99,1,99,1,100,
  	1,100,1,101,1,101,1,102,1,102,1,103,1,103,1,104,1,104,1,105,1,105,1,106,
  	1,106,1,106,1,107,1,107,1,108,1,108,1,108,1,109,1,109,1,109,1,110,1,110,
  	1,110,1,111,1,111,1,111,1,112,1,112,1,112,1,113,1,113,1,113,1,114,1,114,
  	1,545,0,115,2,1,4,2,6,3,8,4,10,5,12,6,14,7,16,8,18,9,20,10,22,11,24,12,
  	26,13,28,14,30,15,32,16,34,17,36,18,38,19,40,20,42,21,44,22,46,23,48,
  	24,50,25,52,26,54,27,56,28,58,29,60,30,62,31,64,32,66,33,68,34,70,35,
  	72,36,74,37,76,38,78,39,80,40,82,41,84,42,86,43,88,44,90,45,92,46,94,
  	47,96,48,98,49,100,50,102,51,104,52,106,53,108,54,110,55,112,56,114,57,
  	116,58,118,59,120,0,122,0,124,0,126,0,128,0,130,0,132,0,134,0,136,0,138,
  	0,140,0,142,0,144,0,146,0,148,0,150,0,152,0,154,0,156,0,158,0,160,0,162,
  	0,164,0,166,0,168,0,170,0,172,0,174,60,176,61,178,62,180,63,182,64,184,
  	65,186,66,188,67,190,68,192,69,194,70,196,71,198,72,200,73,202,74,204,
  	75,206,76,208,77,210,78,212,79,214,80,216,81,218,82,220,83,222,84,224,
  	85,226,86,228,87,230,88,2,0,1,34,1,0,96,96,3,0,65,90,95,95,97,122,4,0,
  	48,57,65,90,95,95,97,122,1,0,39,39,2,0,10,10,13,13,3,0,9,11,13,13,32,
  	32,1,0,48,57,2,0,65,65,97,97,2,0,66,66,98,98,2,0,67,67,99,99,2,0,68,68,
  	100,100,2,0,69,69,101,101,2,0,70,70,102,102,2,0,71,71,103,103,2,0,72,
  	72,104,104,2,0,73,73,105,105,2,0,74,74,106,106,2,0,75,75,107,107,2,0,
  	76,76,108,108,2,0,77,77,109,109,2,0,78,78,110,110,2,0,79,79,111,111,2,
  	0,80,80,112,112,2,0,81,81,113,113,2,0,82,82,114,114,2,0,83,83,115,115,
  	2,0,84,84,116,116,2,0,85,85,117,117,2,0,86,86,118,118,2,0,87,87,119,119,
  	2,0,88,88,120,120,2,0,89,89,121,121,2,0,90,90,122,122,2,0,65,90,97,122,
  	681,0,2,1,0,0,0,0,4,1,0,0,0,0,6,1,0,0,0,0,8,1,0,0,0,0,10,1,0,0,0,0,12,
  	1,0,0,0,0,14,1,0,0,0,0,16,1,0,0,0,0,18,1,0,0,0,0,20,1,0,0,0,0,22,1,0,
  	0,0,0,24,1,0,0,0,0,26,1,0,0,0,0,28,1,0,0,0,0,30,1,0,0,0,0,32,1,0,0,0,
  	0,34,1,0,0,0,0,36,1,0,0,0,0,38,1,0,0,0,0,40,1,0,0,0,0,42,1,0,0,0,0,44,
  	1,0,0,0,0,46,1,0,0,0,0,48,1,0,0,0,0,50,1,0,0,0,0,52,1,0,0,0,0,54,1,0,
  	0,0,0,56,1,0,0,0,0,58,1,0,0,0,0,60,1,0,0,0,0,62,1,0,0,0,0,64,1,0,0,0,
  	0,66,1,0,0,0,0,68,1,0,0,0,0,70,1,0,0,0,0,72,1,0,0,0,0,74,1,0,0,0,0,76,
  	1,0,0,0,0,78,1,0,0,0,0,80,1,0,0,0,0,82,1,0,0,0,0,84,1,0,0,0,0,86,1,0,
  	0,0,0,88,1,0,0,0,0,90,1,0,0,0,0,92,1,0,0,0,0,94,1,0,0,0,0,96,1,0,0,0,
  	0,98,1,0,0,0,0,100,1,0,0,0,0,102,1,0,0,0,0,104,1,0,0,0,0,106,1,0,0,0,
  	0,108,1,0,0,0,0,110,1,0,0,0,0,112,1,0,0,0,0,114,1,0,0,0,0,116,1,0,0,0,
  	0,118,1,0,0,0,0,174,1,0,0,0,1,176,1,0,0,0,1,178,1,0,0,0,1,180,1,0,0,0,
  	1,182,1,0,0,0,1,184,1,0,0,0,1,186,1,0,0,0,1,188,1,0,0,0,1,190,1,0,0,0,
  	1,192,1,0,0,0,1,194,1,0,0,0,1,196,1,0,0,0,1,198,1,0,0,0,1,200,1,0,0,0,
  	1,202,1,0,0,0,1,204,1,0,0,0,1,206,1,0,0,0,1,208,1,0,0,0,1,210,1,0,0,0,
  	1,212,1,0,0,0,1,214,1,0,0,0,1,216,1,0,0,0,1,218,1,0,0,0,1,220,1,0,0,0,
  	1,222,1,0,0,0,1,224,1,0,0,0,1,226,1,0,0,0,1,228,1,0,0,0,1,230,1,0,0,0,
  	2,232,1,0,0,0,4,236,1,0,0,0,6,240,1,0,0,0,8,244,1,0,0,0,10,247,1,0,0,
  	0,12,250,1,0,0,0,14,258,1,0,0,0,16,267,1,0,0,0,18,273,1,0,0,0,20,280,
  	1,0,0,0,22,287,1,0,0,0,24,292,1,0,0,0,26,299,1,0,0,0,28,302,1,0,0,0,30,
  	307,1,0,0,0,32,312,1,0,0,0,34,316,1,0,0,0,36,325,1,0,0,0,38,330,1,0,0,
  	0,40,335,1,0,0,0,42,339,1,0,0,0,44,342,1,0,0,0,46,352,1,0,0,0,48,358,
  	1,0,0,0,50,367,1,0,0,0,52,374,1,0,0,0,54,381,1,0,0,0,56,388,1,0,0,0,58,
  	395,1,0,0,0,60,401,1,0,0,0,62,408,1,0,0,0,64,410,1,0,0,0,66,412,1,0,0,
  	0,68,414,1,0,0,0,70,416,1,0,0,0,72,418,1,0,0,0,74,420,1,0,0,0,76,423,
  	1,0,0,0,78,425,1,0,0,0,80,431,1,0,0,0,82,437,1,0,0,0,84,439,1,0,0,0,86,
  	441,1,0,0,0,88,443,1,0,0,0,90,446,1,0,0,0,92,448,1,0,0,0,94,450,1,0,0,
  	0,96,452,1,0,0,0,98,454,1,0,0,0,100,456,1,0,0,0,102,475,1,0,0,0,104,501,
  	1,0,0,0,106,504,1,0,0,0,108,508,1,0,0,0,110,517,1,0,0,0,112,528,1,0,0,
  	0,114,539,1,0,0,0,116,555,1,0,0,0,118,559,1,0,0,0,120,561,1,0,0,0,122,
  	563,1,0,0,0,124,565,1,0,0,0,126,567,1,0,0,0,128,569,1,0,0,0,130,571,1,
  	0,0,0,132,573,1,0,0,0,134,575,1,0,0,0,136,577,1,0,0,0,138,579,1,0,0,0,
  	140,581,1,0,0,0,142,583,1,0,0,0,144,585,1,0,0,0,146,587,1,0,0,0,148,589,
  	1,0,0,0,150,591,1,0,0,0,152,593,1,0,0,0,154,595,1,0,0,0,156,597,1,0,0,
  	0,158,599,1,0,0,0,160,601,1,0,0,0,162,603,1,0,0,0,164,605,1,0,0,0,166,
  	607,1,0,0,0,168,609,1,0,0,0,170,611,1,0,0,0,172,613,1,0,0,0,174,615,1,
  	0,0,0,176,620,1,0,0,0,178,625,1,0,0,0,180,628,1,0,0,0,182,630,1,0,0,0,
  	184,632,1,0,0,0,186,634,1,0,0,0,188,636,1,0,0,0,190,638,1,0,0,0,192,640,
  	1,0,0,0,194,642,1,0,0,0,196,644,1,0,0,0,198,646,1,0,0,0,200,648,1,0,0,
  	0,202,650,1,0,0,0,204,652,1,0,0,0,206,654,1,0,0,0,208,656,1,0,0,0,210,
  	658,1,0,0,0,212,660,1,0,0,0,214,662,1,0,0,0,216,665,1,0,0,0,218,667,1,
  	0,0,0,220,670,1,0,0,0,222,673,1,0,0,0,224,676,1,0,0,0,226,679,1,0,0,0,
  	228,682,1,0,0,0,230,685,1,0,0,0,232,233,3,122,60,0,233,234,3,144,71,0,
  	234,235,3,144,71,0,235,3,1,0,0,0,236,237,3,122,60,0,237,238,3,148,73,
  	0,238,239,3,128,63,0,239,5,1,0,0,0,240,241,3,122,60,0,241,242,3,148,73,
  	0,242,243,3,170,84,0,243,7,1,0,0,0,244,245,3,122,60,0,245,246,3,158,78,
  	0,246,9,1,0,0,0,247,248,3,124,61,0,248,249,3,170,84,0,249,11,1,0,0,0,
  	250,251,3,126,62,0,251,252,3,150,74,0,252,253,3,148,73,0,253,254,3,158,
  	78,0,254,255,3,162,80,0,255,256,3,146,72,0,256,257,3,130,64,0,257,13,
  	1,0,0,0,258,259,3,128,63,0,259,260,3,138,68,0,260,261,3,158,78,0,261,
  	262,3,160,79,0,262,263,3,138,68,0,263,264,3,148,73,0,264,265,3,126,62,
  	0,265,266,3,160,79,0,266,15,1,0,0,0,267,268,3,130,64,0,268,269,3,164,
  	81,0,269,270,3,130,64,0,270,271,3,148,73,0,271,272,3,160,79,0,272,17,
  	1,0,0,0,273,274,3,130,64,0,274,275,3,164,81,0,275,276,3,130,64,0,276,
  	277,3,148,73,0,277,278,3,160,79,0,278,279,3,158,78,0,279,19,1,0,0,0,280,
  	281,3,132,65,0,281,282,3,138,68,0,282,283,3,144,71,0,283,284,3,160,79,
  	0,284,285,3,130,64,0,285,286,3,156,77,0,286,21,1,0,0,0,287,288,3,132,
  	65,0,288,289,3,156,77,0,289,290,3,150,74,0,290,291,3,146,72,0,291,23,
  	1,0,0,0,292,293,3,136,67,0,293,294,3,150,74,0,294,295,3,162,80,0,295,
  	297,3,156,77,0,296,298,3,158,78,0,297,296,1,0,0,0,297,298,1,0,0,0,298,
  	25,1,0,0,0,299,300,3,138,68,0,300,301,3,148,73,0,301,27,1,0,0,0,302,303,
  	3,144,71,0,303,304,3,122,60,0,304,305,3,158,78,0,305,306,3,160,79,0,306,
  	29,1,0,0,0,307,308,3,144,71,0,308,309,3,138,68,0,309,310,3,142,70,0,310,
  	311,3,130,64,0,311,31,1,0,0,0,312,313,3,146,72,0,313,314,3,122,60,0,314,
  	315,3,168,83,0,315,33,1,0,0,0,316,317,3,146,72,0,317,318,3,138,68,0,318,
  	319,3,148,73,0,319,320,3,162,80,0,320,321,3,160,79,0,321,323,3,130,64,
  	0,322,324,3,158,78,0,323,322,1,0,0,0,323,324,1,0,0,0,324,35,1,0,0,0,325,
  	326,3,148,73,0,326,327,3,130,64,0,327,328,3,168,83,0,328,329,3,160,79,
  	0,329,37,1,0,0,0,330,331,3,148,73,0,331,332,3,150,74,0,332,333,3,148,
  	73,0,333,334,3,130,64,0,334,39,1,0,0,0,335,336,3,148,73,0,336,337,3,150,
  	74,0,337,338,3,160,79,0,338,41,1,0,0,0,339,340,3,150,74,0,340,341,3,156,
  	77,0,341,43,1,0,0,0,342,343,3,152,75,0,343,344,3,122,60,0,344,345,3,156,
  	77,0,345,346,3,160,79,0,346,347,3,138,68,0,347,348,3,160,79,0,348,349,
  	3,138,68,0,349,350,3,150,74,0,350,351,3,148,73,0,351,45,1,0,0,0,352,353,
  	3,156,77,0,353,354,3,122,60,0,354,355,3,148,73,0,355,356,3,134,66,0,356,
  	357,3,130,64,0,357,47,1,0,0,0,358,359,3,158,78,0,359,360,3,130,64,0,360,
  	361,3,126,62,0,361,362,3,150,74,0,362,363,3,148,73,0,363,365,3,128,63,
  	0,364,366,3,158,78,0,365,364,1,0,0,0,365,366,1,0,0,0,366,49,1,0,0,0,367,
  	368,3,158,78,0,368,369,3,130,64,0,369,370,3,144,71,0,370,371,3,130,64,
  	0,371,372,3,126,62,0,372,373,3,160,79,0,373,51,1,0,0,0,374,375,3,158,
  	78,0,375,376,3,160,79,0,376,377,3,156,77,0,377,378,3,130,64,0,378,379,
  	3,122,60,0,379,380,3,146,72,0,380,53,1,0,0,0,381,382,3,158,78,0,382,383,
  	3,160,79,0,383,384,3,156,77,0,384,385,3,138,68,0,385,386,3,126,62,0,386,
  	387,3,160,79,0,387,55,1,0,0,0,388,389,3,162,80,0,389,390,3,148,73,0,390,
  	391,3,144,71,0,391,392,3,130,64,0,392,393,3,158,78,0,393,394,3,158,78,
  	0,394,57,1,0,0,0,395,396,3,166,82,0,396,397,3,136,67,0,397,398,3,130,
  	64,0,398,399,3,156,77,0,399,400,3,130,64,0,400,59,1,0,0,0,401,402,3,166,
  	82,0,402,403,3,138,68,0,403,404,3,160,79,0,404,405,3,136,67,0,405,406,
  	3,138,68,0,406,407,3,148,73,0,407,61,1,0,0,0,408,409,5,37,0,0,409,63,
  	1,0,0,0,410,411,5,43,0,0,411,65,1,0,0,0,412,413,5,45,0,0,413,67,1,0,0,
  	0,414,415,5,42,0,0,415,69,1,0,0,0,416,417,5,47,0,0,417,71,1,0,0,0,418,
  	419,5,60,0,0,419,73,1,0,0,0,420,421,5,60,0,0,421,422,5,61,0,0,422,75,
  	1,0,0,0,423,424,5,62,0,0,424,77,1,0,0,0,425,426,5,62,0,0,426,427,5,61,
  	0,0,427,79,1,0,0,0,428,429,5,61,0,0,429,432,5,61,0,0,430,432,5,61,0,0,
  	431,428,1,0,0,0,431,430,1,0,0,0,432,81,1,0,0,0,433,434,5,33,0,0,434,438,
  	5,61,0,0,435,436,5,60,0,0,436,438,5,62,0,0,437,433,1,0,0,0,437,435,1,
  	0,0,0,438,83,1,0,0,0,439,440,5,59,0,0,440,85,1,0,0,0,441,442,5,44,0,0,
  	442,87,1,0,0,0,443,444,5,46,0,0,444,445,5,46,0,0,445,89,1,0,0,0,446,447,
  	5,40,0,0,447,91,1,0,0,0,448,449,5,41,0,0,449,93,1,0,0,0,450,451,5,91,
  	0,0,451,95,1,0,0,0,452,453,5,93,0,0,453,97,1,0,0,0,454,455,5,123,0,0,
  	455,99,1,0,0,0,456,457,5,125,0,0,457,101,1,0,0,0,458,464,5,96,0,0,459,
  	463,8,0,0,0,460,461,5,96,0,0,461,463,5,96,0,0,462,459,1,0,0,0,462,460,
  	1,0,0,0,463,466,1,0,0,0,464,462,1,0,0,0,464,465,1,0,0,0,465,467,1,0,0,
  	0,466,464,1,0,0,0,467,476,5,96,0,0,468,472,7,1,0,0,469,471,7,2,0,0,470,
  	469,1,0,0,0,471,474,1,0,0,0,472,470,1,0,0,0,472,473,1,0,0,0,473,476,1,
  	0,0,0,474,472,1,0,0,0,475,458,1,0,0,0,475,468,1,0,0,0,476,103,1,0,0,0,
  	477,478,3,106,52,0,478,479,5,46,0,0,479,480,3,108,53,0,480,502,1,0,0,
  	0,481,483,3,106,52,0,482,481,1,0,0,0,482,483,1,0,0,0,483,484,1,0,0,0,
  	484,486,5,46,0,0,485,487,3,120,59,0,486,485,1,0,0,0,487,488,1,0,0,0,488,
  	486,1,0,0,0,488,489,1,0,0,0,489,502,1,0,0,0,490,492,3,106,52,0,491,490,
  	1,0,0,0,491,492,1,0,0,0,492,493,1,0,0,0,493,495,5,46,0,0,494,496,3,120,
  	59,0,495,494,1,0,0,0,496,497,1,0,0,0,497,495,1,0,0,0,497,498,1,0,0,0,
  	498,499,1,0,0,0,499,500,3,108,53,0,500,502,1,0,0,0,501,477,1,0,0,0,501,
  	482,1,0,0,0,501,491,1,0,0,0,502,105,1,0,0,0,503,505,3,120,59,0,504,503,
  	1,0,0,0,505,506,1,0,0,0,506,504,1,0,0,0,506,507,1,0,0,0,507,107,1,0,0,
  	0,508,510,3,130,64,0,509,511,5,45,0,0,510,509,1,0,0,0,510,511,1,0,0,0,
  	511,513,1,0,0,0,512,514,3,120,59,0,513,512,1,0,0,0,514,515,1,0,0,0,515,
  	513,1,0,0,0,515,516,1,0,0,0,516,109,1,0,0,0,517,523,5,39,0,0,518,522,
  	8,3,0,0,519,520,5,39,0,0,520,522,5,39,0,0,521,518,1,0,0,0,521,519,1,0,
  	0,0,522,525,1,0,0,0,523,521,1,0,0,0,523,524,1,0,0,0,524,526,1,0,0,0,525,
  	523,1,0,0,0,526,527,5,39,0,0,527,111,1,0,0,0,528,529,5,45,0,0,529,530,
  	5,45,0,0,530,534,1,0,0,0,531,533,8,4,0,0,532,531,1,0,0,0,533,536,1,0,
  	0,0,534,532,1,0,0,0,534,535,1,0,0,0,535,537,1,0,0,0,536,534,1,0,0,0,537,
  	538,6,55,0,0,538,113,1,0,0,0,539,540,5,47,0,0,540,541,5,42,0,0,541,545,
  	1,0,0,0,542,544,9,0,0,0,543,542,1,0,0,0,544,547,1,0,0,0,545,546,1,0,0,
  	0,545,543,1,0,0,0,546,551,1,0,0,0,547,545,1,0,0,0,548,549,5,42,0,0,549,
  	552,5,47,0,0,550,552,5,0,0,1,551,548,1,0,0,0,551,550,1,0,0,0,552,553,
  	1,0,0,0,553,554,6,56,0,0,554,115,1,0,0,0,555,556,7,5,0,0,556,557,1,0,
  	0,0,557,558,6,57,0,0,558,117,1,0,0,0,559,560,9,0,0,0,560,119,1,0,0,0,
  	561,562,7,6,0,0,562,121,1,0,0,0,563,564,7,7,0,0,564,123,1,0,0,0,565,566,
  	7,8,0,0,566,125,1,0,0,0,567,568,7,9,0,0,568,127,1,0,0,0,569,570,7,10,
  	0,0,570,129,1,0,0,0,571,572,7,11,0,0,572,131,1,0,0,0,573,574,7,12,0,0,
  	574,133,1,0,0,0,575,576,7,13,0,0,576,135,1,0,0,0,577,578,7,14,0,0,578,
  	137,1,0,0,0,579,580,7,15,0,0,580,139,1,0,0,0,581,582,7,16,0,0,582,141,
  	1,0,0,0,583,584,7,17,0,0,584,143,1,0,0,0,585,586,7,18,0,0,586,145,1,0,
  	0,0,587,588,7,19,0,0,588,147,1,0,0,0,589,590,7,20,0,0,590,149,1,0,0,0,
  	591,592,7,21,0,0,592,151,1,0,0,0,593,594,7,22,0,0,594,153,1,0,0,0,595,
  	596,7,23,0,0,596,155,1,0,0,0,597,598,7,24,0,0,598,157,1,0,0,0,599,600,
  	7,25,0,0,600,159,1,0,0,0,601,602,7,26,0,0,602,161,1,0,0,0,603,604,7,27,
  	0,0,604,163,1,0,0,0,605,606,7,28,0,0,606,165,1,0,0,0,607,608,7,29,0,0,
  	608,167,1,0,0,0,609,610,7,30,0,0,610,169,1,0,0,0,611,612,7,31,0,0,612,
  	171,1,0,0,0,613,614,7,32,0,0,614,173,1,0,0,0,615,616,5,60,0,0,616,617,
  	5,60,0,0,617,618,1,0,0,0,618,619,6,86,1,0,619,175,1,0,0,0,620,621,5,62,
  	0,0,621,622,5,62,0,0,622,623,1,0,0,0,623,624,6,87,2,0,624,177,1,0,0,0,
  	625,626,5,92,0,0,626,627,5,62,0,0,627,179,1,0,0,0,628,629,5,124,0,0,629,
  	181,1,0,0,0,630,631,5,33,0,0,631,183,1,0,0,0,632,633,5,123,0,0,633,185,
  	1,0,0,0,634,635,5,125,0,0,635,187,1,0,0,0,636,637,5,40,0,0,637,189,1,
  	0,0,0,638,639,5,41,0,0,639,191,1,0,0,0,640,641,5,44,0,0,641,193,1,0,0,
  	0,642,643,5,63,0,0,643,195,1,0,0,0,644,645,5,43,0,0,645,197,1,0,0,0,646,
  	647,5,42,0,0,647,199,1,0,0,0,648,649,5,94,0,0,649,201,1,0,0,0,650,651,
  	5,45,0,0,651,203,1,0,0,0,652,653,5,91,0,0,653,205,1,0,0,0,654,655,5,93,
  	0,0,655,207,1,0,0,0,656,657,5,92,0,0,657,209,1,0,0,0,658,659,7,33,0,0,
  	659,211,1,0,0,0,660,661,5,46,0,0,661,213,1,0,0,0,662,663,5,46,0,0,663,
  	664,5,46,0,0,664,215,1,0,0,0,665,666,9,0,0,0,666,217,1,0,0,0,667,668,
  	5,92,0,0,668,669,5,100,0,0,669,219,1,0,0,0,670,671,5,92,0,0,671,672,5,
  	68,0,0,672,221,1,0,0,0,673,674,5,92,0,0,674,675,5,115,0,0,675,223,1,0,
  	0,0,676,677,5,92,0,0,677,678,5,83,0,0,678,225,1,0,0,0,679,680,5,92,0,
  	0,680,681,5,119,0,0,681,227,1,0,0,0,682,683,5,92,0,0,683,684,5,87,0,0,
  	684,229,1,0,0,0,685,686,7,6,0,0,686,231,1,0,0,0,24,0,1,297,323,365,431,
  	437,462,464,472,475,482,488,491,497,501,506,510,515,521,523,534,545,551,
  	3,0,1,0,2,1,0,2,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  ceqlquerylexerLexerStaticData = staticData.release();
}

}

CEQLQueryLexer::CEQLQueryLexer(CharStream *input) : Lexer(input) {
  CEQLQueryLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *ceqlquerylexerLexerStaticData->atn, ceqlquerylexerLexerStaticData->decisionToDFA, ceqlquerylexerLexerStaticData->sharedContextCache);
}

CEQLQueryLexer::~CEQLQueryLexer() {
  delete _interpreter;
}

std::string CEQLQueryLexer::getGrammarFileName() const {
  return "CEQLQueryLexer.g4";
}

const std::vector<std::string>& CEQLQueryLexer::getRuleNames() const {
  return ceqlquerylexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& CEQLQueryLexer::getChannelNames() const {
  return ceqlquerylexerLexerStaticData->channelNames;
}

const std::vector<std::string>& CEQLQueryLexer::getModeNames() const {
  return ceqlquerylexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& CEQLQueryLexer::getVocabulary() const {
  return ceqlquerylexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CEQLQueryLexer::getSerializedATN() const {
  return ceqlquerylexerLexerStaticData->serializedATN;
}

const atn::ATN& CEQLQueryLexer::getATN() const {
  return *ceqlquerylexerLexerStaticData->atn;
}




void CEQLQueryLexer::initialize() {
  ::antlr4::internal::call_once(ceqlquerylexerLexerOnceFlag, ceqlquerylexerLexerInitialize);
}
