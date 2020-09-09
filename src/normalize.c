/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grolash <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 14:19:42 by grolash           #+#    #+#             */
/*   Updated: 2020/09/09 16:21:48 by grolash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "scop.h"

static void	get_vminmax(t_obj *obj)
{
	size_t	i;
	size_t	y;

	i = 0;
	obj->min[0] = obj->vert[0];
	obj->min[1] = obj->vert[1];
	obj->min[2] = obj->vert[2];
	obj->max[0] = obj->min[0];
	obj->max[1] = obj->min[1];
	obj->max[2] = obj->min[2];
	while (i < obj->vert_size)
	{
		y = 0;
		while (y < 3)
		{
			if(obj->min[y] > obj->vert[i])
				obj->min[y] = obj->vert[i];
			else if(obj->max[y] < obj->vert[i])
				obj->max[y] = obj->vert[i];
			y++;
			i++;
		}
	}
}

void		normalize_scale(t_obj *obj)
{
	obj->rescale[0] = obj->max[0] - obj->min[0];
	obj->rescale[1] = obj->max[1] - obj->min[1];
	obj->rescale[2] = obj->max[2] - obj->min[2];
	obj->rescale[3] = obj->rescale[0];
	if (obj->rescale[3] < obj->rescale[1])
	{
		obj->rescale[3] = obj->rescale[1];
		if (obj->rescale[3] < obj->rescale[2])
			obj->rescale[3] = obj->rescale[2];
	}
	obj->rescale[0] = 1 / obj->rescale[3];
	obj->rescale[1] = 1 / obj->rescale[3];
	obj->rescale[2] = 1 / obj->rescale[3];
	obj->rescale[3] = 1;
}

int			normalize(t_obj *obj)
{
	size_t	i;

	i = 0;
	get_vminmax(obj);
	normalize_scale(obj);
	return (0);
}
