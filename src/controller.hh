#pragma once
#include <string_view>

#include "model.hh"
#include "view.hh"

class Controller {
 public:
  Controller();
  std::string handleBtn(char input, std::string_view val);
  void run();

 private:
  Model _model;
  View _view;
};
