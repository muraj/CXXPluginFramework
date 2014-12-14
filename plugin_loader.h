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

#ifndef __PLUGINLOADER_H__
#define __PLUGINLOADER_H__

#if defined(_WIN32) || defined(__CYGWIN32__)
  #include <windows.h>
  typedef HMODULE PluginHandle;
  #define PLUGIN_EXT            ".dll"
  #define PLUGIN_LOAD(fn)       LoadLibrary(fn)
  #define PLUGIN_LOOKUP(hdl, n) GetProcAddress(hdl, n)
  #define PLUGIN_INIT()         
  #define PLUGIN_ERR(hdl)
  #define PLUGIN_CLOSE(hdl)     FreeLibrary(hdl)
#else // LINUX || OSX
  #include <dlfcn.h>
  typedef void* PluginHandle;
  #if defined(__APPLE__)
    #define PLUGIN_EXT ".dylib"
  #else
    #define PLUGIN_EXT ".so"
  #endif  // __APPLE__
  #define PLUGIN_LOAD(fn)       dlopen(fn, RTLD_NOW|RTLD_GLOBAL)
  #define PLUGIN_LOOKUP(hdl, n) dlsym(hdl, n)
  #define PLUGIN_INIT()         PLUGIN_LOAD(0)
  #define PLUGIN_ERR(hdl)       dlerror()
  #define PLUGIN_CLOSE(hdl)     dlclose(hdl)
#endif

#endif  // __PLUGINLOADER_H__
