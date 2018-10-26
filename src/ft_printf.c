/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <vdzhanaz@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 20:17:50 by vdzhanaz          #+#    #+#             */
/*   Updated: 2018/10/26 01:20:36 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

size_t	ft_parse(char *ft, size_t i, t_res *res, size_t j)
{
	t_elem	*prs;

	prs = ft_memalloc(sizeof(t_elem));
	ft_bzero(prs, sizeof(*prs));
	(i - j + 1 > res->size - res->l) ? ft_realloc_t_res(res, i - j) : 1;
	ft_strncpy(&(res->sym[res->l]), &ft[j], i - j);
	res->l = res->l + i - j;
	while (ft[++i] != '\0' && ft[i] != '%' &&
	!(ft_isalpha(ft[i]) && !(ft[i] == 'l' || ft[i] == 'h' || ft[i] == 'z' ||
	ft[i] == 'L' || ft[i] == 'j' || ft[i] == 't')))
	{
		j = i;
		i = ft_pars_flg_and_size(ft, i, prs);
		i = ft_pars_wd_and_acc(ft, i, prs, res);
		if (i < j)
			break ;
	}
	(i >= j) ? prs->type = ft[i] : prs->type;
	(ft[i] != '\0') ? i++ : i;
	prs->type = (prs->type == 's' && prs->sz[5] == 1) ? 'S' : prs->type;
	prs->type = (prs->type == 'c' && prs->sz[5] == 1) ? 'C' : prs->type;
	if ((ft_isalpha(prs->type) || prs->type == '%'))
		ft_get_data(prs, res, i);
	ft_memdel((void**)(&prs));
	return (i);
}

int		ft_printf(const char *format, ...)
{
	size_t		i;
	size_t		j;
	t_res		res;

	ft_bzero(&res, sizeof(res));
	va_start(res.ap, format);
	i = 0;
	j = 0;
	res.size = 2048;
	res.sym = ft_strnew(2048);
	va_copy(res.list, res.ap);
	while (format[i] != '\0')
		if (format[i++] == '%')
		{
			i = ft_parse((char*)(format), i - 1, &res, j);
			j = i;
			res.l = res.l + ft_strlen(&(res.sym[res.l]));
		}
	(i - j > res.size - res.l) ? ft_realloc_t_res(&res, i - j) : 1;
	ft_strncpy(&(res.sym[res.l]), &format[j], i - j);
	res.l = res.l + i - j;
	i = write(1, res.sym, res.l);
	va_end(res.ap);
	ft_strdel(&(res.sym));
	return (i);
}
