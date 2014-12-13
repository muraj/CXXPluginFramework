#include "cat.h"
#include "plugin_builder.h"
#include <iostream>

Cat::Cat() {}
Cat::~Cat() {}

void Cat::speak() {
  std::cout << "meow!" << std::endl;
}

namespace {
  template<> bool reg_placeholder<Animal, Cat>::reg = PluginBuilder<Animal>::load<Cat>("Cat");
}
