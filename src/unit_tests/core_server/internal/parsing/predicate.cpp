#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

#include "core_server/internal/ceql/query/query.hpp"
#include "core_server/internal/parsing/ceql_query/autogenerated/CEQL_QUERYBaseVisitor.h"
#include "core_server/internal/parsing/ceql_query/autogenerated/CEQL_QUERYLexer.h"
#include "core_server/internal/parsing/ceql_query/autogenerated/CEQL_QUERYParser.h"
#include "core_server/internal/parsing/ceql_query/visitors/where_visitor.hpp"

using namespace InternalCORECEQLParsing;

namespace COREQueryParsingTestsPredicate {

std::string create_query(std::string filter_clause) {
  // clang-format off
  return "SELECT ALL * \n"
         "FROM S, S2\n"
         "WHERE   S>T \n"
         "--WHERE H+ OR H+\n"
         "FILTER\n"
         + filter_clause + "\n"
         "WITHIN 4 EVENTS\n";
  // clang-format on
}

Where parse_where(std::string query) {
  antlr4::ANTLRInputStream input(query);
  CEQL_QUERYLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  CEQL_QUERYParser parser(&tokens);
  antlr4::tree::ParseTree* tree = parser.parse();
  WhereVisitor where_visitor;
  where_visitor.visit(tree);
  return where_visitor.get_parsed_where();
}

template <typename T>
std::unique_ptr<T> cast_to(std::unique_ptr<Formula> unknown) {
  std::unique_ptr<T> casted_optional(dynamic_cast<T*>(unknown.release()));
  return casted_optional;
}

template <typename T>
std::unique_ptr<T> cast_to(std::unique_ptr<Filter> unknown) {
  std::unique_ptr<T> casted_optional(dynamic_cast<T*>(unknown.release()));
  return casted_optional;
}

std::unique_ptr<Predicate> parse_predicate(std::string query) {
  auto where = std::move(parse_where(query));
  auto formula = std::move(where.formula);
  REQUIRE(formula != nullptr);
  auto filter_formula = cast_to<FilterFormula>(std::move(formula));
  REQUIRE(filter_formula != nullptr);
  auto filter = std::move(filter_formula->filter);
  REQUIRE(filter != nullptr);
  auto atomic_filter = cast_to<AtomicFilter>(std::move(filter));
  REQUIRE(atomic_filter != nullptr);
  auto predicate = std::move(atomic_filter->predicate);
  REQUIRE(predicate != nullptr);
  return std::move(predicate);
}

using std::make_unique;

/***********************************/
/* Single functionality unit tests */
/***********************************/

/*************************/
/* Inequality Predicates */
/*************************/

TEST_CASE("== physical_predicate work", "[Predicate, Inequality]") {
  auto query = create_query("t2[temp == 50]");
  std::unique_ptr<Predicate> predicate = parse_predicate(query);
  auto expected_predicate = make_unique<InequalityPredicate>(
      make_unique<Attribute>("temp"),
      InequalityPredicate::LogicalOperation::EQUALS,
      make_unique<IntegerLiteral>(50));
  INFO("Expected: " + expected_predicate->to_string());
  INFO("Got: " + predicate->to_string());
  REQUIRE(predicate->equals(expected_predicate.get()));
}

TEST_CASE("= physical_predicate work", "[Predicate, Inequality]") {
  auto query = create_query("t2[temp = 50]");
  std::unique_ptr<Predicate> predicate = parse_predicate(query);
  auto expected_predicate = make_unique<InequalityPredicate>(
      make_unique<Attribute>("temp"),
      InequalityPredicate::LogicalOperation::EQUALS,
      make_unique<IntegerLiteral>(50));
  INFO("Expected: " + expected_predicate->to_string());
  INFO("Got: " + predicate->to_string());
  REQUIRE(predicate->equals(expected_predicate.get()));
}

TEST_CASE("> physical_predicate works", "[Predicate]") {
  auto query = create_query("t2[temp > 50]");
  std::unique_ptr<Predicate> predicate = parse_predicate(query);
  auto expected_predicate = make_unique<InequalityPredicate>(
      make_unique<Attribute>("temp"),
      InequalityPredicate::LogicalOperation::GREATER,
      make_unique<IntegerLiteral>(50));
  INFO("Expected: " + expected_predicate->to_string());
  INFO("Got: " + predicate->to_string());
  REQUIRE(predicate->equals(expected_predicate.get()));
}

TEST_CASE(">= physical_predicate works", "[Predicate]") {
  auto query = create_query("t2[temp >= 50]");
  std::unique_ptr<Predicate> predicate = parse_predicate(query);
  auto expected_predicate = make_unique<InequalityPredicate>(
      make_unique<Attribute>("temp"),
      InequalityPredicate::LogicalOperation::GREATER_EQUALS,
      make_unique<IntegerLiteral>(50));
  INFO("Expected: " + expected_predicate->to_string());
  INFO("Got: " + predicate->to_string());
  REQUIRE(predicate->equals(expected_predicate.get()));
}

TEST_CASE("<= physical_predicate works", "[Predicate]") {
  auto query = create_query("t2[temp <= 50]");
  std::unique_ptr<Predicate> predicate = parse_predicate(query);
  auto expected_predicate = make_unique<InequalityPredicate>(
      make_unique<Attribute>("temp"),
      InequalityPredicate::LogicalOperation::LESS_EQUALS,
      make_unique<IntegerLiteral>(50));
  INFO("Expected: " + expected_predicate->to_string());
  INFO("Got: " + predicate->to_string());
  REQUIRE(predicate->equals(expected_predicate.get()));
}

TEST_CASE("< physical_predicate works", "[Predicate]") {
  auto query = create_query("t2[temp < 50]");
  std::unique_ptr<Predicate> predicate = parse_predicate(query);
  auto expected_predicate = make_unique<InequalityPredicate>(
      make_unique<Attribute>("temp"),
      InequalityPredicate::LogicalOperation::LESS,
      make_unique<IntegerLiteral>(50));
  INFO("Expected: " + expected_predicate->to_string());
  INFO("Got: " + predicate->to_string());
  REQUIRE(predicate->equals(expected_predicate.get()));
}

TEST_CASE("!= physical_predicate works", "[Predicate]") {
  auto query = create_query("t2[temp != 50]");
  std::unique_ptr<Predicate> predicate = parse_predicate(query);
  auto expected_predicate = make_unique<InequalityPredicate>(
      make_unique<Attribute>("temp"),
      InequalityPredicate::LogicalOperation::NOT_EQUALS,
      make_unique<IntegerLiteral>(50));
  INFO("Expected: " + expected_predicate->to_string());
  INFO("Got: " + predicate->to_string());
  REQUIRE(predicate->equals(expected_predicate.get()));
}

TEST_CASE("<> physical_predicate works", "[Predicate]") {
  auto query = create_query("t2[temp <> 50]");
  std::unique_ptr<Predicate> predicate = parse_predicate(query);
  auto expected_predicate = make_unique<InequalityPredicate>(
      make_unique<Attribute>("temp"),
      InequalityPredicate::LogicalOperation::NOT_EQUALS,
      make_unique<IntegerLiteral>(50));
  INFO("Expected: " + expected_predicate->to_string());
  INFO("Got: " + predicate->to_string());
  REQUIRE(predicate->equals(expected_predicate.get()));
}

/********************************/
/* InequalityPredicate negative */
/********************************/

TEST_CASE("not == physical_predicate work", "[Predicate, Inequality]") {
  auto query = create_query("t2[not temp == 50]");
  std::unique_ptr<Predicate> predicate = parse_predicate(query);
  auto expected_predicate = make_unique<InequalityPredicate>(
      make_unique<Attribute>("temp"),
      InequalityPredicate::LogicalOperation::NOT_EQUALS,
      make_unique<IntegerLiteral>(50));
  INFO("Expected: " + expected_predicate->to_string());
  INFO("Got: " + predicate->to_string());
  REQUIRE(predicate->equals(expected_predicate.get()));
}

TEST_CASE("not = physical_predicate work", "[Predicate, Inequality]") {
  auto query = create_query("t2[not temp = 50]");
  std::unique_ptr<Predicate> predicate = parse_predicate(query);
  auto expected_predicate = make_unique<InequalityPredicate>(
      make_unique<Attribute>("temp"),
      InequalityPredicate::LogicalOperation::NOT_EQUALS,
      make_unique<IntegerLiteral>(50));
  INFO("Expected: " + expected_predicate->to_string());
  INFO("Got: " + predicate->to_string());
  REQUIRE(predicate->equals(expected_predicate.get()));
}

TEST_CASE("not > physical_predicate works", "[Predicate]") {
  auto query = create_query("t2[not temp > 50]");
  std::unique_ptr<Predicate> predicate = parse_predicate(query);
  auto expected_predicate = make_unique<InequalityPredicate>(
      make_unique<Attribute>("temp"),
      InequalityPredicate::LogicalOperation::LESS_EQUALS,
      make_unique<IntegerLiteral>(50));
  INFO("Expected: " + expected_predicate->to_string());
  INFO("Got: " + predicate->to_string());
  REQUIRE(predicate->equals(expected_predicate.get()));
}

TEST_CASE("not >= physical_predicate works", "[Predicate]") {
  auto query = create_query("t2[not temp >= 50]");
  std::unique_ptr<Predicate> predicate = parse_predicate(query);
  auto expected_predicate = make_unique<InequalityPredicate>(
      make_unique<Attribute>("temp"),
      InequalityPredicate::LogicalOperation::LESS,
      make_unique<IntegerLiteral>(50));
  INFO("Expected: " + expected_predicate->to_string());
  INFO("Got: " + predicate->to_string());
  REQUIRE(predicate->equals(expected_predicate.get()));
}

TEST_CASE("not <= physical_predicate works", "[Predicate]") {
  auto query = create_query("t2[not temp <= 50]");
  std::unique_ptr<Predicate> predicate = parse_predicate(query);
  auto expected_predicate = make_unique<InequalityPredicate>(
      make_unique<Attribute>("temp"),
      InequalityPredicate::LogicalOperation::GREATER,
      make_unique<IntegerLiteral>(50));
  INFO("Expected: " + expected_predicate->to_string());
  INFO("Got: " + predicate->to_string());
  REQUIRE(predicate->equals(expected_predicate.get()));
}

TEST_CASE("not < physical_predicate works", "[Predicate]") {
  auto query = create_query("t2[not temp < 50]");
  std::unique_ptr<Predicate> predicate = parse_predicate(query);
  auto expected_predicate = make_unique<InequalityPredicate>(
      make_unique<Attribute>("temp"),
      InequalityPredicate::LogicalOperation::GREATER_EQUALS,
      make_unique<IntegerLiteral>(50));
  INFO("Expected: " + expected_predicate->to_string());
  INFO("Got: " + predicate->to_string());
  REQUIRE(predicate->equals(expected_predicate.get()));
}

TEST_CASE("not != physical_predicate works", "[Predicate]") {
  auto query = create_query("t2[not temp != 50]");
  std::unique_ptr<Predicate> predicate = parse_predicate(query);
  auto expected_predicate = make_unique<InequalityPredicate>(
      make_unique<Attribute>("temp"),
      InequalityPredicate::LogicalOperation::EQUALS,
      make_unique<IntegerLiteral>(50));
  INFO("Expected: " + expected_predicate->to_string());
  INFO("Got: " + predicate->to_string());
  REQUIRE(predicate->equals(expected_predicate.get()));
}

TEST_CASE("not <> physical_predicate works", "[Predicate]") {
  auto query = create_query("t2[not temp <> 50]");
  std::unique_ptr<Predicate> predicate = parse_predicate(query);
  auto expected_predicate = make_unique<InequalityPredicate>(
      make_unique<Attribute>("temp"),
      InequalityPredicate::LogicalOperation::EQUALS,
      make_unique<IntegerLiteral>(50));
  INFO("Expected: " + expected_predicate->to_string());
  INFO("Got: " + predicate->to_string());
  REQUIRE(predicate->equals(expected_predicate.get()));
}

TEST_CASE("In {num_list} physical_predicate", "[Predicate]") {
  auto query = create_query("t2[temp IN {1, 2, 3}]");
  std::unique_ptr<Predicate> predicate = parse_predicate(query);
  std::vector<std::unique_ptr<Value>> number_seq;
  for (int64_t i = 1; i <= 3; i++) {
    number_seq.push_back(make_unique<IntegerLiteral>(i));
  }
  auto expected_predicate = make_unique<InPredicate>(
      make_unique<Attribute>("temp"), Sequence(std::move(number_seq)));
  INFO("Expected: " + expected_predicate->to_string());
  INFO("Got: " + predicate->to_string());
  REQUIRE(predicate->equals(expected_predicate.get()));
}

TEST_CASE("In {...Upper Bound} physical_predicate", "[Predicate]") {
  auto query = create_query("t2[temp IN {..3}]");
  std::unique_ptr<Predicate> predicate = parse_predicate(query);
  std::vector<std::unique_ptr<Value>> number_seq;
  auto expected_predicate =
      make_unique<InPredicate>(make_unique<Attribute>("temp"),
                               Sequence(make_unique<IntegerLiteral>(3),
                                        Sequence::Type::UPPER_BOUND));
  INFO("Expected: " + expected_predicate->to_string());
  INFO("Got: " + predicate->to_string());
  REQUIRE(predicate->equals(expected_predicate.get()));
}

TEST_CASE("In {Lower Bound...} physical_predicate", "[Predicate]") {
  auto query = create_query("t2[temp IN {3..}]");
  std::unique_ptr<Predicate> predicate = parse_predicate(query);
  std::vector<std::unique_ptr<Value>> number_seq;
  auto expected_predicate =
      make_unique<InPredicate>(make_unique<Attribute>("temp"),
                               Sequence(make_unique<IntegerLiteral>(3),
                                        Sequence::Type::LOWER_BOUND));
  INFO("Expected: " + expected_predicate->to_string());
  INFO("Got: " + predicate->to_string());
  REQUIRE(predicate->equals(expected_predicate.get()));
}

TEST_CASE("In {Lower Bound... Upper Bound} physical_predicate",
          "[Predicate]") {
  auto query = create_query("t2[temp IN {3..999999999999}]");
  std::unique_ptr<Predicate> predicate = parse_predicate(query);
  std::vector<std::unique_ptr<Value>> number_seq;
  auto expected_predicate = make_unique<InPredicate>(
      make_unique<Attribute>("temp"),
      Sequence(make_unique<IntegerLiteral>(3),
               make_unique<IntegerLiteral>(999999999999)));
  INFO("Expected: " + expected_predicate->to_string());
  INFO("Got: " + predicate->to_string());
  REQUIRE(predicate->equals(expected_predicate.get()));
}

TEST_CASE("NOT IN {num_list} physical_predicate", "[Predicate]") {
  auto query = create_query("t2[temp NOT IN {1, 2, 3}]");
  std::unique_ptr<Predicate> predicate = parse_predicate(query);
  std::vector<std::unique_ptr<Value>> number_seq;
  for (int64_t i = 1; i <= 3; i++) {
    number_seq.push_back(make_unique<IntegerLiteral>(i));
  }
  auto expected_predicate =
      make_unique<NotPredicate>(make_unique<InPredicate>(
          make_unique<Attribute>("temp"), Sequence(std::move(number_seq))));
  INFO("Expected: " + expected_predicate->to_string());
  INFO("Got: " + predicate->to_string());
  REQUIRE(predicate->equals(expected_predicate.get()));
}

TEST_CASE("NOT IN {...Upper Bound} physical_predicate", "[Predicate]") {
  auto query = create_query("t2[temp NOT IN {..3}]");
  std::unique_ptr<Predicate> predicate = parse_predicate(query);
  std::vector<std::unique_ptr<Value>> number_seq;
  auto expected_predicate = make_unique<NotPredicate>(
      make_unique<InPredicate>(make_unique<Attribute>("temp"),
                               Sequence(make_unique<IntegerLiteral>(3),
                                        Sequence::Type::UPPER_BOUND)));
  INFO("Expected: " + expected_predicate->to_string());
  INFO("Got: " + predicate->to_string());
  REQUIRE(predicate->equals(expected_predicate.get()));
}

TEST_CASE("NOT IN {Lower Bound...} physical_predicate", "[Predicate]") {
  auto query = create_query("t2[temp NOT IN {3..}]");
  std::unique_ptr<Predicate> predicate = parse_predicate(query);
  std::vector<std::unique_ptr<Value>> number_seq;
  auto expected_predicate = make_unique<NotPredicate>(
      make_unique<InPredicate>(make_unique<Attribute>("temp"),
                               Sequence(make_unique<IntegerLiteral>(3),
                                        Sequence::Type::LOWER_BOUND)));
  INFO("Expected: " + expected_predicate->to_string());
  INFO("Got: " + predicate->to_string());
  REQUIRE(predicate->equals(expected_predicate.get()));
}

TEST_CASE("NOT IN {Lower Bound... Upper Bound} physical_predicate",
          "[Predicate]") {
  auto query = create_query("t2[temp NOT IN {3..999999999999}]");
  std::unique_ptr<Predicate> predicate = parse_predicate(query);
  std::vector<std::unique_ptr<Value>> number_seq;
  auto expected_predicate =
      make_unique<NotPredicate>(make_unique<InPredicate>(
          make_unique<Attribute>("temp"),
          Sequence(make_unique<IntegerLiteral>(3),
                   make_unique<IntegerLiteral>(999999999999))));
  INFO("Expected: " + expected_predicate->to_string());
  INFO("Got: " + predicate->to_string());
  REQUIRE(predicate->equals(expected_predicate.get()));
}

TEST_CASE("math_expr IN math_expr_sequence", "[Predicate]") {
  // TODO
}

TEST_CASE("Like", "[Predicate]") {
  // TODO
}

/*****************************/
/* Binary Predicates testing */
/*****************************/

TEST_CASE("P1 AND P2", "[Predicate]") {
  auto query = create_query("t2[not temp != 50 AND temp > 40]");
  std::unique_ptr<Predicate> predicate = parse_predicate(query);
  std::vector<std::unique_ptr<Predicate>> predicates;
  predicates.push_back(make_unique<InequalityPredicate>(
      make_unique<Attribute>("temp"),
      InequalityPredicate::LogicalOperation::EQUALS,
      make_unique<IntegerLiteral>(50)));
  predicates.push_back(make_unique<InequalityPredicate>(
      make_unique<Attribute>("temp"),
      InequalityPredicate::LogicalOperation::GREATER,
      make_unique<IntegerLiteral>(40)));
  auto expected_predicate =
      make_unique<AndPredicate>(std::move(predicates));
  INFO("Expected: " + expected_predicate->to_string());
  INFO("Got: " + predicate->to_string());
  REQUIRE(predicate->equals(expected_predicate.get()));
}

TEST_CASE("NOT (P1 AND P2) = NOT P1 OR NOT P2", "[Predicate]") {
  auto query = create_query("t2[not (not temp != 50 AND temp > 40)]");
  std::unique_ptr<Predicate> predicate = parse_predicate(query);
  std::vector<std::unique_ptr<Predicate>> predicates;
  predicates.push_back(make_unique<InequalityPredicate>(
      make_unique<Attribute>("temp"),
      InequalityPredicate::LogicalOperation::NOT_EQUALS,
      make_unique<IntegerLiteral>(50)));
  predicates.push_back(make_unique<InequalityPredicate>(
      make_unique<Attribute>("temp"),
      InequalityPredicate::LogicalOperation::LESS_EQUALS,
      make_unique<IntegerLiteral>(40)));
  auto expected_predicate = make_unique<OrPredicate>(std::move(predicates));
  INFO("Expected: " + expected_predicate->to_string());
  INFO("Got: " + predicate->to_string());
  REQUIRE(predicate->equals(expected_predicate.get()));
}

TEST_CASE("P1 OR P2", "[Predicate]") {
  auto query = create_query("t2[not temp != 50 OR temp > 40]");
  std::unique_ptr<Predicate> predicate = parse_predicate(query);
  std::vector<std::unique_ptr<Predicate>> predicates;
  predicates.push_back(make_unique<InequalityPredicate>(
      make_unique<Attribute>("temp"),
      InequalityPredicate::LogicalOperation::EQUALS,
      make_unique<IntegerLiteral>(50)));
  predicates.push_back(make_unique<InequalityPredicate>(
      make_unique<Attribute>("temp"),
      InequalityPredicate::LogicalOperation::GREATER,
      make_unique<IntegerLiteral>(40)));
  auto expected_predicate = make_unique<OrPredicate>(std::move(predicates));
  INFO("Expected: " + expected_predicate->to_string());
  INFO("Got: " + predicate->to_string());
  REQUIRE(predicate->equals(expected_predicate.get()));
}

TEST_CASE("NOT (P1 OR P2) = NOT P1 AND NOT P2", "[Predicate]") {
  auto query = create_query("t2[not (not temp != 50 AND temp > 40)]");
  std::unique_ptr<Predicate> predicate = parse_predicate(query);
  std::vector<std::unique_ptr<Predicate>> predicates;
  predicates.push_back(make_unique<InequalityPredicate>(
      make_unique<Attribute>("temp"),
      InequalityPredicate::LogicalOperation::NOT_EQUALS,
      make_unique<IntegerLiteral>(50)));
  predicates.push_back(make_unique<InequalityPredicate>(
      make_unique<Attribute>("temp"),
      InequalityPredicate::LogicalOperation::LESS_EQUALS,
      make_unique<IntegerLiteral>(40)));
  auto expected_predicate = make_unique<OrPredicate>(std::move(predicates));
  INFO("Expected: " + expected_predicate->to_string());
  INFO("Got: " + predicate->to_string());
  REQUIRE(predicate->equals(expected_predicate.get()));
}

}  // namespace COREQueryParsingTestsPredicate
