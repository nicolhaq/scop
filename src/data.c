/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grolash <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 11:14:55 by grolash           #+#    #+#             */
/*   Updated: 2020/08/28 14:23:49 by grolash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "scop.h"
#include <stdlib.h>
#include <stdio.h>

static int	triangulate(t_obj *obj, char **temp)
{
	static size_t	y = 0;
	size_t			z;
	size_t			i_num;

	z = 0;
	i_num = 0;
	while (temp[i_num])
		i_num++;
	while (z < i_num - 3)
	{
		obj->ind[y] = atoi(temp[1]) - 1;
		obj->ind[y + 1] = atoi(temp[z + 2]) - 1;
		obj->ind[y + 2] = atoi(temp[z + 3]) - 1;
		z++;
		y += 3;
	}
	return (0);
}

static int	fill_array(t_obj *obj, char **temp)
{
	static size_t	y = 0;

	if (temp[0][0] == 'v')
	{
		obj->vert[y] = strtof(temp[1], NULL);
		obj->vert[y + 1] = strtof(temp[2], NULL);
		obj->vert[y + 2] = strtof(temp[3], NULL);
		y += 3;
		if (errno == ERANGE)
			return (-43);
	}
	else if (temp[0][0] == 'f')
	{
		triangulate(obj, temp);
	}
	return (0);
}

static int	data_split(t_obj *obj, char **stab)
{
	size_t		i;
	char		**temp;

	i = 0;
	while (stab[i])
	{
		if (stab[i][0] == 'f' || stab[i][0] == 'v')
		{
			temp = ft_strsplit(stab[i], ' ');
			fill_array(obj, temp);
			ft_free_tab((void **)temp);
			temp = NULL;
		}
		i++;
	}
	return (0);
}

int			get_data(char **stab, t_obj *obj)
{
	size_t	size;

	size = get_data_size(stab, 'v') * 3;
	obj->vert_size = size;
	if (!size)
		return (-41);
	if (!(obj->vert = (GLfloat *)malloc(sizeof(GLfloat) * size)))
		return (-42);
	size = get_data_size(stab, 'f') * 3;
	obj->ind_size = size;
	if (!size)
		return (-41);
	if (!(obj->ind = (GLuint *)malloc(sizeof(GLuint) * size)))
		return (-42);
	return (data_split(obj, stab));
}
