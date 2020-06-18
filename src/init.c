/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grolash <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 14:10:44 by grolash           #+#    #+#             */
/*   Updated: 2020/06/18 14:42:21 by grolash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <scop.h>

int	init_window(GLFWwindow **window)
{
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	/*uncoment on macos*/
	/*glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);*/
	*window = glfwCreateWindow(800, 600,"scop", NULL, NULL);
	if(*window == NULL)
		return (-1);
	glfwMakeContextCurrent(*window);
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		ft_putstr_fd(2, "Error: Failed to initialize GLAD\n");
		return(-1);
	}
	glViewport(0, 0, 800, 600);
	return (0);
}

int	init_glfw()
{
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		return (-1);
	return (0);
}

int	init(GLFWwindow **window)
{
	/*GLuint vertex_array_ID;*/

	if(init_glfw())
		return (-1);
	if(init_window(&*window))
		return (-1);
	if (shader_link())
		return (-1);
	/*glGenVertexArrays(1, &vertex_array_ID);*/
	/*glBindVertexArray(vertex_array_ID);*/
	glfwSetKeyCallback(*window, key_callback);
	glfwSetFramebufferSizeCallback(*window, framebuffer_size_callback);
	glfwSetInputMode(*window, GLFW_STICKY_KEYS, GLFW_TRUE);
	return (0);
}

