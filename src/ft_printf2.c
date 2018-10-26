/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <vdzhanaz@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:41:24 by vdzhanaz          #+#    #+#             */
/*   Updated: 2018/10/26 01:47:17 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_uni_make(t_res *res, size_t *size, int arr)
{
	size_t	j;
	char	tmp;

	tmp = -128;
	res->sym[res->l] = (*size == 1) ? (char)arr : tmp;
	while (--*size > 0)
	{
		tmp /= 2;
		res->sym[res->l] -= tmp;
		res->sym[res->l + *size] = -128;
		j = 1;
		while (j < 33)
		{
			res->sym[res->l + *size] += j * (arr % 2);
			j = j * 2;
			arr = (arr) / 2;
		}
	}
	j = 1;
	while (j < (size_t)-tmp && tmp != -128)
	{
		res->sym[res->l + *size] += j * (arr % 2);
		j = j * 2;
		arr = arr / 2;
	}
}

void	ft_uni(t_res *res, size_t k, t_elem *prs)
{
	size_t	i;
	size_t	size;
	int		arr;

	size = 0;
	i = -1;
	if (prs->type == 'C')
		res->sym[res->l++] = 0;
	while (prs->pdata[++i])
	{
		arr = prs->pdata[i];
		(arr > 65535 && arr < 2097151) ? size = size + 4 : size;
		(arr > 2047 && arr < 65536) ? size = size + 3 : size;
		(arr > 127 && arr < 2048) ? size = size + 2 : size;
		(arr < 128) ? size++ : size;
		if (size <= k)
			k -= size;
		else
			break ;
		ft_uni_make(res, &size, arr);
		res->l += ft_strlen(&(res->sym[res->l]));
	}
}

size_t	ft_get_size(t_elem *prs, int bs, intmax_t data, uintmax_t udata)
{
	size_t	size;

	size = (prs->type == 'S') ? 0 : 1;
	bs = (prs->type == 'x' || prs->type == 'X' || prs->type == 'p') ? 16 : 10;
	bs = (prs->type == 'o' || prs->type == 'O') ? 8 : bs;
	if (prs->ttype == 'u')
		while ((udata = udata / bs) > 0)
			size++;
	else if (prs->ttype == 's' && data < 0)
		while ((data = data / bs) < 0)
			size++;
	while (prs->ttype == 's' && ((data = data / bs) > 0))
		size++;
	bs = -1;
	while (prs->pdata && prs->pdata[++bs])
	{
		(prs->pdata[bs] > 65535 && prs->pdata[bs] < 2097151) ? size = size + 4 :
		size;
		(prs->pdata[bs] > 2047 && prs->pdata[bs] < 65536) ? size = size + 3 :
		size;
		(prs->pdata[bs] > 127 && prs->pdata[bs] < 2048) ? size = size + 2 :
		size;
		(prs->pdata[bs] < 128) ? size++ : size;
	}
	return (size);
}

void	ft_itoa_baseu(t_elem *tmp, t_res *res, int size, int type)
{
	char	*tab;

	tab = (tmp->type == 'X') ? ft_strdup("0123456789ABCDEF") :
	ft_strdup("0123456789abcdef");
	size = (tmp->acc > (int)(size)) ? tmp->acc : size;
	type = (tmp->type == 'o' || tmp->type == 'O') ? 8 : 10;
	if (tmp->type == 'x' || tmp->type == 'X' || tmp->type == 'p')
		type = 16;
	if (tmp->data < 0)
	{
		size--;
		res->sym[res->l + size] = tab[(-1 * ((tmp->data) % 10))];
		(tmp->data) = (tmp->data) / (-10);
	}
	while (tmp->ttype == 's' && size-- > 0)
	{
		res->sym[res->l + size] = tab[(tmp->data) % type];
		(tmp->data) = (tmp->data) / type;
	}
	while (tmp->ttype == 'u' && size-- > 0)
	{
		res->sym[res->l + size] = tab[(tmp->udata) % type];
		(tmp->udata) = (tmp->udata) / type;
	}
	ft_strdel(&tab);
}

void	ft_pointer(t_res *res, t_elem *prs)
{
	void *n;

	n = va_arg(res->ap, void*);
	if (prs->sz[0] == 1)
		*((__int64_t*)n) = (__int64_t)(res->l);
	else if (prs->sz[1] == 1)
		*((intmax_t*)n) = (intmax_t)(res->l);
	else if (prs->sz[2] == 1 || prs->sz[3] == 1)
		*((ssize_t*)n) = (res->l);
	else if (prs->sz[4] == 1)
		*((long long*)n) = (long long)(res->l);
	else if (prs->sz[5] == 1)
		*((long*)n) = (long)(res->l);
	else if (prs->sz[6] == 1)
		*((short*)n) = (short)(res->l);
	else if (prs->sz[7] == 1)
		*((char*)n) = (char)(res->l);
	else
		*((int*)n) = (int)(res->l);
}
