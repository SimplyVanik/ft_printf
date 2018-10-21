/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:39:20 by vdzhanaz          #+#    #+#             */
/*   Updated: 2017/11/08 18:39:22 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*n;

	n = NULL;
	if (s && f)
	{
		len = ft_strlen(s);
		n = (char*)malloc(len + 1);
		if (!n)
			return (NULL);
		n[len] = '\0';
		while (len-- > 0)
			n[len] = f((unsigned int)len, s[len]);
	}
	return (n);
}
