/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grolash <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 14:10:44 by grolash           #+#    #+#             */
/*   Updated: 2020/09/25 13:41:28 by grolash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scop.h>

static int	init_window(GLFWwindow **window)
{
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	if (OSX)
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	*window = glfwCreateWindow(600, 600, "scop", NULL, NULL);
	if (*window == NULL)
		return (-12);
	glfwMakeContextCurrent(*window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		ft_putstr_fd(2, "Error: Failed to initialize GLAD\n");
		return (-13);
	}
	return (0);
}

static int	init_glfw(void)
{
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		return (-11);
	return (0);
}

int			init(GLFWwindow **window)
{
	int	error;

	error = 0;
	if ((error = init_glfw()))
		return (error);
	if ((error = init_window(window)))
		return (error);
	glfwSetKeyCallback(*window, key_callback);
	glfwSetFramebufferSizeCallback(*window, framebuffer_size_callback);
	glfwSetInputMode(*window, GLFW_STICKY_KEYS, GLFW_TRUE);
	return (0);
}
