#include "dog.h"
#include "plugin_builder.h"
#include <iostream>

Dog::Dog() {}
Dog::~Dog() {}

void Dog::speak() {
  std::cout << "bark!" << std::endl;
}

namespace {
  template<> DOG_NO_EXPORT bool reg_placeholder<Animal, Dog>::reg = PluginBuilder<Animal>::load<Dog>("Dog");
}
