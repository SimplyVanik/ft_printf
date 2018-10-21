/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:20:34 by vdzhanaz          #+#    #+#             */
/*   Updated: 2017/11/06 14:20:35 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;
	size_t			i;

	ch = c;
	str = (unsigned char*)s;
	i = 0;
	while (i < n && str[i] != ch)
		i++;
	if (i == n)
		return (NULL);
	else
		return (&str[i]);
}
