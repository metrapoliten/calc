#include "controller.hh"

#include <cassert>
#include <cctype>
#include <string>
#include <string_view>

#include "model.hh"

Controller::Controller() : _model{Model()} {}

std::string Controller::processInput(char const input,
                                     std::string_view const val)
{
  if (std::isdigit(static_cast<unsigned char>(input)) != 0) {
    _model.processDigit();
    return std::string{val} + input;
  }
  // _model.processSpecialBtn(char const input);
  return {};
}
