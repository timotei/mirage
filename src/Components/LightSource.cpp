/*
   Copyright (C) 2011-2012 by Timotei Dolean <timotei21@gmail.com>

   Part of the Mirage Project https://github.com/timotei/mirage

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY.

   See the COPYING file for more details.
*/
#include "LightSource.hpp"

#include <sstream>

#include "Camera.hpp"

static int LIGHTS_COUNTER = 0;

LightSource::LightSource( Game* parent ) :
GameComponent( parent ),
_index( LIGHTS_COUNTER ),
color( 1.0f, 1.0f, 1.0f, 1.0f )
{
	LIGHTS_COUNTER ++ ;
}

LightSource::~LightSource()
{
}

void LightSource::draw( bool shadow )
{
	if ( shadow )
		return;

	glPushMatrix();

	glTranslatef(translationPostRotation.x, translationPostRotation.y, translationPostRotation.z);

	glRotatef(rotation.x, 1, 0, 0);
	glRotatef(rotation.y, 0, 1, 0);
	glRotatef(rotation.z, 0, 0, 1);

	glTranslatef(translation.x, translation.y, translation.z);
	glutSolidSphere(1, 10, 10);

	glPopMatrix();
}

void LightSource::sendToShaderProgram( ShaderProgram& program, const Camera& cam )
{
	std::ostringstream name;
	name << "u_Lights[" << _index << "].position";

	nv::vec4f res = cam.getViewMatrix() *  getModelMatrix() * nv::vec4f( 0, 0, 0, 1.0f );
	program.setUniform( name.str().c_str(), res._xyz );

	name.str( "" );

	name << "u_Lights[" << _index << "].color";
	program.setUniform( name.str().c_str(), color );
}
