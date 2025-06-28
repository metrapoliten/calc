#pragma once

#include <ui.h>

class View {
 public:
  using String        = slint::SharedString;
  using ButtonHandler = std::function<void(String)>;
  using UiHandler     = slint::ComponentHandle<AppWindow>;

  explicit View(ButtonHandler);
  void run();
  String getValue();
  void setValue(String val);

 private:
  UiHandler _ui;
  ButtonHandler _button_handler;
};
