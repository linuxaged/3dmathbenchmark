#include "ksmath/ksmath.hpp"
#include "lxdmath/Matrix.hpp"
#include "ovrmath/OVR_Math.h"
#include "benchmark/benchmark.h"

//int main(int argc, char const *argv[])
//{
//	/* code */
//	ksMatrix4x4f ksMat;
//	ksMatrix4x4f_CreateIdentity(&ksMat);
//
//	m3d::math::Matrix4x4 lxdMat;
//
//	OVR::Matrix4f ovrMat;
//
//	return 0;
//}

static void BM_StringCreation(benchmark::State& state) {
	while (state.KeepRunning())
		std::string empty_string;
}
// Register the function as a benchmark
BENCHMARK(BM_StringCreation);

// Define another benchmark
static void BM_StringCopy(benchmark::State& state) {
	std::string x = "hello";
	while (state.KeepRunning())
		std::string copy(x);
}
BENCHMARK(BM_StringCopy);

BENCHMARK_MAIN();