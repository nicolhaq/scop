/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grolash <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:42:50 by grolash           #+#    #+#             */
/*   Updated: 2020/09/25 12:30:57 by grolash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <GLFW/glfw3.h>

void cam_key(GLFWwindow **windows, t_cam *cam)
{
	if (glfwGetKey(*windows, GLFW_KEY_W) == GLFW_PRESS)
		cam->pos[z]-=0.1;
	if (glfwGetKey(*windows, GLFW_KEY_S) == GLFW_PRESS)
		cam->pos[z]+=0.1;
	if (glfwGetKey(*windows, GLFW_KEY_A) == GLFW_PRESS)
		cam->pos[x]-=0.1;
	if (glfwGetKey(*windows, GLFW_KEY_D) == GLFW_PRESS)
		cam->pos[x]+=0.1;
	if (glfwGetKey(*windows, GLFW_KEY_Q) == GLFW_PRESS)
		cam->pos[y]-=0.1;
	if (glfwGetKey(*windows, GLFW_KEY_E) == GLFW_PRESS)
		cam->pos[y]+=0.1;
	if (glfwGetKey(*windows, GLFW_KEY_R) == GLFW_PRESS)
		cam_init(cam);
}
