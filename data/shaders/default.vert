//VERTEX SHADER
#version 140

struct LightSource
{
	vec4 color;
	vec3 position;
};

uniform LightSource lights[8];
uniform mat4 u_VMatrix;
uniform mat4 u_MMatrix;
uniform mat4 u_PMatrix;

void main(void)
{
    // normal MVP transform
    gl_Position = u_PMatrix * u_VMatrix * u_MMatrix * gl_Vertex;

    vec3 N = normalize(gl_NormalMatrix * gl_Normal);
    vec4 V = u_VMatrix * u_MMatrix * gl_Vertex;
    vec3 L = normalize(lights[0].position - V.xyz);

    // output the diffuse color
    float NdotL = dot(N, L);
    gl_FrontColor = gl_Color * vec4(max(0.0, NdotL)) * lights[0].color;
}