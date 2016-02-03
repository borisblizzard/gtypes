#define __HL_UT_LIB_NAME gtypes
#ifdef __APPLE__
#import "hunittest.h"
#else
#include "hunittest.h"
#endif

#include "Vector3.h"

#define E_TOLRANCE 0.0001f

HL_UT_TEST_CLASS(Vector3)
{
	static float habs(float value)
	{
		return value >= 0.0f ? value : -value;
	}

	static bool heqf(float a, float b, float tolerance = E_TOLRANCE)
	{
		return (habs(a - b) < tolerance);
	}

	static bool vec3eqf(const gvec3& v1, const gvec3& v2)
	{
		return (heqf(v1.x, v2.x) && heqf(v1.y, v2.y) && heqf(v1.z, v2.z));
	}

	HL_UT_TEST_FUNCTION(assignment)
	{
		gvec3 v(1.0f, 2.0f, 3.0f);
		HL_UT_ASSERT(v.x == 1.0f && v.y == 2.0f && v.z == 3.0f, "constructor assignment");
		v.set(2.0f, 3.0f, 4.0f);
		HL_UT_ASSERT(v.x == 2.0f && v.y == 3.0f && v.z == 4.0f, "set()");
	}

	HL_UT_TEST_FUNCTION(addition)
	{
		gvec3 v1(1.0f, 2.0f, 3.0f), v2(2.0f, 3.0f, 4.0f);
		gvec3 v3 = v1 + v2;
		HL_UT_ASSERT(v3.x == 3.0f && v3.y == 5.0f && v3.z == 7.0f, "");
	}

	HL_UT_TEST_FUNCTION(zeroLength)
	{
		gvec3 v(0.0f, 0.0f, 0.0f);
		HL_UT_ASSERT(v.isNull(), "");
	}

	HL_UT_TEST_FUNCTION(length)
	{
		gvec3 v(2.0f, 0.0f, 0.0f);
		HL_UT_ASSERT(v.length() == 2.0f, "");
	}

	HL_UT_TEST_FUNCTION(squaredLength)
	{
		gvec3 v(2.0f, 2.0f, 0.0f);
		HL_UT_ASSERT(v.squaredLength() == 8.0f, "");
	}

	HL_UT_TEST_FUNCTION(normalize)
	{
		gvec3 v1(2.0f, 0.0f, 0.0f);
		gvec3 v2(1.0f, 0.0f, 0.0f);
		v1.normalize();
		HL_UT_ASSERT(v1 == v2, "");
	}

	HL_UT_TEST_FUNCTION(normalized)
	{
		gvec3 v1(1.0f, -1.0f, 0.0f);
		gvec3 v2(0.707107f, -0.707107f, 0.0f);
		HL_UT_ASSERT(vec3eqf(v1.normalized(), v2), "");
	}

	HL_UT_TEST_FUNCTION(dot)
	{
		gvec3 v1(1.0f, 0.0f, 0.0f);
		gvec3 v2(0.5f, 0.5f, 0.5f);
		float dot = v2.dot(v1);
		HL_UT_ASSERT(heqf(dot, v1.x * v2.x + v1.y * v2.y + v1.z * v2.z), "");
	}

	HL_UT_TEST_FUNCTION(cross)
	{
		gvec3 v1(1.0f, 0.0f, 0.0f);
		gvec3 v2(0.0f, 0.0f, 1.0f);
		gvec3 v3(0.0f, 1.0f, 0.0f);
		HL_UT_ASSERT(vec3eqf(v1.cross(v2), v3), "");
	}

	HL_UT_TEST_FUNCTION(negation)
	{
		gvec3 v1(3.0f, 4.0f, 5.0f);
		gvec3 v2(-3.0f, -4.0f, -5.0f);
		v1 = -v1;
		HL_UT_ASSERT(vec3eqf(v1, v2), "");
	}

	HL_UT_TEST_FUNCTION(substraction)
	{
		gvec3 v1(3.0f, 4.0f, 5.0f);
		gvec3 v2(1.0f, 2.0f, 3.0f);
		gvec3 v = v1 - v2;
		HL_UT_ASSERT(v.x == 2.0f && v.y == 2.0f && v.z == 2.0f, "");
	}

	HL_UT_TEST_FUNCTION(multiplicationVector)
	{
		gvec3 v1(1.0f, 2.0f, 3.0f);
		gvec3 v2(2.0f, 4.0f, 5.0f);
		gvec3 v = v1 * v2;
		HL_UT_ASSERT(v.x == 2 && v.y == 8 && v.z == 15, "");
	}

	HL_UT_TEST_FUNCTION(divisionVector)
	{
		gvec3 v1(4.0f, 6.0f, 8.0f);
		gvec3 v2(2.0f, 3.0f, 4.0f);
		gvec3 v = v1 / v2;
		HL_UT_ASSERT(v.x == 2 && v.y == 2 && v.z == 2, "");
	}

	HL_UT_TEST_FUNCTION(multiplication)
	{
		gvec3 v(1, 2, 3);
		v = v * 2;
		HL_UT_ASSERT(v.x == 2 && v.y == 4 && v.z == 6, "");
	}

	HL_UT_TEST_FUNCTION(division)
	{
		gvec3 v(4, 8, 12);
		v = v / 2;
		HL_UT_ASSERT(v.x == 2 && v.y == 4 && v.z == 6, "");
	}

	HL_UT_TEST_FUNCTION(additionAssign)
	{
		gvec3 v1(1, 2, 3), v2(2, 3, 4);
		v1 += v2;
		HL_UT_ASSERT(v1.x == 3 && v1.y == 5 && v1.z == 7, "");
	}

	HL_UT_TEST_FUNCTION(substractionAssign)
	{
		gvec3 v1(3, 4, 5);
		gvec3 v2(1, 2, 3);
		v1 -= v2;
		HL_UT_ASSERT(v1.x == 2 && v1.y == 2 && v1.z == 2, "");
	}

	HL_UT_TEST_FUNCTION(multiplicationVectorAssign)
	{
		gvec3 v1(1, 2, 3);
		gvec3 v2(2, 4, 5);
		v1 *= v2;
		HL_UT_ASSERT(v1.x == 2 && v1.y == 8 && v1.z == 15, "");
	}

	HL_UT_TEST_FUNCTION(divisionVectorAssign)
	{
		gvec3 v1(4, 6, 8);
		gvec3 v2(2, 3, 4);
		v1 /= v2;
		HL_UT_ASSERT(v1.x == 2 && v1.y == 2 && v1.z == 2, "");
	}

	HL_UT_TEST_FUNCTION(multiplicationAssign)
	{
		gvec3 v(1, 2, 3);
		v *= 2;
		HL_UT_ASSERT(v.x == 2 && v.y == 4 && v.z == 6, "");
	}

	HL_UT_TEST_FUNCTION(divisionAssign)
	{
		gvec3 v(4, 8, 12);
		v /= 2;
		HL_UT_ASSERT(v.x == 2 && v.y == 4 && v.z == 6, "");
	}

	HL_UT_TEST_FUNCTION(equal)
	{
		gvec3 v1(4, 6, 8);
		gvec3 v2(4, 6, 8);
		HL_UT_ASSERT(v1 == v2, "");
	}

	HL_UT_TEST_FUNCTION(notEqual)
	{
		gvec3 v1(4, 6, 8);
		gvec3 v2(2, 3, 4);
		HL_UT_ASSERT(v1 != v2, "");
	}

}