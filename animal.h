#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <vector>
#include <string>
#include "plugin_builder.h"

class Animal {
public:
  Animal() {}
  virtual ~Animal() {}
  virtual void speak() = 0;
  static std::vector<std::string> kinds() {
    std::vector<std::string> ret;
    for(PluginBuilder<Animal>::FactoryMap::const_iterator it = PluginBuilder<Animal>::factoryMap().begin(); it != PluginBuilder<Animal>::factoryMap().end(); ++it)
      ret.push_back(it->first);
    return ret;
  }
  static Animal* create(const std::string& kind) {
    return PluginBuilder<Animal>::build(kind);
  }
};

#endif // __ANIMAL_H__
