#version 410 core
out vec4 frag_color;
flat in vec3 v_color;
void main()
{
	float grey;
	grey = (0.2125 * v_color.x + 0.7154 * v_color.y + 0.0721 * v_color.z) / 1.2f;
	frag_color = vec4(grey,grey, grey, 1.0f);
}
