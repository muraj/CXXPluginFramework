
cmake_minimum_required(VERSION 2.8.7)

project(pluginTest)

include(GenerateExportHeader)
add_compiler_export_flags(COMPILE_VISIBILITY_FLAGS)
include_directories(${PROJECT_BINARY_DIR})

set(pluginTest_SRCS
  main.cpp)

add_executable(pluginTest ${pluginTest_SRCS})
target_link_libraries(pluginTest -ldl)

set(dogPlugin_SRCS
  dog.cpp)
add_library(dog MODULE ${dogPlugin_SRCS})
generate_export_header(dog)
#set_target_properties(dog PROPERTIES COMPILE_FLAGS ${COMPILE_VISIBILITY_FLAGS})

set(catPlugin_SRCS
  cat.cpp)
add_library(cat MODULE ${catPlugin_SRCS})
generate_export_header(cat)
set_target_properties(cat PROPERTIES COMPILE_FLAGS ${COMPILE_VISIBILITY_FLAGS})
