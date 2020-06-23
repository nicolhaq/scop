/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grolash <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 23:35:58 by grolash           #+#    #+#             */
/*   Updated: 2020/06/23 16:38:45 by grolash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H
# include <glad/glad.h>
# include <GLFW/glfw3.h>
# include <math.h>
# include <stdlib.h>
# include "libft/libft.h"
# define OSX 0
# ifdef MACOS
#  define OSX 1
# endif

void	error_callback(int error, const char *description);
void	key_callback(GLFWwindow *window, int key, int scancode,\
		int action, int mods);
void	framebuffer_size_callback(GLFWwindow *window, int width, int height);
int	init(GLFWwindow **window);
int	shader_link(GLuint *shader_program);
#endif
