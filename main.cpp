#include "ksmath/ksmath.hpp"
#include "mj2math/Matrix.hpp"
#include "ovrmath/OVR_Math.h"
#include "benchmark/benchmark.h"
#include <random>
//
// todo: compile time
// gen random float, range (.0f , 1.0f)
//
std::vector<float> GenRandomFloatArray()
{
	std::default_random_engine dre;
	std::uniform_real_distribution<float> dr(0.0f, 1.0f);

	std::vector<float> matrix;
	for (int i = 0; i < 16; i++)
	{
		matrix.push_back(dr(dre));
	}

	return matrix;
}

//
// ksMath
//
static void VectorCreation_ks(benchmark::State& state )
{
	std::vector<float> floats = GenRandomFloatArray();
	while (state.KeepRunning())
	{
		ksVector3f vec{floats[0], floats[1], floats[2]};
	}
}
BENCHMARK(VectorCreation_ks);

static void MatrixCreation_ks(benchmark::State& state)
{
	std::vector<float> left = GenRandomFloatArray();
	while ( state.KeepRunning() )
	{
		ksMatrix4x4f mat{
			left[0], left[1], left[2], left[3],
			left[4], left[5], left[6], left[7],
			left[8], left[9], left[10], left[11],
			left[12], left[13], left[14], left[15]
		};
	}
}
BENCHMARK(MatrixCreation_ks);

static void MatrixMultiply_ks(benchmark::State& state)
{
	std::vector<float> left = GenRandomFloatArray();
	std::vector<float> right = GenRandomFloatArray();
	while ( state.KeepRunning() )
	{
		ksMatrix4x4f mat0{
			left[0], left[1], left[2], left[3],
			left[4], left[5], left[6], left[7],
			left[8], left[9], left[10], left[11],
			left[12], left[13], left[14], left[15]
		};
		ksMatrix4x4f mat1{
			right[0], right[1], right[2], right[3],
			right[4], right[5], right[6], right[7],
			right[8], right[9], right[10], right[11],
			right[12], right[13], right[14], right[15]
		};
		ksMatrix4x4f res;
		ksMatrix4x4f_Multiply(&res, &mat0, &mat1 );
	}
}
BENCHMARK(MatrixMultiply_ks);

//
// lxdMath
//
static void VectorCreation_mj2(benchmark::State& state)
{
	std::vector<float> floats = GenRandomFloatArray();
	while (state.KeepRunning())
	{
		mj2::Vector3 vec{ floats[0], floats[1], floats[2] };
	}
	
}
BENCHMARK(VectorCreation_mj2);

static void MatrixCreation_mj2(benchmark::State& state)
{
	std::vector<float> left = GenRandomFloatArray();
	while (state.KeepRunning())
	{
		mj2::Matrix4x4 mat {
				left.data()
			};
	}
	
}
BENCHMARK(MatrixCreation_mj2);

static void MatrixMultiply_mj2(benchmark::State& state)
{
	std::vector<float> left = GenRandomFloatArray();
	std::vector<float> right = GenRandomFloatArray();
	while (state.KeepRunning())
	{
		mj2::Matrix4x4 mat0 { left.data() };
		mj2::Matrix4x4 mat1 { right.data() };
		mj2::Matrix4x4 res;
		res = mat0 * mat1;
	}
}
BENCHMARK(MatrixMultiply_mj2);

//
// OVR math
//
static void VectorCreation_ovr(benchmark::State& state)
{
	std::vector<float> floats = GenRandomFloatArray();
	while (state.KeepRunning())
	{
		OVR::Vector3f vec{floats[0], floats[1], floats[2]};
	}
}
BENCHMARK(VectorCreation_ovr);

static void MatrixCreation_ovr(benchmark::State& state)
{
	std::vector<float> left = GenRandomFloatArray();
	while (state.KeepRunning())
	{
		OVR::Matrix4f mat{
			left[0], left[1], left[2], left[3],
			left[4], left[5], left[6], left[7],
			left[8], left[9], left[10], left[11],
			left[12], left[13], left[14], left[15]
		};
	}
}
BENCHMARK(MatrixCreation_ovr);

static void MatrixMultiply_ovr(benchmark::State& state)
{
	std::vector<float> left = GenRandomFloatArray();
	std::vector<float> right = GenRandomFloatArray();
	while (state.KeepRunning())
	{
		OVR::Matrix4f mat0{
			left[0], left[1], left[2], left[3],
			left[4], left[5], left[6], left[7],
			left[8], left[9], left[10], left[11],
			left[12], left[13], left[14], left[15]
		};
		OVR::Matrix4f mat1{
			right[0], right[1], right[2], right[3],
			right[4], right[5], right[6], right[7],
			right[8], right[9], right[10], right[11],
			right[12], right[13], right[14], right[15]
		};
		OVR::Matrix4f res;
		res = mat0 * mat1;
	}
}
BENCHMARK(MatrixMultiply_ovr);

BENCHMARK_MAIN();