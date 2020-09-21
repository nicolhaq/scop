/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grolash <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:30:46 by grolash           #+#    #+#             */
/*   Updated: 2020/09/21 13:54:34 by grolash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	vec_init(GLfloat *vec, GLfloat pos_x, GLfloat pos_y, GLfloat pos_z)
{
	vec[x] = pos_x;
	vec[y] = pos_y;
	vec[z] = pos_z;
}

void	cam_init(t_cam *cam)
{
	cam->angle = -90.0f;
	vec_init(cam->pos, 0.0f, 0.0f, 5.0f);
	vec_init(cam->axis, 0.0f, 0.01f, 0.0f);
	vec_init(cam->zoom, 1.0f, 1.0f, 1.0f);
}

void	mat4_view(t_mat4 *mat4, t_cam *cam)
{
	t_mat4	temp;

	mat4_init( &temp, 1.0f);
	mat4_trans(&temp, cam->pos);
	mat4_rotat(&temp, cam->angle, cam->axis);
	mat4_scale(&temp, cam->zoom);
	mat4_mult(mat4, &temp);
}

void	mat4_perspective(t_mat4 *mat4, GLfloat width,\
			GLfloat height, GLfloat fov)
{
	t_mat4	temp;
 	GLfloat	tanHalfFov;
	GLfloat	near;
	GLfloat	far;

	near = 0.01f;
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
