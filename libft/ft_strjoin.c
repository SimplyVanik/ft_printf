/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:48:43 by vdzhanaz          #+#    #+#             */
/*   Updated: 2017/11/09 12:48:45 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*joy;

	if (!s1 && !s2)
		return (NULL);
	if (s1 && !s2)
		return ((char*)s1);
	if (!s1 && s2)
		return ((char*)s2);
	len = ft_strlen(s1) + ft_strlen(s2);
	joy = ft_strnew(len);
	if (joy && len > 0)
	{
		while (len-- > ft_strlen(s1))
			joy[len] = s2[len - ft_strlen(s1)];
		len++;
		while (len-- > 0)
			joy[len] = s1[len];
	}
	return (joy);
}
