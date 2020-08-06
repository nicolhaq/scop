/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grolash <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 13:03:29 by grolash           #+#    #+#             */
/*   Updated: 2020/08/06 13:09:42 by grolash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	mat_mult(t_mat4 *mat4, t_mat4 *mult)
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

void	vec_mult(t_mat4 *mat4, GLfloat vec4[4])
{
	size_t	i;
	GLfloat	res[4];

	i = 0;
	while(i < 4)
	{
		res[i] = mat4->mat[i][0] * vec4[0];
		res[i] += (mat4->mat[i][1] * vec4[1]);
		res[i] += (mat4->mat[i][2] * vec4[2]);
		res[i] += (mat4->mat[i][3] * vec4[3]);
		i++;
	}
	memcpy(vec4, res, sizeof(GLfloat[3]));
}

void	print_mat4(t_mat4 *mat)
{
	int i;

	i = 0;
	while (i < 16)
	{
		ft_putnbr((int)mat->ptr[i]);
		ft_putstr("	|");
		if (i == 3 || i == 7 || i == 11)
			ft_putchar('\n');
		i++;
	}
	ft_putstr("\n===========================================\n");
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

void	mat4_scale(t_mat4 *mat4, GLfloat x, GLfloat y, GLfloat z)
{
	mat4->x[0] = x;
	mat4->y[1] = y;
	mat4->z[2] = z;
}

void	mat4_trans(t_mat4 *mat4, GLfloat x, GLfloat y,GLfloat z)
{
	mat4->w[0] = x;
	mat4->w[1] = y;
	mat4->w[2] = z;

}

void	mat4_rotat(t_mat4 *mat4, GLfloat rad, enum e_axis axis)
{
	if (axis == x)
	{
		mat4->y[1] = cos(rad);
		mat4->y[2] = -sin(rad);
		mat4->z[1] = sin(rad);
		mat4->z[2] = cos(rad);
	}
	else if (axis == y)
	{
		mat4->x[0] = cos(rad);
		mat4->x[2] = sin(rad);
		mat4->z[0] = -sin(rad);
		mat4->z[2] = cos(rad);
	}
	else if (axis == z)
	{
		mat4->x[0] = cos(rad);
		mat4->x[1] = -sin(rad);
		mat4->y[0] = sin(rad);
		mat4->y[1] = cos(rad);
	}
}

