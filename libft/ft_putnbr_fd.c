/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:05:12 by vdzhanaz          #+#    #+#             */
/*   Updated: 2017/11/13 17:05:14 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	buf;
	int r;

	r = 1;
	buf = n;
	while (buf > 9 || buf < -9)
	{
		buf = buf / 10;
		r = r * 10;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd(-1 * (n / r) + 48, fd);
		n = -1 * (n % r);
		r = r / 10;
	}
	while (r > 0)
	{
		ft_putchar_fd(n / r + 48, fd);
		n = n % r;
		r = r / 10;
	}
}
