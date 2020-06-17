/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grolash <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 23:35:37 by grolash           #+#    #+#             */
/*   Updated: 2020/06/17 14:22:03 by grolash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scop.h>

void	error_callback(int error, const char* description)
{
	ft_putstr_fd(2, "Error ");
	ft_putnbr_fd(2, error);
	ft_putstr_fd(2, ": ");
	ft_putstr_fd(2, description);
	ft_putchar_fd(2, '\n');
}

void	key_callback(GLFWwindow* window, int key,\
		int scancode __attribute__((unused)), int action,\
		int mods __attribute__((unused)))
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void	framebuffer_size_callback(GLFWwindow *window __attribute__((unused)),\
		int width, int height)
{
	glViewport(0, 0, width, height);
}
