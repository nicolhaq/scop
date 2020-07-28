#version 410 core
layout (location = 0) in vec3 aPos;
//layout (location = 1) in vec3 aColor;

flat out vec3 v_color;

uniform mat4 transform;

void main()
{
	v_color = vec3(aPos * 0.4f + 0.4f);
	gl_Position = transform * vec4(aPos, 1.0f);
}
