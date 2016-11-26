#version 330

uniform mat4 viewProjMatrix;
uniform mat4 modelMatrix;
uniform vec4 gridOffset;
uniform float Amplitude;
uniform int Shd_Mode;


layout (location=0) in vec4 vertexPos;
layout (location=1) in vec4 vertexColour;

out vec4 colour;
out vec4 vertices;

vec4 sinwave_Offset(vec4 Handlevector)
{
	// This takes a vector and adds Sine wave variation to the Y axis
	vec4 SineOffset = vec4(0.0f,0.0f,0.0f,0.0f);

	// This handles the UV mapping of a radial SineWave
	float x5,y5;
	x5 = Handlevector.x - 15;
	y5 = Handlevector.z - 15;

	float speed = 5;

	if(Shd_Mode == 1)
	{
		SineOffset = vec4(0.0f, cos(Handlevector.x) + cos(Handlevector.z), 0.0f, 0.0f);
	}
	if(Shd_Mode == 2)
	{
		SineOffset = vec4(0.0f, sin(sqrt(  (x5*x5) + (y5*y5)  )), 0.0f, 0.0f);
	}

	vec4 Result = Handlevector + SineOffset * (sin(Amplitude * speed)* 2); // amp amplifies the sine wave height

	return Result;

}

void main(void) {

	
	vec4 Offset = gridOffset + sinwave_Offset(vertexPos);
	colour = vertexColour;
	vertices = Offset;

	gl_Position = viewProjMatrix * modelMatrix * Offset;
}