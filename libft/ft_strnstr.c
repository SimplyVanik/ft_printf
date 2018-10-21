/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:48:45 by vdzhanaz          #+#    #+#             */
/*   Updated: 2017/11/01 16:48:49 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *nl, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (nl[i] == '\0')
		return ((char*)hs);
	while (hs[i] != '\0' && i < len)
	{
		j = 0;
		if (hs[i] == nl[j])
			while (hs[i + j] == nl[j] && hs[i + j] != '\0'
				&& nl[j] != '\0' && i + j < len)
				j++;
		if (nl[j] == '\0')
			return ((char*)(&hs[i]));
		i++;
	}
	return (NULL);
}
