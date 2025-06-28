#pragma once

#include <ui.h>

#include "controller.hh"

class View {
 public:
  using String = slint::SharedString;
  explicit View();
  void run();

 private:
  Controller _controller;
  slint::ComponentHandle<AppWindow> _ui;
  void setValue(String val);
  String getValue();
};
