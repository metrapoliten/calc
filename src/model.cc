#include "model.hh"
#include <cstdint>

namespace {
  enum class Operation : std::uint8_t {
    PLUS,
    MINUS,
    MUL,
    DIV
  };
  enum class ActionBtn : char {
    PLUS  = '+',
    MINUS = '-',
    MUL   = '*',
    DIV   = '/',
    EQUAL = '=',
    AC    = 'A',
    DEL   = 'D'
  };
} // namespace

void Model::processDigit() {  }

void Model::processSpecialBtn([[maybe_unused]]char const input)
{
  // switch (input)
}
