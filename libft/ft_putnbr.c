/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:35:52 by vdzhanaz          #+#    #+#             */
/*   Updated: 2017/11/13 13:35:53 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
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
		ft_putchar('-');
		ft_putchar(-1 * (n / r) + 48);
		n = -1 * (n % r);
		r = r / 10;
	}
	while (r > 0)
	{
		ft_putchar(n / r + 48);
		n = n % r;
		r = r / 10;
	}
}
