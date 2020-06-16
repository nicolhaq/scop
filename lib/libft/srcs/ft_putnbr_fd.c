/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grolash <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 01:10:46 by grolash           #+#    #+#             */
/*   Updated: 2020/06/16 14:54:01 by grolash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int const fd, int n)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
			write(1, "2147483648", 10);
		else
			ft_putnbr_fd(-n, fd);
	}
	else if (n < 10)
	{
		n = n + 48;
		write(fd, &n, 1);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
