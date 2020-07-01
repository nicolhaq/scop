/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 09:49:34 by nhaquet           #+#    #+#             */
/*   Updated: 2020/07/01 11:20:56 by grolash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t num)
{
	unsigned char	*temp;

	temp = (unsigned char*)str;
	while (num--)
	{
		*temp++ = (unsigned char)c;
	}
	return (str);
}
