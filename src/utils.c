/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grolash <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 13:03:13 by grolash           #+#    #+#             */
/*   Updated: 2020/07/08 16:49:55 by grolash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <sys/stat.h>
#include <fcntl.h>

const char	*load_source(char *filepath)
{
	int			fd;
	struct stat	st;
	char		*source;
	int			ret;

	if ((fd = open(filepath, O_RDONLY)) == -1)
		error_callback(-31, "cannot open vertex shader.");
	if (stat(filepath, &st) == -1)
		error_callback(-32, "cannot read stat.");
	if (!(source = ft_strnew(st.st_size)))
		error_callback(-33, "source's malloc failed.");
	if ((ret = read(fd, source, st.st_size)) == -1)
		error_callback(-34, "cannot read shader.");
	close(fd);
	return (source);
}
