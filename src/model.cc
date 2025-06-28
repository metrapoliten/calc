#include "model.hh"

#include <cctype>
#include <cstdint>
#include <string>

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

  void processDigit() {};
}  // namespace

std::string Model::processBtn(char const input, std::string_view const val)
{
  if (std::isdigit(static_cast<unsigned char>(input)) != 0) {
    processDigit();
    return std::string{val} + input;
  }
  return {};
}
