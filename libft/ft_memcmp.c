/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:38:51 by vdzhanaz          #+#    #+#             */
/*   Updated: 2017/11/06 13:38:53 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*st1;
	unsigned char	*st2;
	size_t			i;

	if (n == 0)
		return (0);
	st1 = (unsigned char*)s1;
	st2 = (unsigned char*)s2;
	i = 0;
	while (i < n && st1[i] == st2[i])
		i++;
	if (i == n)
		return (st1[i - 1] - st2[i - 1]);
	else
		return (st1[i] - st2[i]);
}
