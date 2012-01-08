#ifndef MIRAGE_LIGHTSOURCE_HPP__
#define MIRAGE_LIGHTSOURCE_HPP__

#if defined _WIN32 || defined _WIN64
#include "GL/glew.h"
#include "GL/freeglut.h"
#else
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#endif
#include "nvMath.h"
#include <boost/shared_ptr.hpp>

#include "GameComponent.hpp"
#include "../Utils.hpp"

class Camera;
class LightSource;

typedef boost::shared_ptr<LightSource> LightSourcePtr;

class LightSource :	public GameComponent
{
public:
	LightSource( Game* parent );
	~LightSource();

	void update() { GameComponent::update(); }
	void draw( bool shadow = false );
	void sendToShaderProgram( ShaderProgram& program, const Camera& cam );

	nv::vec4f getPosition() { return getModelMatrix() * nv::vec4f( 0, 0, 0, 1 ); }

	nv::vec4f color;

private:
	int _index;

	DISALLOW_COPY_AND_ASSIGN(LightSource);
};

#endif // MIRAGE_LIGHTSOURCE_HPP__