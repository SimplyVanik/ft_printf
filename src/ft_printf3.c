/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <vdzhanaz@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:43:06 by vdzhanaz          #+#    #+#             */
/*   Updated: 2018/10/26 01:50:47 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_makeres(t_elem *prs, t_res *res, int j, int size)
{
	((prs->flg[3] == 1 && (prs->type == 'x' || prs->type == 'X')) ||
	prs->type == 'p') ? prs->wd = prs->wd - 2 : prs->wd;
	if (((prs->flg[2] || prs->flg[1]) && prs->data >= 0) || prs->data < 0)
		prs->wd--;
	while (prs->flg[4] == 0 && (prs->wd)-- > (int)size && prs->wd >= prs->acc)
		res->sym[(res->l)++] = ' ';
	if ((prs->flg[2] == 1 || prs->flg[1] == 1) && prs->data >= 0 &&
	prs->ttype == 's')
		res->sym[(res->l)++] = (prs->flg[1] == 0) ? ' ' : '+';
	if (prs->data < 0)
		res->sym[(res->l)++] = '-';
	if ((prs->flg[3] && (prs->type == 'x' || prs->type == 'X')) || j == 9)
	{
		res->sym[(res->l)++] = '0';
		res->sym[(res->l)++] = (prs->type == 'p') ? 'x' : prs->type;
	}
	while (prs->flg[4] == 1 && (prs->wd)-- > (int)size && prs->wd >= prs->acc)
		res->sym[(res->l)++] = '0';
	if ((prs->ttype == 's' || prs->ttype == 'u') && size != 0)
		ft_itoa_baseu(prs, res, size, j);
	if (prs->type == 's')
		ft_strncpy(&(res->sym[res->l]), prs->tdata, size);
	(prs->type == 'c') ? res->sym[res->l++] = prs->udata : res->sym[res->l];
	(prs->type == 'S' || prs->type == 'C') ? ft_uni(res, (size_t)size, prs) : 1;
	(prs->type == 'n') ? ft_pointer(res, prs) : 1;
}

size_t	ft_wch_format(t_elem *prs, size_t size)
{
	size_t	lsize;
	size_t	i;
	size_t	tmp;

	lsize = (prs->flg[5] == 1) ? 0 : size;
	i = -1;
	tmp = 0;
	if (prs->type == 'S' && prs->pdata == NULL)
		prs->type = 's';
	if (prs->type == 's' && prs->tdata == NULL)
		prs->tdata = "(null)";
	if (prs->flg[5] == 1 && prs->type == 'S')
		while (prs->pdata[++i] && (lsize + tmp) <= (size_t)prs->acc)
		{
			tmp = (prs->pdata[i] < 128) ? 1 : tmp;
			tmp = (prs->pdata[i] > 127 && prs->pdata[i] < 2048) ? 2 : tmp;
			tmp = (prs->pdata[i] > 2047 && prs->pdata[i] < 65536) ? 3 : tmp;
			tmp = (prs->pdata[i] > 65535 && prs->pdata[i] < 2097151) ? 4 : tmp;
			lsize = ((lsize + tmp) <= (size_t)prs->acc) ? lsize + tmp : lsize;
		}
	lsize = (prs->type == 's') ? (ft_strlen(prs->tdata)) : lsize;
	lsize = (prs->type == 's' && prs->flg[5] > 0 && prs->acc < (int)lsize) ?
	prs->acc : lsize;
	return (lsize);
}

void	ft_formating(t_elem *prs, t_res *res, int j)
{
	size_t	size;
	int		msize;

	prs->flg[1] = (prs->ttype == 'u') ? 0 : prs->flg[1];
	prs->flg[2] = (prs->ttype == 'u') ? 0 : prs->flg[2];
	if (prs->flg[0] == 1 || (prs->flg[5] > 0 && j < 10))
		prs->flg[4] = 0;
	(prs->ttype == 's' || (prs->udata == 0 && !(prs->flg[5] && prs->acc == 0 &&
	(prs->type == 'o' || prs->type == 'O')))) ? prs->flg[3] = 0 : prs->flg[3];
	size = (prs->type == 'S' || prs->type == 'C' || prs->ttype == 's' ||
	prs->ttype == 'u') ? ft_get_size(prs, j, prs->data, prs->udata) : 1;
	if (prs->type == 'S' || prs->type == 's')
		size = ft_wch_format(prs, size);
	size = (prs->flg[5] && prs->acc == 0 && prs->udata == 0 &&
	prs->type != 'c' && prs->data == 0) ? 0 : size;
	if (prs->flg[3] && (prs->type == 'o' || prs->type == 'O'))
		size++;
	prs->acc = ((prs->type == 's' || prs->type == 'S' || prs->type == 'c')
	&& prs->flg[5] > 0 && prs->acc > (int)size) ? (int)size : prs->acc;
	msize = (prs->acc > (int)size) ? prs->acc : (int)size;
	msize = (prs->wd > msize) ? prs->wd : msize;
	(msize > (int)(res->size - res->l)) ? ft_realloc_t_res(res, msize) : msize;
	while (prs->flg[0] == 1 && (prs->wd)-- > (int)size && prs->wd >= prs->acc)
		res->sym[res->l + prs->wd] = ' ';
	ft_makeres(prs, res, j, size);
}

void	ft_cast_size(t_elem *prs, int i)
{
	i = 0;
	while (i < 8 && prs->sz[i] != 1)
		i++;
	if (prs->ttype == 's')
	{
		(i == 5) ? prs->data = (long)(prs->data) : prs->data;
		(i == 0) ? prs->data = (__int64_t)(prs->data) : prs->data;
		(i == 2 || i == 3) ? prs->data = (ssize_t)(prs->data) : prs->data;
		(i == 4) ? prs->data = (long long)(prs->data) : prs->data;
		(i == 8) ? prs->data = (int)(prs->data) : prs->data;
		(i == 6) ? prs->data = (short)(prs->data) : prs->data;
		(i == 7) ? prs->data = (char)(prs->data) : prs->data;
	}
	if ((prs->ttype == 'u' || prs->type == 'c') && prs->type != 'p')
	{
		(i == 0) ? prs->udata = (__uint64_t)(prs->udata) : prs->udata;
		(i == 2 || i == 3) ? prs->udata = (size_t)(prs->udata) : prs->udata;
		(i == 4) ? prs->udata = (unsigned long long)(prs->udata) : prs->udata;
		(i == 5) ? prs->udata = (unsigned long)(prs->udata) : prs->udata;
		(i == 8) ? prs->udata = (unsigned)(prs->udata) : prs->udata;
		(i == 6) ? prs->udata = (unsigned short)(prs->udata) : prs->udata;
		(i == 7 || prs->type == 'c') ? prs->udata = (unsigned char)(prs->udata)
		: prs->udata;
	}
	(prs->sz[0] == 1) ? prs->ldata = (double)(prs->ldata) : prs->ldata;
}

void	ft_get_data(t_elem *prs, t_res *res, int j)
{
	char	*type;

	j = 0;
	type = "idDOUouxXpcCSfFeEgGaAsn";
	while (type[j] != '\0' && type[j] != prs->type)
		j++;
	(j < 3) ? prs->ttype = 's' : prs->ttype;
	(j >= 3 && j < 10) ? prs->ttype = 'u' : prs->ttype;
	(j >= 11 && j < 19) ? prs->ttype = 'd' : prs->ttype;
	(prs->arg_num > 0) ? va_copy(res->ap, res->list) : res->ap;
	while (--(prs->arg_num) > 0)
		va_arg(res->ap, int*);
	prs->data = (j < 3) ? va_arg(res->ap, intmax_t) : prs->data;
	prs->udata = (j > 2 && j < 11) ? va_arg(res->ap, uintmax_t) : prs->udata;
	prs->data = (j == 11) ? va_arg(res->ap, wchar_t) : prs->data;
	prs->pdata = (j == 12) ? va_arg(res->ap, wchar_t*) : prs->pdata;
	prs->ldata = (j > 12 && j < 21) ? va_arg(res->ap, long double) : 0;
	prs->tdata = (prs->type == 's') ? va_arg(res->ap, char*) : prs->tdata;
	prs->udata = (type[j] == '\0') ? prs->type : prs->udata;
	prs->type = (type[j] == '\0') ? 'c' : prs->type;
	prs->pdata = (prs->type == 'C') ? (wchar_t*)(&prs->data) : prs->pdata;
	prs->type = (prs->type == 'C' && prs->data != 0) ? 'S' : prs->type;
	prs->sz[5] = (j > 1 && j < 5) ? 1 : prs->sz[5];
	ft_cast_size(prs, j);
	ft_formating(prs, res, j);
}
