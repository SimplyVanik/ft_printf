/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:52:29 by vdzhanaz          #+#    #+#             */
/*   Updated: 2017/10/30 15:52:33 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*t1;
	unsigned char	*t2;

	if (n == 0)
		return (0);
	t1 = (unsigned char*)s1;
	t2 = (unsigned char*)s2;
	i = 0;
	while (t1[i] != '\0' && t2[i] != '\0' && t1[i] == t2[i] && i < n)
		i++;
	if (i < n)
		return (t1[i] - t2[i]);
	else
		return (t1[i - 1] - t2[i - 1]);
}
