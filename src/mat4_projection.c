/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grolash <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:30:46 by grolash           #+#    #+#             */
/*   Updated: 2020/09/11 16:49:46 by grolash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	mat4_perspective(t_mat4 *mat4, GLfloat width,\
			GLfloat height, GLfloat fov)
{
	t_mat4	temp;
	GLfloat	tanHalfFov;
	GLfloat	near;
	GLfloat	far;

	near = 0.1f;
	far = 100.0f;
	tanHalfFov = tanf((fov / 2.0f) * M_PI / 180.0f);
	mat4_init(&temp, 1.0f);
	temp.x[x] = 1.0f / (tanHalfFov * width / height);
	temp.y[y] = 1.0f / tanHalfFov;
	temp.z[z] = -(far + near) / (far - near);
	temp.z[w] = -1.0f;
	temp.w[z] = -(2.0f * far * near) / (far - near);
	mat4_mult(mat4, &temp);

}
