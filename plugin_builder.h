//  Copyright (c) 2014 Cory Perry
//  This file is part of CXXPluginFramework.
//
//  CXXPluginFramework is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  CXXPluginFramework is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with CXXPluginFramework.  If not, see <http://www.gnu.org/licenses/>.

#ifndef __PLUGINBUILDER_H__
#define __PLUGINBUILDER_H__

#include <string>
#include <map>
#include <iostream>

namespace {   // Force internal linkage
  template<typename Base, typename Derived, typename Key = std::string>
  struct reg_placeholder {
    static bool reg;
  };
  template<typename Base, typename Derived, typename Key>
  bool reg_placeholder<Base, Derived, Key>::reg = false;
}


template<typename Base, typename Derived>
struct PluginFactory {
  static Base* build() { return new Derived; }
};

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

#define INIT_PLUGIN_BUILDER \
  template<typename Base, typename Key> \
  typename PluginBuilder<Base, Key>::FactoryMap PluginBuilder<Base, Key>::_map = PluginBuilder<Base, Key>::FactoryMap();

#define REGISTER_PLUGIN(Base, Derived) \
  namespace {                          \
    template<> bool reg_placeholder<Base, Derived>::reg = PluginBuilder<Base>::load<Derived>(#Derived); \
  }

#endif // __PLUGINBUILDER_H__
