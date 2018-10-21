/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:29:14 by vdzhanaz          #+#    #+#             */
/*   Updated: 2017/11/09 11:29:15 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	sub = ft_strnew(len);
	if (sub)
	{
		i = 0;
		while (i < len && s[i + (size_t)start] != '\0')
		{
			sub[i] = s[i + (size_t)start];
			i++;
		}
	}
	return (sub);
}
