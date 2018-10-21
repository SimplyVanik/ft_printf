/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 12:59:14 by exam              #+#    #+#             */
/*   Updated: 2017/10/13 13:55:31 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	pr_bit(unsigned char c)
{
	char *six;

	six = "0123456789abcdef";
	write(1, &six[c / 16], 1);
	write(1, &six[c % 16], 1);
}

void	pr_mem(char *tt, size_t cur, size_t max)
{
	size_t i;

	i = cur - 1;
	while (++i < cur + 16 && i < max)
	{
		pr_bit(tt[i]);
		if (i % 2)
			write(1, " ", 1);
	}
	while (i < cur + 16)
	{
		write(1, "  ", 2);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
	i = cur - 1;
	while (++i < cur + 16 && i < max)
	{
		if (tt[i] > 31 && tt[i] < 127)
			write(1, &tt[i], 1);
		else
			write(1, ".", 1);
	}
	write(1, "\n", 1);
}

void	print_memory(const void *addr, size_t size)
{
	char	*st;
	size_t	c;

	c = 0;
	st = (char *)addr;
	while (c < size)
	{
		pr_mem(st, c, size);
		c = c + 16;
	}
}
