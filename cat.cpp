#include "cat.h"
#include "plugin_builder.h"
#include <iostream>

Cat::Cat() {}
Cat::~Cat() {}

void Cat::speak() {
  std::cout << "meow!" << std::endl;
}

REGISTER_PLUGIN(Animal, Cat)
