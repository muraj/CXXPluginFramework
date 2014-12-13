#include <iostream>
#include <assert.h>

#include "plugin_loader.h"
#include "plugin_builder.h"

#include "animal.h"

template<typename Base, typename Key>
typename PluginBuilder<Base, Key>::FactoryMap PluginBuilder<Base, Key>::_map = PluginBuilder<Base, Key>::FactoryMap();

//template<>
//typename PluginBuilder<Animal>::FactoryMap PluginBuilder<Animal>::_map;

int main() {

  PLUGIN_INIT();
  PluginHandle dogso = PLUGIN_LOAD("./libdog.so");
  if(!dogso) std::cout << "Failed to load dog.so: " << PLUGIN_ERR() << std::endl;
  PluginHandle catso = PLUGIN_LOAD("./libcat.so");
  if(!catso) std::cout << "Failed to load cat.so: " << PLUGIN_ERR() << std::endl;

  std::cout << "Registered kinds:" << std::endl;
  for(PluginBuilder<Animal>::FactoryMap::const_iterator it = PluginBuilder<Animal>::factoryMap().begin(); it != PluginBuilder<Animal>::factoryMap().end(); ++it)
    std::cout << '\t' << it->first << std::endl;

  Animal* a = PluginBuilder<Animal>::build("Dog");
  if(a) a->speak();
  else std::cout << "Dog missing!" << std::endl;
  delete a;

  Animal* b = PluginBuilder<Animal>::build("Cat");
  if(b) b->speak();
  else std::cout << "Cat missing!" << std::endl;
  delete b;

  if(dogso) PLUGIN_CLOSE(dogso);
  if(catso) PLUGIN_CLOSE(catso);

  return 0;
}
