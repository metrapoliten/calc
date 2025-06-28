#include "view.hh"

#include <ui.h>

#include <cstdlib>

View::View() : _controller{Controller()}, _ui{AppWindow::create()}
{
  _ui->global<Logic>().on_button_pressed([&](String const input) {
    if (input.empty()) {
      std::_Exit(1);
    }
    auto const* const ch = input.begin();
    setValue(_controller.processInput(*ch, getValue()).data());
  });
}

void View::run() { _ui->run(); }

void View::setValue(View::String const val) { _ui->set_val(val); }

View::String View::getValue() { return _ui->get_val(); };