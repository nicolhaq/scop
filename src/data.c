/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grolash <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 11:14:55 by grolash           #+#    #+#             */
/*   Updated: 2020/08/06 13:17:12 by grolash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "scop.h"
#include <stdio.h>

static int	fill_varray(t_obj *obj, char **stab, size_t *size, size_t *start)
{
	size_t	i;
	size_t	y;
	char	**temp;

	i = *start;
	y = 0;
	while (i <= *size)
	{
		temp = ft_strsplit(stab[i], ' ');
		obj->vert[y++] = strtof(temp[1], NULL);
		obj->vert[y++] = strtof(temp[2], NULL);
		obj->vert[y++] = strtof(temp[3], NULL);
		ft_free_tab((void **)temp);
		temp = NULL;
		i++;
	}
	return (0);
}

int			get_vertex(char **stab, t_obj *obj)
{
	size_t	start;
	size_t	size;

	start = 0;
	size = get_data_size(stab, "v ", &start);
	if (!size)
		return (-41);
	obj->vert_size = size * 3;
	obj->vert = malloc(sizeof(GLfloat) * obj->vert_size);
	return (fill_varray(obj, stab, &size, &start));
}
