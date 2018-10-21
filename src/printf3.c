/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <vdzhanaz@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 18:29:02 by vdzhanaz          #+#    #+#             */
/*   Updated: 2018/10/21 07:54:49 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int		ft_pars_flg_and_wd(char *format, int i, t_elem *prs)
{
	char	*flags;
	int		j;

	//flags = ft_strnew(5);
	flags = "-+ #0";
	j = -1;
	// while (++k < 5 && j == i)
	// 	if (flags[k] == format[i])
	// 		i++;
	// (*prs)->flg = flags[i];
	while (flags[++j] != '\0')
		if (flags[j] == format[i])
		{
			prs->flg[j] = 1;
			j = -1;
			i++;
		}
	if (format[i] == '*')
		prs->flg[5] = '*';
	else
		prs->wd = ft_atoi(&format[i]);// but need to catch negativ (for example %0-12d, or %01-12d) - it is error
	j = prs->wd * 10;
	if (format[i] == 48)
		i++;
	else
		while (j /= 10 > 0)
			i++;
	return (i);
}

int		ft_pars_accur(char *format, int i, t_elem *prs)
{
	int k;

	if (format[i] == '.')
	{
		prs->flg[6] = 1;
		if (format[++i] == '*')
			prs->flg[6] = '*';
		else
			prs->accur = ft_atoi(&format[i]);//but need to catch negativ - it is error, or two **
		k = prs->accur * 10;
		if (format[i] == 48)
			i++;
		else
			while (k / 10 > 0)
				i++;
	}
	return (i);
}

int		ft_pars_size_and_type(char *format, int i, t_elem *prs)
{
	char	*size;
	int		k;
	int		j;

	//size = ft_strnew(6);
	size = "lhjztL";
	k = -1;
	j = i;
	while (++k < 6 && j == i)
		if (size[k] == format[i])
			i++;
	prs->sz = size[k];
	if (k < 2 && format[i] == format[i - 1])
	{
		(prs->sz)++;
		i++;
	}
	prs->type = format[i];
	return (i);
}

t_elem	*ft_parse(char *format, size_t *i, t_res *res)
{
	t_elem	*prs;
	int		j;
	char	*type;

	prs = ft_memalloc(sizeof(t_elem));//or function new t_elem
	(*i - res->k > res->size - res->l) ? ft_realloc_t_res(res, *i - res->k) : 1;
	res->sym = ft_strncpy(&(res->sym[res->l]), &format[res->k], *i - res->k);
	res->l = res->l + *i - res->k;
	// j = i;
	// k = -1;
	// while (++k < 5 && j == i)
	// 	if (flags[k] == format[i])
	// 		i++;
	// prs->flg = flags[i];
	// if (format[i] == '*')
	// 	prs->wd = -1;
	// else
	// 	prs->wd = ft_atoi(&format[i]);
	// k = prs->wd * 10;
	// if (prs->wd < 0 || (format[i] >= 48 && format[i] < 58)
	// 	i++;
	// else
	// 	while (k / 10 > 0)  
	// 		i++;
	//if (format[i] == '.')
	//type = ft_strnew(23);
	type = "dDioOuUxXcCpfFeEgGaAsSn";
	*i = ft_pars_flg_and_wd(format, ++(*i), prs);
	*i = ft_pars_accur(format, *i, prs);
	*i = ft_pars_size_and_type(format, *i, prs);
	res->k = *i + 1;
	j = 0;
	while (j < 22 && type[j] != prs->type)
		j++;
	(j < 3) ? prs->ttype = 's' : prs->ttype;
	(j >= 3 && j < 12) ? prs->ttype = 'u' : prs->ttype;
	(j >= 12 && j < 20) ? prs->ttype = 'd' : prs->ttype;
	(j >= 20 ) ? prs->ttype = 'c' : prs->ttype;
	(prs->flg[0] == 1 || (prs->flg[6] > 0 && prs->type != 'c' && prs->type != 'C' && prs->ttype != 'c')) ? prs->flg[4] = 0 : prs->flg[4];
	(prs->ttype == 's') ? prs->flg[3] = 0 : prs->flg[3];
	if (prs->ttype == 'u')
	{
		prs->flg[1] = 0;
		prs->flg[2] = 0;
	}
	return (prs);
}

int		ft_printf(const char *format, ...)
{
	size_t	i;
	t_res	res;
	va_list	ap;
	t_elem	*tmp;
	
	va_start(ap, format);
	i = -1;
	res.l = 0;
	res.k = 0;
	res.size = 2048;
	res.sym = ft_strnew(2048);
	while (format[++i] != '\0')
	{
		(format[i] == '%') ? tmp = ft_parse((char*)format, &i, &res) : tmp;
		(tmp->flg[5] == '*') ? tmp->wd = va_arg(ap, int) : tmp->wd;
		(tmp->flg[6] == '*') ? tmp->accur = va_arg(ap, int) : tmp->accur;
		(tmp->ttype == 's' || tmp->ttype == 'u') ? tmp->data = va_arg(ap, intmax_t) : tmp->data;
		//(prs->ttype == "uintmax_t") ? tmp->data = va_arg(ap, uintmax_t) : tmp->data;
		(tmp->ttype == 'd') ? tmp->ldata = va_arg(ap, long double) : tmp->data;
		//(prs->ttype == 'c') ? tmp->data = va_arg(ap, char *) : tmp->data;
		// (prs->ttype == 'w') ? tmp->data = va_arg(ap, wchar_t *) : tmp->data;
		(tmp->type == 'n' || tmp->ttype == 'c') ? tmp->pdata = va_arg(ap, int *) : tmp->pdata;
		i = ft_makeres(tmp, i, (char*)format, &res);
		ft_memdel((void**)(&tmp));
	}
	i = write(1, res.sym, res.l);
	va_end(ap);
	//ft_memdel(&res);
	return (i);
}
