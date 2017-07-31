#include "ksmath/ksmath.hpp"
#include "lxdmath/Matrix.hpp"
#include "ovrmath/OVR_Math.h"
#include "benchmark/benchmark.h"

static void VectorCreation_ks(benchmark::State& state )
{
	while (state.KeepRunning())
	{
		ksVector3f vec;
	}
}
BENCHMARK(VectorCreation_ks);

static void MatrixCreation_ks(benchmark::State& state)
{
	while ( state.KeepRunning() )
	{
		ksMatrix4x4f mat;
	}
}
BENCHMARK(MatrixCreation_ks);

static void MatrixMultiply_ks(benchmark::State& state)
{
	while ( state.KeepRunning() )
	{
		ksMatrix4x4f mat0{
			1.0f, 0, 0, 0,
			0, 1.0f, 0, 0,
			0, 0, 1.0f, 0,
			0, 0, 0, 1.0f
		};
		ksMatrix4x4f mat1{
			0.987f, 0, 0.5f, 0,
			0.32f, 0, 0.5f, 0,
			0.15f, 0.1f, 0, 1.0f,
			0, 1.0f, 0.78f, 0.4f
		};
		ksMatrix4x4f res;
		ksMatrix4x4f_Multiply(&res, &mat0, &mat1 );
	}
}
BENCHMARK(MatrixMultiply_ks);

BENCHMARK_MAIN();