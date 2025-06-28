#pragma once
#include <string_view>

#include "model.hh"

class Controller {
 public:
  explicit Controller();
  std::string processInput(char input, std::string_view val);

 private:
  Model _model;
};
