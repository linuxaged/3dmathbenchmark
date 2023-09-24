cmake_minimum_required( VERSION 3.8.0 )

set(CMAKE_CXX_STANDARD 20)

project ( 3dmathbenchmark )

add_subdirectory( ./ksmath ksmath )
add_subdirectory( ./mj2math mj2math )
add_subdirectory( ./ovrmath ovrmath )

add_executable( 3dmathbenchmark nanobench.cpp doctest.cpp main.cpp )

target_link_libraries( 3dmathbenchmark PRIVATE ksmath mj2math ovrmath shlwapi.lib )
