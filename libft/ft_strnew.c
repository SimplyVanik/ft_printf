/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:55:34 by vdzhanaz          #+#    #+#             */
/*   Updated: 2017/11/08 13:55:41 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	new = NULL;
	new = (char*)malloc(size + 1);
	if (new)
	{
		i = -1;
		while (++i <= size)
			new[i] = '\0';
	}
	return (new);
}
