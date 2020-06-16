/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grolash <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 23:38:45 by grolash           #+#    #+#             */
/*   Updated: 2020/06/16 14:35:07 by grolash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scop.h>

int	init_window(GLFWwindow **window)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	*window = glfwCreateWindow(1024, 768,"scop", NULL, NULL);
	if(*window == NULL)
		return (-1);
	glfwMakeContextCurrent(*window);
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		ft_putstr_fd(2, "Error: Failed to initialize GLAD\n");
		return(-1);
	}
	return (0);
}

int		init_glfw()
{
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		return (-1);
	return (0);
}

int		init()
{
	GLFWwindow	*window;

	window = NULL;
	if(init_glfw())
		return (-1);
	if(init_window(&window))
		return (-1);
	glfwSetKeyCallback(window, key_callback);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_TRUE);
	while(!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	return (0);
}

int		draw()
{
	GLuint Vertex_array_ID;

	return (0);
}

int		main(int argc,char **argv)
{
	(void)argc;
	(void)argv;
	if(init())
		return (-1);
	glfwTerminate();
	return (0);
}
