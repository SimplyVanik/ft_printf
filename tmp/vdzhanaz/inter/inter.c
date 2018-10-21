/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 10:34:10 by exam              #+#    #+#             */
/*   Updated: 2017/10/13 11:05:04 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	check(char c, char *st)
{
	int k;

	k = 0;
	while (st[k] != '\0')
	{
		if (st[k] == c)
		{
			write(1, &c, 1);
			break ;
		}
		k++;
	}
}

int		main(int ac, char **av)
{
	int i;
	int j;

	if (ac == 3)
	{
		i = 0;
		while (av[1][i] != '\0')
		{
			j = -1;
			while (++j < i)
				if (av[1][j] == av[1][i])
					j = i + 1;
			if (i == j)
				check(av[1][i], av[2]);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
