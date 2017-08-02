cmake_minimum_required( VERSION 3.8.0 )

project ( mj2math )

add_library( mj2math STATIC 
	Matrix.cpp
	SIMD_NEON.cpp
	SIMD_SSE.cpp
)
