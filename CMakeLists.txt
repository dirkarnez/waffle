cmake_minimum_required (VERSION 3.17.2)
set(CMAKE_CXX_STANDARD 11)
project(waffle)

set(Boost_NO_SYSTEM_PATHS TRUE)
set(Boost_USE_STATIC_LIBS TRUE)
set(BOOST_ROOT "C:/Code Projects/Cpp Libraries/boost_1_74_0")

find_package(Boost REQUIRED COMPONENTS date_time filesystem iostreams)

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  add_executable(${PROJECT_NAME} main.cpp)
  target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
endif()