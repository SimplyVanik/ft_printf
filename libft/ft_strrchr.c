/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 19:26:46 by vdzhanaz          #+#    #+#             */
/*   Updated: 2017/11/01 19:26:48 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	int		i;

	ch = c;
	i = ft_strlen((char*)(s));
	while (i >= 0)
	{
		if (s[i] == ch)
			return ((char*)(&s[i]));
		i--;
	}
	return (NULL);
}
