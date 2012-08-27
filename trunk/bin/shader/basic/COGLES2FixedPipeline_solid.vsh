attribute mediump vec4 inVertexPosition;
attribute mediump vec4 inVertexColor;

uniform mediump mat4 uMvpMatrix;

varying mediump vec4 varVertexColor;

void main(void)
{
	varVertexColor = inVertexColor;	
	gl_Position = uMvpMatrix * inVertexPosition;	
}