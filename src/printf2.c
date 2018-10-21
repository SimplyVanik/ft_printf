/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <vdzhanaz@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 16:23:06 by vdzhanaz          #+#    #+#             */
/*   Updated: 2018/10/09 15:50:45 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_get_size(intmax_t value, char type, char ttype)
{
	size_t		size;
	intmax_t	tmp;
	
	tmp = value;
	size = 1;
	(type == 'c') ? return (1) : type;
	//(type == 'C') ? return (ft_ucode_sz(&value)) : type;
	(ttype == 'u') ? (unsigned)tmp : tmp;
	//(type == 'p') ? size = 3 : size = 1;
	(type == 'p') ? tp = 16 : tp;

	if (tmp < 0)
	{
		//size++;
		while ((tmp / 10) < 0);
			size++;
	}
	if (type == 'D' || type == 'd' || type == 'i' || type == 'U' || type == 'u')
		tp = 10;
	(type == 'o' || type == 'O') ? type = 8 : type;
	(type == 'x' || type == 'X') ? type = 16 : type;
	while ((tmp / type) > 0)
		size++;
	
	return (size);
}

size_t	ft_ucode_sz(void *data)
{
	size_t	size;
	size_t	i;
	wchar_t	*arr;

	i = 0;
	size = 0;
	arr = (w_char *)(data);
	while (arr[i])
	{
		(arr[i] >65535 && arr[i] < 2097151) ? size = size + 4 : size;
		(arr[i] > 2047 && arr[i] < 65536) ? size = size + 3 : size;
		(arr[i] > 127 && arr[i] < 2048) ? size = size + 2 : size;
		(arr[i] < 128) ? size++ : size;
		i++;
	}
	return (size);
}

// {
// 	if (p->ttype == 's' || p->ttype == 'u')
// 	{
// 		size = ft_get_size(*(p->data), p->type, p->ttype);
// 		if ()
// 		// if ((p->flg[1] == 1 || p->flg[2] == 1) && p->ttype == 's' && *(p->data)
// 		// 	>= 0 || (p->flg[3] == 1 && (p->type == 'o' || p->type == 'O')))
// 		// 	size++;
// 		// if ((p->type == 'X' || p->type == 'x') && p->flg[3] == 1)
// 		// 	size = size + 2;
// 		// (p->flg[6] > 0 && p->accur > size && p->type != 'p' && p->type != 'c'
// 		// 	 && p->type != 'C') ? size = p->accur : size;
// 		// (p->flg[5] > 0 && p->flg[6] == 0 && p->wd > size) ? size = p->wd : size;
// 	}
// }

size_t	*ft_set_size(t_elem *p)
{
	size_t	size;

	if ((p->ttype == 's' || p->ttype == 'u') && p->type != 'C')
	{
		size = ft_get_size(*(p->data), p->type, p->ttype);
		(p->flg[3] == 1 && p->type = 'o') ? size++ : size;
		(p->accur > size && p->type != 'c') ? size = p->accur : 1;
		(p->flg[1] == 1 || p->flg[2] == 1 || *(p->data) < 0) ? p->wd-- : 1;
		(p->flg[3] == 1 && (p->type = 'x' || p->type = 'X')) ? p->wd = p->wd - 2 : 1;
		(p->flg[4] == 1 && p->wd > size && p->type != 'c') ? size = p->wd : 1;
		// if ((p->flg[1] == 1 || p->flg[2] == 1) && p->ttype == 's' && *(p->data)
		// 	>= 0 || (p->flg[3] == 1 && (p->type == 'o' || p->type == 'O')))
		// 	size[1] = size[0] + 1;
		// if ((p->type == 'X' || p->type == 'x') && p->flg[3] == 1)
		// 	size[1] = size[0] + 2;
		// (p->flg[6] > 0 && p->accur > size && p->type != 'p' && p->type != 'c'
		// 	 && p->type != 'C') ? size = p->accur : size;
		// (p->flg[5] > 0 && p->flg[6] == 0 && p->wd > size) ? size = p->wd : size;
	}
	// (p->type == 'c') ? size = 1; size;
	if (p->ttype == 'c')
	{
		(p->data == NULL) ? p->data = "(null)" : p->data;
		((p->type == 'S' || p->sz == 'l') && !ft_strequ(p->data, "(null)")) ? size = ft_ucode_sz(p->data) : size = ft_strlen((char *)(p->data));
		
		//size = ft_strlen((char *)(p->data));

		(p->flg[6] > 0 && p->accur < size) ? size = p->accur : size;
	}
	// if (p->type == 's' && p->data == NULL && p->sz != 'l')
	// {
	// 	size = 6;
	// 	p->data = "(null)";
	// }
	(p->type == 'C' || (p->sz == 'l' && tel->type = 'c')) ? size = ft_ucode_sz(p->data) : type;
	//(p->ttype == 'd') ? size = ft_flt_point_sz(p) : size;
	return (size);
}