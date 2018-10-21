/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 19:04:35 by vdzhanaz          #+#    #+#             */
/*   Updated: 2017/11/01 19:04:36 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	int		i;

	ch = c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return ((char*)(&s[i]));
		i++;
	}
	if (c == '\0')
		return ((char*)(&s[i]));
	else
		return (NULL);
}
