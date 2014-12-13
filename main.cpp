#include <iostream>
#include <assert.h>

#include "plugin_loader.h"
#include "plugin_builder.h"

#include "animal.h"

INIT_PLUGIN_BUILDER

int main() {

  PLUGIN_INIT();

  PluginHandle dogso = PLUGIN_LOAD("./dog.so");
  if(!dogso) std::cout << "Failed to load dog.so: " << PLUGIN_ERR() << std::endl;

  PluginHandle catso = PLUGIN_LOAD("./cat.so");
  if(!catso) std::cout << "Failed to load cat.so: " << PLUGIN_ERR() << std::endl;

  std::cout << "Registered kinds:" << std::endl;
  std::vector<std::string> kinds = Animal::kinds();
  for(size_t i=0;i<kinds.size();i++)
    std::cout << '\t' << kinds[i] << std::endl;

  Animal* a = Animal::create("Dog");
  if(a) a->speak();
  else std::cout << "Dog missing!" << std::endl;
  delete a;

  Animal* b = Animal::create("Cat");
  if(b) b->speak();
  else std::cout << "Cat missing!" << std::endl;
  delete b;

  if(dogso) PLUGIN_CLOSE(dogso);
  if(catso) PLUGIN_CLOSE(catso);

  return 0;
}
