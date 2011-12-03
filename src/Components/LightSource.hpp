#ifndef MIRAGE_LIGHTSOURCE_HPP__
#define MIRAGE_LIGHTSOURCE_HPP__

#include <Gl/freeglut.h>

#include "GameComponent.hpp"
#include "../Vector3.hpp"
#include "../Utils.hpp"

class LightSource :	public GameComponent
{
public:
	LightSource(GLenum lightNum);
	~LightSource();

	void update() {}
	void draw();

	void setDiffuse(const Vector3& newDiffuse) { _diffuse = Vector3(newDiffuse); }
	const Vector3& diffuse() const { return _diffuse; }

	void setAmbient(const Vector3& newAmbient) { _ambient = Vector3(newAmbient); }
	const Vector3& ambient() const { return _ambient; }

	void setPosition(const Vector3& newPosition) { _position = Vector3(newPosition);  }
	const Vector3& position() const { return _position; }

private:
	GLenum _lightNum;

	Vector3 _position;
	Vector3 _diffuse;
	Vector3 _ambient;

	DISALLOW_COPY_AND_ASSIGN(LightSource);
};

#endif // MIRAGE_LIGHTSOURCE_HPP__