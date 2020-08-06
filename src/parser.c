/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grolash <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 13:39:08 by grolash           #+#    #+#             */
/*   Updated: 2020/08/06 13:20:42 by grolash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "scop.h"

int		get_data_size(char **stab, const char *delim,
		size_t *start)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (stab[i] != NULL && strncmp(stab[i], delim, 2))
	{
		i++;
	}
	*start = i + 1;
	while (stab[i] != NULL && !strncmp(stab[i], delim, 2))
	{
		size++;
		i++;
	}
	return (size);
}

static int	get_data(char **stab, t_obj *obj)
{
	int	ret;

	ret = 0;
	ret = get_vertex(stab, obj);
	return (ret);
}

int			parser(int argc, char **argv, t_obj *obj)
{
	const char	*buf;
	char		**temp;
	int			ret;

	ret = 0;
	if (argc != 2)
		return (-1);
	buf = load_source(argv[1]);
	temp = ft_strsplit(buf, '\n');
	free((char*)buf);
	buf = NULL;
	ret = get_data(temp, obj);
	ft_free_tab((void**)temp);
	return (ret);
}
