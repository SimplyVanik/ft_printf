/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:13:26 by vdzhanaz          #+#    #+#             */
/*   Updated: 2017/11/10 13:13:28 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	getsize(int n)
{
	size_t	size;

	size = 1;
	if (n < 0)
	{
		size++;
		n = n / (-10);
		if (n > 0)
			size++;
	}
	while (n > 9)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	size_t	size;
	char	*num;

	size = getsize(n);
	num = ft_strnew(size);
	if (num)
	{
		if (n < 0)
		{
			num[0] = '-';
			size--;
			num[size] = -1 * (n % 10) + 48;
			n = n / (-10);
		}
		while (size-- > 0 && num[size] == '\0')
		{
			num[size] = (n % 10) + 48;
			n = n / 10;
		}
	}
	return (num);
}
