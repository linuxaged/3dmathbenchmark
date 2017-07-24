cmake_minimum_required( VERSION 3.8.0 )

project ( 3dmathbenchmark )

add_subdirectory( ./ksmath ksmath )
add_subdirectory( ./lxdmath lxdmath )
add_subdirectory( ./ovrmath ovrmath )

add_executable( 3dmathbenchmark main.cpp )

target_link_libraries( 3dmathbenchmark PRIVATE ksmath lxdmath ovrmath )
