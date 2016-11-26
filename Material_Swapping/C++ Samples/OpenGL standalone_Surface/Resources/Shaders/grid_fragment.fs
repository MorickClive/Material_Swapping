#version 330

uniform float gridLineWidth; // should be a value between 1 and 20
uniform int Shd_ClMode;

in vec4 colour;
in vec4 vertices;

layout (location=0) out vec4 fragColour;

void main(void) {
 
   //Here is our Vertex Coordinates
   // Calculations determine each signif int figure, finds modulus between them
    float x = mod(vertices.x, 1);
    float z = mod(vertices.z, 1);

    // absolute value of our sine wave allows for ID of peeks and troughs
    float y = abs(vertices.y); 
    float y1 = y * 0.5;

    // This is a linewidth Uniform variable handle
    float lineWidth = gridLineWidth * 0.025; // this determines a perfect unit line between weight 1 and 20
    float lineUpper = 1 - (lineWidth * 1); // this is a value that reachs to 1 for the line
    float lineLesser = lineWidth; // this is a value that descends to 0.0 for the line

    /////
    // Send pixel colour data
    /////

    // Logic
    // if each unit is divide into a gradient square
    // find the value 0.95 to 1 and fill in black
    // find the value 0.05 and 0 tand fil in black
    // each corner edge of a gradient square is either 0 or 1
    // if statements below check for black based on grid value created by unit modulus

    if(x >= lineUpper || z >= lineUpper) { fragColour = vec4(0, 0, 0, 1); } // set pixels black
    else if(x <= lineLesser|| z <= lineLesser) { fragColour = vec4(0, 0, 0, 1); } // set pixels black

    else {
		if(Shd_ClMode == 1)
		{
			// green and white
			fragColour = vec4(y1, 1, y1, 1); 
		}
		if(Shd_ClMode == 2)
		{
			// blue and white
			fragColour = vec4(y1, 1, y1, 1) + vec4(0, 0, 1, 1) ; 
		}
	} // Else set pixels white (not a line)
    // I adjusted the background code to create a gradient from white to green to demonstrate
    // the gradient in the sine wave, this could be applied with noise functions to add variation.
    // to set white, just remove "y" from both x and z axis from the else condition.
}
