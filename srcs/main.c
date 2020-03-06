/*#include "glad/glad.h"*/
#include <GLFW/glfw3.h>
#include <stdio.h>


void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error %d: %s\n", error, description);
}

int	main(int argc, char** argv)
{
	(void)argc;
	(void)argv;
	if (!glfwInit())
	{
		puts("error: glfwInit failed");
		return (-1);
	}
	glfwSetErrorCallback(error_callback);

	glfwTerminate();
	return (0);
}
