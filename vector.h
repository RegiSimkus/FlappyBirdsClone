#pragma once

#ifndef _VECTOR_H
#define _VECTOR_H

#include <cmath>

typedef float vec_t;

class Vector
{
public:
	vec_t x, y, z;

	Vector()
	{
		x = y = z = 0;
	}

	Vector(vec_t X, vec_t Y = 0.f, vec_t Z = 0.f)
	{
		x = X;
		y = Y;
		z = Z;
	}
};

class Vector2
{
public:
	vec_t x, y;

	Vector2()
	{
		x = y = 0.f;
	}

	Vector2(vec_t X, vec_t Y = 0.f)
	{
		x = X;
		y = Y;
	}

	float Distance(const Vector2& vec)
	{
		return sqrt(
			(x - vec.x) * (x - vec.x) +
			(y - vec.y) * (y - vec.y)
		);
	}

	float DistanceSqr(const Vector2& vec)
	{
		return
			(x - vec.x) * (x - vec.x) +
			(y - vec.y) * (y - vec.y);
	}

	bool operator==(const Vector2& vec)
	{
		return x == vec.x && y == vec.y;
	}

	bool operator==(const Vector& vec)
	{
		return vec.z == 0 && x == vec.x && y == vec.y;
	}
};

#endif // _VECTOR_H