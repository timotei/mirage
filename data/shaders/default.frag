//FRAGMENT SHADER
#version 140

struct LightSource
{
	vec4 color;
	vec3 position;
};

uniform LightSource lights[8];
uniform sampler2D tex;
uniform bool u_UseTexture;

varying vec3 N;
varying vec4 V;

void main()
{
    vec3 L = normalize(lights[0].position - V.xyz);
	
    // output the diffuse color
    float NdotL = dot(N, L);
	if ( u_UseTexture )
		gl_FragColor = texture2D( tex, gl_TexCoord[0].st ) * gl_Color * vec4(max(0.0, NdotL)) * lights[0].color + gl_LightModel.ambient;
	else
		gl_FragColor = gl_Color * vec4(max(0.0, NdotL)) * lights[0].color + gl_LightModel.ambient;
}