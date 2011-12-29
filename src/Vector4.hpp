#ifndef MIRAGE_VECTOR4_HPP__
#define MIRAGE_VECTOR4_HPP__

#include <boost/shared_array.hpp>
#if defined _WIN32 || defined _WIN64
#include "GL/glew.h"
#include "GL/freeglut.h"
#else
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#endif

struct Vector4{
	float x, y, z, w;

	Vector4() :
		x(0),
		y(0),
		z(0),
		w(0)
	{
	}

	Vector4(float X, float Y, float Z, float W) :
		x(X),
		y(Y),
		z(Z),
		w(W)
	{
	}

	explicit Vector4(const Vector3& other) :
		x(other.x),
		y(other.y),
		z(other.z),
		w(0)
	{
	}

	Vector4(const Vector4& other) :
		x(other.x),
		y(other.y),
		z(other.z),
		w(other.w)
	{
	}

	boost::shared_array<GLfloat> toArray()
	{
		boost::shared_array<GLfloat> arr(new GLfloat[4]);
		arr[0] = x;
		arr[1] = y;
		arr[2] = z;
		arr[3] = w;

		return arr;
	}
};

#endif // MIRAGE_VECTOR4_HPP__
