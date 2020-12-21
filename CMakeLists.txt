cmake_minimum_required (VERSION 3.17.2)
set(CMAKE_CXX_STANDARD 11)
project(boost-playground)

set(Boost_NO_SYSTEM_PATHS TRUE)
set(Boost_USE_STATIC_LIBS TRUE)
set(BOOST_ROOT "D:/Cpp Libraries/boost_1_73_0")

find_package(Boost REQUIRED COMPONENTS date_time filesystem iostreams)

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  add_executable(boost-playground main.cpp)
  target_link_libraries(boost-playground ${Boost_LIBRARIES})
endif()