#include "view.hh"

View::View() : _controller{Controller()}, _ui{AppWindow::create()}
{
  _ui->global<Logic>().on_button_pressed([&](String const input) {
      if (input.empty()) std::_Exit(1);
      const auto *const ch = input.begin();
      setValue(_controller.processInput(*ch, getValue()).data());
    });
}

void View::run()
{
  _ui->run();
}
