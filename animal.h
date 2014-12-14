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
