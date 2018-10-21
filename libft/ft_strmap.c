/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:19:54 by vdzhanaz          #+#    #+#             */
/*   Updated: 2017/11/08 18:19:55 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*n;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	n = (char*)malloc(len + 1);
	if (!n)
		return (NULL);
	n[len] = '\0';
	while (len-- > 0)
		n[len] = f(s[len]);
	return (n);
}
