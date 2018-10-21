/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:28:58 by vdzhanaz          #+#    #+#             */
/*   Updated: 2017/11/09 16:29:00 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		k;
	int		num;
	char	**res;

	if (!s)
		return (NULL);
	i = -1;
	num = 0;
	while (s[++i] != '\0')
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			num++;
	if (!(res = (char**)ft_memalloc(sizeof(char*) * (num + 1))))
		return (NULL);
	while (num-- > 0)
	{
		while (s[--i] == c && i > 0)
			;
		k = i;
		while (--i > -1 && s[i] != c)
			;
		if (!(res[num] = ft_strsub(s, i + 1, (size_t)(k - i))))
			ft_masdel(&res);
	}
	return (res);
}
