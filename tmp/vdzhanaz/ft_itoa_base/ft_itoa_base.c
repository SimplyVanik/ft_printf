/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 14:22:20 by exam              #+#    #+#             */
/*   Updated: 2017/10/13 16:03:43 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		stsize(int value, int base)
{
	int size;

	size = 1;
	while (value >= base)
	{
		size++;
		value = value / base;
	}
	return (size);
}

char	*ft_itoa_base(int value, int base)
{
	int		size;
	char	*res;
	char	*tab;

	tab = "0123456789ABCDEF";
	if (value < 0)
		size = stsize(value / (-10), base) + 2;
	else
		size = stsize(value, base);
	res = (char *)malloc(sizeof(char) * (size + 1));
	res[size] = '\0';
	if (value < 0)
	{
		res[0] = '-';
		size--;
		res[size] = tab[(-1 * (value % 10))];
		value = value / (-10);
	}
	while (--size > 0 && value > base)
	{
		res[size] = tab[value % base];
		value = value / base;
	}
	res[size] = tab[value];
	return (res);
}
