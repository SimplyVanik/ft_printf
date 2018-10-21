/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 20:02:02 by vdzhanaz          #+#    #+#             */
/*   Updated: 2017/11/02 20:02:06 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	ch;
	size_t			i;
	char			*tt;

	i = -1;
	ch = c;
	tt = (char*)b;
	while (++i < len)
		tt[i] = ch;
	return (b);
}
