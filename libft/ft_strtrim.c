/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:20:11 by vdzhanaz          #+#    #+#             */
/*   Updated: 2017/11/09 15:20:12 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	bg;
	char	*tr;

	tr = NULL;
	if (s)
	{
		len = ft_strlen(s) - 1;
		bg = 0;
		while ((s[bg] == ' ' || s[bg] == '\n' || s[bg] == '\t') && bg <= len)
			bg++;
		while ((s[len] == ' ' || s[len] == '\n' || s[len] == '\t') && len >= bg)
			len--;
		tr = ft_strsub(s, (unsigned int)bg, len - bg + 1);
	}
	return (tr);
}
