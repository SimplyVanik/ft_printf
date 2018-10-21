/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 22:43:01 by vdzhanaz          #+#    #+#             */
/*   Updated: 2017/10/30 22:43:04 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		if (haystack[i] == needle[j])
			while (haystack[i + j] == needle[j] && haystack[i + j] != '\0'
				&& needle[j] != '\0')
				j++;
		if (needle[j] == '\0')
			return ((char*)(&haystack[i]));
		i++;
	}
	return (NULL);
}
