//VERTEX SHADER
#version 140

struct LightSource
{
	vec3 color;
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
	vec3 light = (u_VMatrix * vec4(lights[0].position, 1)).xyz;
    vec3 L = normalize(light - V.xyz);

    // output the diffuse color
    float NdotL = dot(N, L);
    gl_FrontColor = gl_Color * vec4(max(0.0, NdotL));
}