/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_alpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 10:08:35 by exam              #+#    #+#             */
/*   Updated: 2017/10/13 10:11:59 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(void)
{
	int		i;
	char	c;

	i = 0;
	while (i < 26)
	{
		if (i % 2 == 0)
			c = i + 97;
		else
			c = i + 65;
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}