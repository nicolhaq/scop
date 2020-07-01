/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grolash <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 13:03:29 by grolash           #+#    #+#             */
/*   Updated: 2020/07/01 13:45:58 by grolash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "scop.h"
#include <string.h>

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
	ft_bzero(mat4->ptr, sizeof(mat4->ptr));
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

void	mat_translate(t_mat4 *mat4, GLfloat *vec3)
{
	mat4->x[3] = vec3[0];
	mat4->y[3] = vec3[1];
	mat4->z[3] = vec3[2];
}

void	mat_mult(t_mat4 *mat4, t_mat4 *mult)
{
	size_t i;
	size_t j;
	t_mat4 res;

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
	*mat4 = res;
}
