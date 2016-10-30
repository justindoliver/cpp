cmake_minimum_required (VERSION 2.6)
project (MultiIndex_Test)
add_executable(MultiIndex_Test test.cpp)

include_directories (/home/justin/Projects/cpp/boost_tutorial/multi-index)
include_directories (/usr/include)
include_directories (/home/justin/Projects/googletest/googletest/include/)

link_directories (/usr/local/lib)
link_directories (/usr/lib)

target_link_libraries( MultiIndex_Test gtest_main )
target_link_libraries( MultiIndex_Test gtest )
target_link_libraries( MultiIndex_Test pthread)

