#include <iostream>
#include <assert.h>
#include <dlfcn.h>

#include "plugin_builder.h"
#include "animal.h"

int main() {

  dlopen(0, RTLD_NOW|RTLD_GLOBAL);
  void* dogso = dlopen("./libdog.so", RTLD_NOW|RTLD_GLOBAL);
  if(!dogso) std::cout << "Failed to load dog.so: " << dlerror() << std::endl;
  void* catso = dlopen("./libcat.so", RTLD_NOW|RTLD_GLOBAL);
  if(!catso) std::cout << "Failed to load cat.so: " << dlerror() << std::endl;

  for(PluginBuilder<Animal>::FactoryMap::const_iterator it = PluginBuilder<Animal>::factoryMap().begin(); it != PluginBuilder<Animal>::factoryMap().end(); ++it)
    std::cout << it->first << std::endl;

  Animal* a = PluginBuilder<Animal>::build("Dog");
  if(a) a->speak();
  else std::cout << "Dog missing!" << std::endl;
  delete a;

  Animal* b = PluginBuilder<Animal>::build("Cat");
  if(b) b->speak();
  else std::cout << "Cat missing!" << std::endl;
  delete b;

  if(dogso) dlclose(dogso);
  if(catso) dlclose(catso);

  return 0;
}