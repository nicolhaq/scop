#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <libft/libft.h>
/*#include <stdio.h>*/
#include <stdlib.h>


//temporary need to remove after test
#include "linmath.h"

static const struct
{
	float x, y;
	float r, g, b;
} vertices[3] =
{
	{ -0.6f, -0.4f, 1.f, 0.f, 0.f },
	{  0.6f, -0.4f, 0.f, 1.f, 0.f },
	{   0.f,  0.6f, 0.f, 0.f, 1.f }
};

static const char* vertex_shader_text =
	"#version 110\n"
	"uniform mat4 MVP;\n"
	"attribute vec3 vCol;\n"
	"attribute vec2 vPos;\n"
	"varying vec3 color;\n"
	"void main()\n"
	"{\n"
	"    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
	"    color = vCol;\n"
	"}\n";

static const char* fragment_shader_text =
	"#version 110\n"
	"varying vec3 color;\n"
	"void main()\n"
	"{\n"
	"    gl_FragColor = vec4(color, 1.0);\n"
	"}\n";
static void	error_callback(int error, const char* description)
{
	ft_putstrfd(2, "Error ");
	ft_putnbrfd(2, error);
	ft_putstrfd(2, ": ");
	ft_putstrfd(2, description);
	ft_putcharfd(2, '\n');
}

static void	key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	(void)scancode;
	(void)mods;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int vertex_controler(GLuint *program)
{
	GLuint vertex_buffer;
	GLuint vertex_shader;
	GLuint fragment_shader;

	vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	*program = glCreateProgram();
	if(!vertex_shader || !fragment_shader || !*program)
		return (0);
	glGenBuffers(1, &vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
	glCompileShader(vertex_shader);
	glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
	glCompileShader(fragment_shader);
	glAttachShader(*program, vertex_shader);
	glAttachShader(*program, fragment_shader);
	glLinkProgram(*program);
	return (1);
}

static int	window_controler()
{
	GLuint program;
	GLint mvp_location, vpos_location, vcol_location;
	GLFWwindow* window;
	window = glfwCreateWindow(640, 480, "Scop", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwSetKeyCallback(window, key_callback);
	glfwMakeContextCurrent(window);
	gladLoadGL();
	glfwSwapInterval(1);

	// NOTE: OpenGL error checks have been omitted for brevity

	vertex_controler(&program);
	mvp_location = glGetUniformLocation(program, "MVP");
	vpos_location = glGetAttribLocation(program, "vPos");
	vcol_location = glGetAttribLocation(program, "vCol");

	glEnableVertexAttribArray(vpos_location);
	glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE,
			sizeof(vertices[0]), (void*) 0);
	glEnableVertexAttribArray(vcol_location);
	glVertexAttribPointer(vcol_location, 3, GL_FLOAT, GL_FALSE,
			sizeof(vertices[0]), (void*) (sizeof(float) * 2));

	while (!glfwWindowShouldClose(window))
	{
		float ratio;
		int width, height;
		mat4x4 m, p, mvp;

		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float) height;

		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);

		mat4x4_identity(m);
		mat4x4_rotate_Z(m, m, (float) glfwGetTime());
		mat4x4_ortho(p, -ratio, ratio, -1.f, 1.f, 1.f, -1.f);
		mat4x4_mul(mvp, p, m);

		glUseProgram(program);
		glUniformMatrix4fv(mvp_location, 1, GL_FALSE, (const GLfloat*) mvp);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	return(0);
}

int		main(int argc, char** argv)
{
	(void)argc;
	(void)argv;
	ft_putchar('l');
	if (!glfwInit())
	{
		ft_putstr("error: glfwInit failed");
		return (-1);
	}
	glfwSetErrorCallback(error_callback);
	window_controler();
	glfwTerminate();
	return (0);
}
