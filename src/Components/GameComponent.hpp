#ifndef MIRAGE_GAMECOMPONENT_HPP__
#define MIRAGE_GAMECOMPONENT_HPP__

#include "../Lua/LuaScript.hpp"
#include <boost/shared_ptr.hpp>
#include "nvMatrix.h"
#include "nvQuaternion.h"
#include "nvMath.h"

#include "../ShaderProgram.hpp"

class GameComponent{
public:
	virtual void draw() {}
	virtual void update() 
	{
		if ( script != NULL ) {
			script->callVoidFunction( "update" );
		}
	}

	virtual void onKeyPressed(int, int, int, bool) {};

	virtual void loadScript(std::string path) {}

	virtual ~GameComponent() {}

	virtual nv::matrix4f getTransformationMatrix() {
		nv::matrix4f rotationMatrix;
		nv::quaternionf rotationQ;
		rotationQ.set_value( nv::vec3f( 1, 0, 0 ), rotation.x );
		rotationQ.set_value( nv::vec3f( 0, 1, 0 ), rotation.y );
		rotationQ.set_value( nv::vec3f( 0, 0, 1 ), rotation.z );

		rotationQ.get_value(rotationMatrix);

		nv::matrix4f translationMatrix;
		translationMatrix.set_translate( translation );

		return rotationMatrix * translationMatrix;
	}

	nv::vec3f translation;
	nv::vec3f rotation;

	boost::shared_ptr<LuaScript> script;
	ShaderProgram shader;
};

#endif // MIRAGE_GAMECOMPONENT_HPP__