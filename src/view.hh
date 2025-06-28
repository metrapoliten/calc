#pragma once
#include <ui.h>

#include "controller.hh"

namespace slint {
  struct SharedString;
}  // namespace slint

class View {
 public:
  using String = slint::SharedString;
  explicit View();
  void run();

 private:
  Controller _controller;
  slint::ComponentHandle<AppWindow> _ui;
  void setValue(String const val)
  {
    _ui->set_val(val);
  };
  String getValue()
  {
    return _ui->get_val();
  };
};
