#ifndef MIRAGE_VECTOR3_HPP__
#define MIRAGE_VECTOR3_HPP__

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
};

#endif // MIRAGE_VECTOR3_HPP__
