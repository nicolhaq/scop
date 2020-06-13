#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <libft/libft.h>
#include <stdlib.h>


static void	error_callback(int error, const char* description)
{
	ft_putstrfd(2, "Error ");
	ft_putnbrfd(2, error);
	ft_putstrfd(2, ": ");
	ft_putstrfd(2, description);
	ft_putcharfd(2, '\n');
}

__attribute__((unused))
static void	key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	(void)scancode;
	(void)mods;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int	create_window()
{
	GLFWwindow	*window;

	window = glfwCreateWindow(1024, 768,"scop", NULL, NULL);
	if(!window)
	{
		return (-1);
	}
	return (0);
}

int		init()
{
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
	{
		return (-1);
	}
	return (0);
}

int		main(int argc, char** argv)
{
	(void)argc;
	(void)argv;
	init();
	create_window();
	glfwTerminate();
	return (0);
}
