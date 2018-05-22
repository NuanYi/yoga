#
# Copyright (c) 2014-present, Facebook, Inc.
#
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.
#
project(yoga)
cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_VERBOSE_MAKEFILE on)

set(CMAKE_CXX_STANDARD 11)

file(GLOB yogacore_SRC 
    yoga/Utils.cpp
    yoga/Utils.h
    yoga/YGConfig.cpp
    yoga/YGConfig.h
    yoga/YGEnums.cpp
    yoga/YGEnums.h
    yoga/YGFloatOptional.cpp
    yoga/YGFloatOptional.h
    yoga/YGLayout.cpp
    yoga/YGLayout.h
    yoga/YGMacros.h
    yoga/YGNode.cpp
    yoga/YGNode.h
    yoga/YGNodePrint.cpp
    yoga/YGNodePrint.h
    yoga/YGStyle.cpp
    yoga/YGStyle.h
    yoga/Yoga-internal.h
    yoga/Yoga.cpp
    yoga/Yoga.h
)
add_library(yogacore STATIC ${yogacore_SRC})

if (${CMAKE_SYSTEM_NAME} EQUAL "Android")
target_link_libraries(yogacore android log)
endif()

# examples
include_directories(yoga)
add_executable(HelloWorld standexample/HelloWorld.cpp)
target_link_libraries(HelloWorld yogacore)
