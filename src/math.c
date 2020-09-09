/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grolash <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 13:03:29 by grolash           #+#    #+#             */
/*   Updated: 2020/09/09 15:26:40 by grolash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

#include <stdio.h>
void	mat4_mult(t_mat4 *mat4, t_mat4 *mult)
{
	size_t	i;
	size_t	j;
	t_mat4	res;

	i = 0;
	j = 0;
	mat4_init(&res, 0);
	while (i < 4)
	{
		while (j < 4)
		{
			res.mat[i][j] = mat4->mat[i][0] * mult->mat[0][j];
			res.mat[i][j] += (mat4->mat[i][1] * mult->mat[1][j]);
			res.mat[i][j] += (mat4->mat[i][2] * mult->mat[2][j]);
			res.mat[i][j] += (mat4->mat[i][3] * mult->mat[3][j]);
			j++;
		}
		j = 0;
		i++;
	}
	memcpy(mat4->ptr, res.ptr, sizeof(GLfloat[16]));
}

void	mat4_init(t_mat4 *mat4, GLfloat source)
{
	memset(mat4->ptr, 0, sizeof(mat4->ptr));
	mat4->x = &mat4->ptr[0];
	mat4->y = &mat4->ptr[4];
	mat4->z = &mat4->ptr[8];
	mat4->w = &mat4->ptr[12];
	mat4->mat[0] = mat4->x;
	mat4->mat[1] = mat4->y;
	mat4->mat[2] = mat4->z;
	mat4->mat[3] = mat4->w;
	mat4->x[0] = source;
	mat4->y[1] = source;
	mat4->z[2] = source;
	mat4->w[3] = source;
}

void	mat4_scale(t_mat4 *mat4, GLfloat *vec)
{
	t_mat4	temp;

	mat4_init(&temp, 1);
	temp.x[0] = vec[0];
	temp.y[1] = vec[1];
	temp.z[2] = vec[2];
	temp.w[3] = vec[3];
	mat4_mult(mat4, &temp);
}

void	mat4_trans(t_mat4 *mat4, GLfloat *vec)
{
	t_mat4	temp;

	mat4_init(&temp, 1);
	temp.w[0] = vec[0];
	temp.w[1] = vec[1];
	temp.w[2] = vec[2];
	temp.w[3] = vec[3];
	mat4_mult(mat4, &temp);
}

void	mat4_rotat(t_mat4 *mat4, GLfloat rad, enum e_axis axis)
{
	t_mat4	temp;

	mat4_init(&temp, 1);
	if (axis == x)
	{
		temp.y[1] = cos(rad);
		temp.y[2] = -sin(rad);
		temp.z[1] = sin(rad);
		temp.z[2] = cos(rad);
	}
	else if (axis == y)
	{
		temp.x[0] = cos(rad);
		temp.x[2] = sin(rad);
		temp.z[0] = -sin(rad);
		temp.z[2] = cos(rad);
	}
	else if (axis == z)
	{
		temp.x[0] = cos(rad);
		temp.x[1] = -sin(rad);
		temp.y[0] = sin(rad);
		temp.y[1] = cos(rad);
	}
	mat4_mult(mat4, &temp);
}
