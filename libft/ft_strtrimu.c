/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:08:24 by vdzhanaz          #+#    #+#             */
/*   Updated: 2017/11/21 15:08:26 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimu(char const *s, char c)
{
	size_t	len;
	size_t	bg;
	char	*tr;

	tr = NULL;
	if (s)
	{
		len = ft_strlen(s) - 1;
		bg = 0;
		while (s[bg] == c && bg <= len)
			bg++;
		while (s[len] == c && len >= bg)
			len--;
		tr = ft_strsub(s, (unsigned int)bg, len - bg + 1);
	}
	return (tr);
}
