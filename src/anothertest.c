/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anothertest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <vdzhanaz@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 16:20:43 by vdzhanaz          #+#    #+#             */
/*   Updated: 2018/10/19 16:20:44 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include <stdio.h>

int main()
{
	intmax_t val;

	val = -90233;
	// val = (uintmax_t)(val);
	// val = (int)(val);
	// if (val > 0)
		printf("%jD\n", val);
	printf("%+o\n", 9754645);
	return 0;
}