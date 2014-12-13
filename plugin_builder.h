#ifndef __PLUGINBUILDER_H__
#define __PLUGINBUILDER_H__

#include <string>
#include <map>
#include <iostream>

  template<typename Base, typename Derived>
  struct PluginFactory {
    static Base* build() { return new Derived; }
  };

namespace {   // Force internal linkage
  template<typename Base, typename Derived, typename Key = std::string>
  struct reg_placeholder {
    static bool reg;
  };
  template<typename Base, typename Derived, typename Key>
  bool reg_placeholder<Base, Derived, Key>::reg = false;
}

template<typename Base, typename Key = std::string>
class PluginBuilder {
public:
  typedef Base* ( *FactoryFunc ) ();
  typedef std::map<Key, FactoryFunc> FactoryMap;
  static FactoryMap _map;
  //static FactoryMap factoryMap;

  static FactoryMap& factoryMap() {
    //static FactoryMap _map;
    return _map;
  }

  static Base* build(const Key& key) {
    typename FactoryMap::const_iterator it = factoryMap().find(key);
    return (it != factoryMap().end() ? (it->second)() : NULL);
  }

  template<typename Derived>
  static bool load(const Key& key, FactoryFunc func = 0) {
    if(!func) func = PluginFactory<Base, Derived>::build;
    std::cout << "Loading " << key <<' '<<&(factoryMap())<<std::endl;
    // Insert it, but don't overwrite
    // TODO: Warn of conflicts
    return !(factoryMap().insert(typename FactoryMap::value_type(key, func)).second);
  }
};

#endif // __PLUGINBUILDER_H__
