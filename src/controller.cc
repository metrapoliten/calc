#include "controller.hh"

#include <string>
#include <string_view>

#include "model.hh"

Controller::Controller()
    : _model{Model()}
    , _view{View([this](View::String const input) {
      if (input.empty()) {
        std::_Exit(1);
      }
      auto const* const ch = input.begin();
      handleBtn(*ch, _view.getValue());
    })}
{
}

std::string Controller::handleBtn(char const input, std::string_view const val)
{
  auto res = _model.processBtn(input, val);
  _view.setValue(res.data());
  return {};
}

void Controller::run() { _view.run(); }
