//FRAGMENT SHADER
#version 140

struct LightSource
{
	vec4 color;
	vec3 position;
};

uniform LightSource u_Lights[8];
uniform float u_LightsCount;
uniform sampler2D tex;
uniform bool u_UseTexture;

varying vec3 N;
varying vec4 V;

void main()
{
	vec4 color = vec4(0.0, 0.0, 0.0, 1.0);
	int i = 0;
	for( i = 0; i < u_LightsCount.x; i ++ ) {
		vec3 L = normalize(u_Lights[i].position - V.xyz);
		
		// output the diffuse color
		float NdotL = dot(N, L);
		color += vec4(max(0.0, NdotL)) * u_Lights[i].color;
	}
	
	color = color * gl_Color;
		
	if ( u_UseTexture )
		gl_FragColor = texture2D( tex, gl_TexCoord[0].st ) * color + gl_LightModel.ambient;
	else
		gl_FragColor = color + gl_LightModel.ambient;
}