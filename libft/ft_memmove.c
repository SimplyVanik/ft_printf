/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 16:55:03 by vdzhanaz          #+#    #+#             */
/*   Updated: 2017/11/03 16:55:05 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	if (dst > src)
		while (len-- > 0)
			d[len] = s[len];
	else
	{
		i = -1;
		while (++i < len)
			d[i] = s[i];
	}
	return (dst);
}
