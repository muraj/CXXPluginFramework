#  This file is part of CXXPluginFramework.
#
#  CXXPluginFramework is free software: you can redistribute it and/or modify
#  it under the terms of the GNU Lesser General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  CXXPluginFramework is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU Lesser General Public License for more details.
#
#  You should have received a copy of the GNU Lesser General Public License
#  along with CXXPluginFramework.  If not, see <http://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 2.8.7)

project(pluginTest)

include(GenerateExportHeader)
add_compiler_export_flags(COMPILE_VISIBILITY_FLAGS)
include_directories(${PROJECT_BINARY_DIR})

set(pluginTest_SRCS
  main.cpp)

add_executable(pluginTest ${pluginTest_SRCS})
target_link_libraries(pluginTest ${CMAKE_DL_LIBS})

set(dogPlugin_SRCS
  dog.cpp)
add_library(dog MODULE ${dogPlugin_SRCS})
set_target_properties(dog PROPERTIES PREFIX "")
set_target_properties(dog PROPERTIES COMPILE_FLAGS ${COMPILE_VISIBILITY_FLAGS})

set(catPlugin_SRCS
  cat.cpp)
add_library(cat MODULE ${catPlugin_SRCS})
set_target_properties(cat PROPERTIES PREFIX "")
set_target_properties(cat PROPERTIES COMPILE_FLAGS ${COMPILE_VISIBILITY_FLAGS})
