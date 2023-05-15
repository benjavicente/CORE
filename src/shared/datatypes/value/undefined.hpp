#pragma once

#include <string>

#include "shared/datatypes/value/value.hpp"

namespace CORETypes {
struct Undefined final : public Value {
  Undefined() noexcept {}

  ~Undefined() noexcept override {}

  std::string to_string() const noexcept override { return "Undefined"; }

  bool operator==(const Undefined& other) const noexcept { return true; }

  bool check_if_equals(Value* val) const noexcept override {
    if (Undefined* long_literal = dynamic_cast<Undefined*>(val)) {
      return true;
    } else
      return false;
  }

  std::unique_ptr<Value> clone() const noexcept override {
    return std::make_unique<Undefined>();
  }

  template <class Archive>
  void serialize(Archive& archive) {}
};
}  // namespace CORETypes
