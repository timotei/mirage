#ifndef MIRAGE_VECTOR3_HPP__
#define MIRAGE_VECTOR3_HPP__

#include <boost/shared_array.hpp>
#if defined _WIN32 || defined _WIN64
#include "GL/glew.h"
#include "GL/freeglut.h"
#else
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#endif

struct Vector3{
	float x,y,z;

	Vector3() :
		x(0),
		y(0),
		z(0)
	{
	}

	Vector3(float X, float Y, float Z) :
		x(X),
		y(Y),
		z(Z)
	{
	}

	Vector3(const Vector3& other) :
		x(other.x),
		y(other.y),
		z(other.z)
	{
	}

	boost::shared_array<GLfloat> toArray()
	{
		boost::shared_array<GLfloat> arr(new GLfloat[3]);
		arr[0] = x;
		arr[1] = y;
		arr[2] = z;

		return arr;
	}
};

#endif // MIRAGE_VECTOR3_HPP__
