/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 21:36:27 by vdzhanaz          #+#    #+#             */
/*   Updated: 2017/11/06 21:36:59 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*st;
	void	*new;
	size_t	i;

	new = malloc(size);
	if (new)
	{
		st = (char*)new;
		i = -1;
		while (++i < size)
			st[i] = 0;
		return (new);
	}
	else
		return (NULL);
}
