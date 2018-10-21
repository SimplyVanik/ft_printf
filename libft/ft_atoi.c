/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:34:40 by vdzhanaz          #+#    #+#             */
/*   Updated: 2017/11/20 19:34:56 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	long long	res;
	int			flag;

	i = -1;
	res = 0;
	flag = -1;
	while (str[i + 1] == ' ' || (str[i + 1] > 8 && str[i + 1] < 14))
		i++;
	if (str[i + 1] == '-' || str[i + 1] == '+')
	{
		i++;
		if (str[i] == '-')
			flag = 0;
	}
	while (str[++i] > 47 && str[i] < 58)
	{
		if (res <= MAX / 10 && (MAX - res * 10 - (str[i] - 48)) >= 0)
			res = res * 10 + (str[i] - 48);
		else
			return (flag);
	}
	if (flag == 0)
		return ((int)(-1 * res));
	return ((int)res);
}
