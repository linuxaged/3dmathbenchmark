cmake_minimum_required( VERSION 3.8.0 )

project ( lxdmath )

add_library( lxdmath STATIC 
	Matrix.cpp
	SIMD_NEON.cpp
	SIMD_SSE.cpp
)
