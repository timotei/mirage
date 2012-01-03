//VERTEX SHADER
#version 140

uniform mat4 u_VMatrix;
uniform mat4 u_MMatrix;
uniform mat4 u_PMatrix;

varying vec3 N;
varying vec4 V;

void main(void)
{
    // normal MVP transform
    gl_Position = u_PMatrix * u_VMatrix * u_MMatrix * gl_Vertex;

    N = normalize(gl_NormalMatrix * gl_Normal);
    V = u_VMatrix * u_MMatrix * gl_Vertex;

    gl_FrontColor = gl_Color;
}