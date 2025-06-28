#include "view.hh"

#include <ui.h>

View::View(ButtonHandler button_handler)
    : _ui{AppWindow::create()}
    , _button_handler{button_handler}
{
  if (_button_handler) {
    _ui->global<Logic>().on_button_pressed(
        [this](slint::SharedString input) { _button_handler(input); });
  }
}

void View::run() { _ui->run(); }

void View::setValue(String const val) { _ui->set_val(val); }

View::String View::getValue() { return _ui->get_val(); }
