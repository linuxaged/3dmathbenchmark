#include "ksmath\ksmath.hpp"
#include "lxdmath\Matrix.hpp"
#include "ovrmath\OVR_Math.h"

int main(int argc, char const *argv[])
{
	/* code */
	ksMatrix4x4f ksMat;
	ksMatrix4x4f_CreateIdentity(&ksMat);

	m3d::math::Matrix4x4 lxdMat;

	OVR::Matrix4f ovrMat;

	return 0;
}