cmake_minimum_required( VERSION 3.8.0 )

project ( 3dmathbenchmark )

add_subdirectory( ./ksmath ksmath )
add_subdirectory( ./mj2math mj2math )
add_subdirectory( ./ovrmath ovrmath )

add_executable( 3dmathbenchmark main.cpp )

#
# Google benchmark lib
#
find_path( BENCHMARK_INC_DIR benchmark/benchmark.h )
find_library( BENCHMARK_LIB benchmark )
target_include_directories( 3dmathbenchmark PRIVATE ${BENCHMARK_INC_DIR} )


target_link_libraries( 3dmathbenchmark PRIVATE ksmath mj2math ovrmath ${BENCHMARK_LIB} shlwapi.lib )
