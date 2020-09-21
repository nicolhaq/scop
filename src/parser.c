/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grolash <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 13:39:08 by grolash           #+#    #+#             */
/*   Updated: 2020/09/15 16:57:19 by grolash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "scop.h"
#include <ctype.h>

static size_t	get_data_num(const char *s)
{
	size_t		y;

	y = 0;
	while (*s != '\0')
	{
		while (isspace(*s) && *s != '\0')
			s++;
		if (!isspace(*s) && *s != '\0')
			y++;
		while (!isspace(*s) && *s != '\0')
			s++;
	}
	return (y);
}

size_t			get_data_size(char **stab, const char delim)
{
	size_t		i;
	size_t		size;

	i = 0;
	size = 0;
	while (stab[i] != NULL && stab[i][0] != delim)
	{
		i++;
	}
	while (stab[i] != NULL && stab[i][0] == delim)
	{
		size += 1 + (get_data_num(stab[i]) - 4);
		i++;
	}
	return (size);
}

int				parser(int argc, char **argv, t_obj *obj)
{
	const char	*buf;
	char		**temp;
	int			ret;

	ret = 0;
	if (argc != 2)
		return (-1);
	buf = load_source(argv[1]);
	if(!buf)
		return(-50);
	temp = ft_strsplit(buf, '\n');
	free((char*)buf);
	buf = NULL;
	ret = get_data(temp, obj);
	normalize(obj);
	ft_free_tab((void**)temp);
	return (ret);
}
