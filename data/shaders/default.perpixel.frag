//FRAGMENT SHADER
#version 140

struct LightSource
{
	vec4 color;
	vec3 position;
};

uniform LightSource lights[8];

varying vec3 N;
varying vec4 V;

void main()
{
    vec3 L = normalize(lights[0].position - V.xyz);
	
    // output the diffuse color
    float NdotL = dot(N, L);
	gl_FragColor = gl_Color * vec4(max(0.0, NdotL)) * lights[0].color + gl_LightModel.ambient;
}