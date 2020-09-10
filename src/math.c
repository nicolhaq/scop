/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grolash <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 13:03:29 by grolash           #+#    #+#             */
/*   Updated: 2020/09/10 13:06:13 by grolash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

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
			res.mat[i][j] = mat4->mat[i][x] * mult->mat[x][j];
			res.mat[i][j] += (mat4->mat[i][y] * mult->mat[y][j]);
			res.mat[i][j] += (mat4->mat[i][z] * mult->mat[z][j]);
			res.mat[i][j] += (mat4->mat[i][w] * mult->mat[w][j]);
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
	mat4->mat[x] = mat4->x;
	mat4->mat[y] = mat4->y;
	mat4->mat[z] = mat4->z;
	mat4->mat[w] = mat4->w;
	mat4->x[x] = source;
	mat4->y[y] = source;
	mat4->z[z] = source;
	mat4->w[w] = source;
}

void	mat4_scale(t_mat4 *mat4, GLfloat *vec)
{
	t_mat4	temp;

	mat4_init(&temp, 1);
	temp.x[x] = vec[x];
	temp.y[y] = vec[y];
	temp.z[z] = vec[z];
	temp.w[w] = vec[w];
	mat4_mult(mat4, &temp);
}

void	mat4_trans(t_mat4 *mat4, GLfloat *vec)
{
	t_mat4	temp;

	mat4_init(&temp, 1);
	temp.w[x] = vec[x];
	temp.w[y] = vec[y];
	temp.w[z] = vec[z];
	temp.w[w] = vec[w];
	mat4_mult(mat4, &temp);
}

void	mat4_rotat(t_mat4 *mat4, GLfloat rad, enum e_axis axis)
{
	t_mat4	temp;

	mat4_init(&temp, 1);
	if (axis == x)
	{
		temp.y[y] = cos(rad);
		temp.y[z] = -sin(rad);
		temp.z[y] = sin(rad);
		temp.z[z] = cos(rad);
	}
	else if (axis == y)
	{
		temp.x[x] = cos(rad);
		temp.x[z] = sin(rad);
		temp.z[x] = -sin(rad);
		temp.z[z] = cos(rad);
	}
	else if (axis == z)
	{
		temp.x[x] = cos(rad);
		temp.x[y] = -sin(rad);
		temp.y[x] = sin(rad);
		temp.y[y] = cos(rad);
	}
	mat4_mult(mat4, &temp);
}
