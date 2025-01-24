varying vec3 normal;

void main()
{
	normal = gl_NormalMatrix * gl_Normal;

	// Transforming The Vertex
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;

	// Passing The Texture Coordinate Of Texture Unit 0 To The Fragment Shader
	gl_TexCoord[0] = gl_MultiTexCoord0;
}
