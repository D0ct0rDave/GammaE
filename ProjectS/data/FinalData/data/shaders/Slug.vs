//varying vec2 TMU0TexCoords;
varying vec3 normal;

void main()
{
	// 
	normal = gl_NormalMatrix * gl_Normal;

	// Transforming The Vertex
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;

	// Passing The Texture Coordinate Of Texture Unit 0 To The Fragment Shader
	
	// gl_TexCoord[0] = gl_MultiTexCoord0;

	// Perform an offset over the mapping. Add secondary color just to give some ramdomness.	
	gl_TexCoord[0] = (vec4(gl_Normal,1.0) + vec4(1,1,0,0)) * vec4(0.5,0.5,0,0) + gl_SecondaryColor;
}
