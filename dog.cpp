#include "dog.h"
#include "plugin_builder.h"
#include <iostream>

Dog::Dog() {}
Dog::~Dog() {}

void Dog::speak() {
  std::cout << "bark!" << std::endl;
}

REGISTER_PLUGIN(Animal, Dog)
