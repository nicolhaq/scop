/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grolash <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 14:19:42 by grolash           #+#    #+#             */
/*   Updated: 2020/09/10 13:14:51 by grolash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <stdio.h>

static void	get_vminmax(t_obj *obj)
{
	size_t	i;
	size_t	j;

	i = 0;
	obj->min[x] = obj->vert[0];
	obj->min[y] = obj->vert[1];
	obj->min[z] = obj->vert[2];
	obj->max[x] = obj->min[x];
	obj->max[y] = obj->min[y];
	obj->max[z] = obj->min[z];
	while (i < obj->vert_size)
	{
		j = 0;
		while (j < 3)
		{
			if (obj->min[j] > obj->vert[i])
				obj->min[j] = obj->vert[i];
			else if (obj->max[j] < obj->vert[i])
				obj->max[j] = obj->vert[i];
			j++;
			i++;
		}
	}
}

void		normalize_scale(t_obj *obj)
{
	obj->rescale[x] = obj->max[x] - obj->min[x];
	obj->rescale[y] = obj->max[y] - obj->min[y];
	obj->rescale[z] = obj->max[z] - obj->min[z];
	obj->rescale[w] = obj->rescale[x];
	if (obj->rescale[w] < obj->rescale[y])
	{
		obj->rescale[w] = obj->rescale[y];
		if (obj->rescale[w] < obj->rescale[z])
			obj->rescale[w] = obj->rescale[z];
	}
	obj->rescale[x] = 1 / obj->rescale[w];
	obj->rescale[y] = 1 / obj->rescale[w];
	obj->rescale[z] = 1 / obj->rescale[w];
	obj->rescale[w] = 1;
}

void		normalize_center(t_obj *obj)
{
	obj->center[x] = -(obj->min[x] + obj->max[x]) / 2.0f;
	obj->center[y] = -(obj->min[y] + obj->max[y]) / 2.0f;
	obj->center[z] = -(obj->min[z] + obj->max[z]) / 2.0f;
	obj->center[w] = 1;
}

int			normalize(t_obj *obj)
{
	// size_t	i;

	// i = 0;
	get_vminmax(obj);
	normalize_scale(obj);
	normalize_center(obj);
	return (0);
}
