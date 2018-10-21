/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:42:41 by vdzhanaz          #+#    #+#             */
/*   Updated: 2017/11/14 13:42:41 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	if (s1 && s2 && n > 0)
	{
		i = 0;
		while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n)
			i++;
		if ((i < n && (s1[i] - s2[i] == 0)) ||
			(i == n && (s1[i - 1] - s2[i - 1] == 0)))
			return (1);
		else
			return (0);
	}
	else if ((!s1 ^ !s2) && n > 0)
		return (0);
	else
		return (1);
}
