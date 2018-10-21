/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <vdzhanaz@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 20:17:50 by vdzhanaz          #+#    #+#             */
/*   Updated: 2018/10/21 08:02:29 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_get_nxt(t_elem *prs, t_res *res, char *ft, size_t *i)
{
	int		j;
	int		rez;
	va_list tmp;

	//(*i)++;
	rez = 0;
	va_copy(tmp, res->list);
	j = ft_atoi(&ft[++(*i)]);
	while (ft[*i] > 47 && ft[*i] < 58)
		(*i)++;
	if (ft[*i] != '$')
	{
		rez = va_arg(res->ap, int);
		while (ft[*i - 1] != '*')
			(*i)--;
	}
	else
		while (j-- > 0)
			rez = va_arg(tmp, int);
	if (rez < 0)
	{
		prs->flg[0] = 1;
		rez = -rez;
	}
	(ft[*i] == '$') ? (*i)++ : *i;
	return (rez);
}

void	ft_realloc_t_res(t_res *res, size_t len)
{
	char	*new;

	while (res->size - res->l > 2 * len)
		res->size = res->size + res->size / 2 + 1;
	new = ft_strnew(res->size);
	new = ft_strncpy(new, res->sym, res->l);
	ft_strdel(&(res->sym));
	res->sym = new;
}

size_t	ft_pars_wd_and_acc(char *ft, size_t i, t_elem *prs, t_res *res)
{
	int j;

	j = 0;
	if (ft[i] > 48 && ft[i] < 58)
	{
		j = ft_atoi(&ft[i]);
		while (ft[i] > 47 && ft[i] < 58)
			i++;
		if (ft[i] != '$')
			prs->wd = j;
		else
			prs->arg_num = j;
		(ft[i] == '$') ? i++ : i;
	}
	if (ft[i] == '*')
		prs->wd = ft_get_nxt(prs, res, ft, &i);
	if (ft[i] == '.')
	{
		prs->flg[5] = 1;
		j = ft_atoi(&ft[++i]);
		prs->acc = (ft[i] > 47 && ft[i] < 58) ? j : 0;
		if (ft[i] == '*')
			prs->acc = ft_get_nxt(prs, res, ft, &i);
		if (ft[i - 1] != '*')
			while (ft[i] > 47 && ft[i] < 58)
				i++;
	}
	return (i);
}

	
// 	if (ft[i] == '*')
// 	{
// 		j = ft_atoi(&ft[++i]);
// 		while (ft[i] > 47 && ft[i] < 58)
// 			i++;
// 		if (ft[i] != '$')
// 		{	
// 			prs->wd = va_arg(ap, int);
// 			while (ft[i] != '*')
// 				i--;
// 		}
// 		else
// 			ft_();
// 		// if (j == 0 && ft[i] == '$')
// 		// 	i++;
// 		// if ((ft[++i] < 48 || ft[i] > 57) && ft[i] != '$')
// 		// 	prs->wd = va_arg(ap, int);
// 		// else
// 		// {
// 		// 	j = ft_atoi(&ft[i]);
// 		// 	while (ft[i] > 47 && ft[i] < 58)
// 		// 		i++;
// 		// 	if (j == 0 && ft[i] == '$')
// 		// 		i++;
// 		// 	else if (j != 0 && ft[i] == '$')
// 		// 		i = ft_();
// 		// 	else
// 		// 	{	
// 		// 		prs->wd = va_arg(ap, int);
// 		// 		while (ft[i] != '*')
// 		// 			i--;
// 		// 	}
// 		// }
// 	}
// 	if (ft[i] == '.')
// 		ft_();
// 	return ((ft[i] == '$' || ft[i] == '*' || ft[i] == '.') ? i++ : i);
// }

size_t	ft_pars_flg_and_size(char *ft, size_t i, t_elem *prs)
{
	char	*flags_and_sizes;
	size_t	j;

	flags_and_sizes = "-+ #0Ljztlh";
	j = -1;
	while (flags_and_sizes[++j] != '\0' && ft[i] != '\0')
		if (flags_and_sizes[j] == ft[i])
		{
			if (j < 5)
				prs->flg[j] = 1;
			else if (ft[i + 1] != ft[i] && (ft[i] == 'l' || ft[i] == 'h'))
				prs->sz[j - 4] = 1;
			else if (ft[i] == 'h' && ft[i + 1] == 'h')
				prs->sz[j - 3] = 1;
			// else if (ft[i + 1] == ft[i] && (ft[i] == 'l' || ft[i] == 'h'))
			// {	
			// 	prs->sz[j - 3] = 1;
			// 	i++;
			// }
			else
				prs->sz[j - 5] = 1;
			j = -1;
			if (ft[i + 1] == ft[i])
				i++;
			i++;
		}
	return (i);
}

size_t	ft_get_size(t_elem *prs, int bs, intmax_t data, uintmax_t udata)
{
	size_t	size;

	(prs->type == 'S' || prs->type == 'C') ? size = 0 : 1;
	(prs->type == 'x' || prs->type == 'X' || prs->type == 'p') ? bs = 16 : 10;
	(prs->type == 'o' || prs->type == 'O') ? bs = 8 : bs;
	if (prs->ttype == 'u')
		while ((udata = udata / bs) > 0)
			size++;
	else if (data < 0)
		while ((data = data / bs) < 0)
			size++;
	while ((data = data / bs) > 0)
		size++;
	bs = -1;
	while (prs->pdata[++bs])
	{
		(prs->pdata[bs] >65535 && prs->pdata[bs] < 2097151) ? size = size + 4 :
		size;
		(prs->pdata[bs] > 2047 && prs->pdata[bs] < 65536) ? size = size + 3 :
		size;
		(prs->pdata[bs] > 127 && prs->pdata[bs] < 2048) ? size = size + 2 :
		size;
		(prs->pdata[bs] < 128) ? size++ : size;
	}
	return (size);
}

void	ft_makeres(t_elem *prs, t_res *res, int j, size_t size)
{
	char sym;

	(prs->flg[4] == 1) ? sym = '0' : ' ';
	(size > res->size - res->l) ? ft_realloc_t_res(res, size) : size;
	// (prs->flg[2] == 1) ? res->sym[++(res->l)] = ' ' : res->sym[(res->l)];
	if (prs->flg[2] == 1)
		res->sym[(res->l)++] = ' ';
	if (prs->flg[0] == 1)
		while (--(prs->wd) > size)
			res->sym[res->l + prs->wd + 1] = sym;
	while ((prs->wd)-- > size)
		res->sym[(res->l)++] = sym;
	if 	(prs->flg[3] == 1 && (prs->type == 'x' || prs->type == 'X'))
	{
		res->sym[(res->l)++] = '0';
		res->sym[(res->l)++] = prs->type;
	}
}

void	ft_formating(t_elem *prs, t_res *res, int j)
{
	size_t	size;

	// if (prs->ttype == 'u')
	// {
	// 	prs->flg[1] = 0;
	// 	prs->flg[2] = 0;
	// }
	(prs->tdata == NULL) ? prs->tdata = "(null)" : prs->tdata;
	(prs->ttype == 'u') ? prs->flg[1] = 0 : prs->flg[1];
	(prs->ttype == 'u') ? prs->flg[2] = 0 : prs->flg[2];
	// (prs->flg[0] == 1 || (prs->flg[6] > 0 && j < 10)) ? prs->flg[4] = 0 : prs->flg[4];
	if (prs->flg[0] == 1 || (prs->flg[6] > 0 && j < 10))
		prs->flg[4] = 0;
	(prs->ttype == 's') ? prs->flg[3] = 0 : prs->flg[3];
	if (prs->flg[3] == 1 && (prs->type == 'x' || prs->type == 'X'))
		prs->wd = prs->wd - 2;
	// (prs->type == 'S' || prs->type == 'C') ? size = ft_ucode_sz(prs) : 1;
	(prs->type == 's') ? size = ft_strlen(prs->tdata) : 1;
	(prs->type == 'S' || prs->type == 'C' || prs->ttype == 's' || prs->ttype ==
	'u') ? size = ft_get_size(prs, j, prs->data, prs->udata) : size;
	// (prs->flg[3] == 1 && (prs->type == 'o' || prs->type == 'O')) ? size++ : size;
	if (prs->flg[3] == 1 && (prs->type == 'o' || prs->type == 'O'))
		size++;
	if ((prs->ttype == 's' || prs->ttype == 'u'))
	{
		// size = ft_get_size(prs, j, prs->data, prs->udata);
		// (prs->flg[3] == 1 && (prs->type == 'o' || prs->type == 'O')) ? size++ : size;
		// (prs->flg[3] == 1 && (prs->type == 'x' || prs->type == 'X')) ? prs->wd = prs->wd - 2 : 1;
		(prs->acc > size) ? size = prs->acc : size;
		// (prs->flg[1] == 1 || prs->flg[2] == 1 || prs->data < 0) ? prs->wd-- : prs->wd;
		if (prs->flg[1] == 1 || prs->flg[2] == 1 || prs->data < 0)
			prs->wd--;
		(prs->flg[4] == 1 && prs->wd > size) ? size = prs->wd : size;
	}
	((prs->type == 's' || prs->type == 'S') && prs->flg[6] > 0
	&& prs->acc < size) ? size = prs->acc : size;
	ft_makeres(prs, res, j, size);
}

void	ft_cast_size(t_elem *prs, int i)
{
	// (i > 1 && i < 5) ? prs->sz[5] = 1 : prs->sz[5];
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
	if (prs->ttype == 'u' || prs->type == 'c')
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
	type = "idDOUouxXpcCSfFeEgGaAs";
	while (type[j] != '\0' && type[j] != prs->type)
		j++;
	(j < 3) ? prs->ttype = 's' : prs->ttype;
	(j >= 3 && j < 10) ? prs->ttype = 'u' : prs->ttype;
	(j >= 11 && j < 19) ? prs->ttype = 'd' : prs->ttype;
	(prs->arg_num > 0) ? va_copy(res->ap, res->list) : res->ap;
	while (--(prs->arg_num) > 0)
		va_arg(res->ap, int*);
	if (j < 3)
		prs->data = va_arg(res->ap, intmax_t);
	// else if (j < 10 || j == 10 && prs->sz[5] == 0)
	else if (j < 11)
		prs->data = va_arg(res->ap, uintmax_t);
	// else if (j < 13 || prs->type == 's' && prs->sz[5] == 1)
	else if (j < 13)
		prs->pdata = va_arg(res->ap, wchar_t*);
	else if (j < 21)
		prs->ldata = va_arg(res->ap, long double);
	else if (prs->type == 's')
		prs->tdata = va_arg(res->ap, char*);
	// else if (prs->sz[0] == 1)
	// 	prs->ldata = va_arg(res->ap, long double);
	// else
	// 	prs->ldata = va_arg(res->ap, double);
	// (prs->type == 's' && prs->sz[5] != 1) ? prs->tdata = va_arg(res->ap, char*) : 0;
	// if (prs->type == 'S' || prs->type == 'C' ||
	// ((prs->type == 'c' || prs->type == 's') && prs->sz[5] == 1))
	// 	prs->pdata = va_arg(res->ap, wchar_t*);
	(j > 1 && j < 5) ? prs->sz[5] = 1 : prs->sz[5];
	ft_cast_size(prs, j);
	ft_formating(prs, res, j);
}

size_t	ft_parse(char *ft, size_t i, t_res *res, size_t *k)
{
	t_elem	*prs;
	// int		j;
	// char	*type;

	prs = ft_memalloc(sizeof(t_elem));//or function new t_elem
	ft_bzero(prs, sizeof(*prs));
	(i - *k > res->size - res->l) ? ft_realloc_t_res(&res, i - *k) : 1;
	res->sym = ft_strncpy(&(res->sym[res->l]), &ft[*k], i - *k);
	res->l = res->l + i - *k;
	while (ft[++i] != '\0' && ((ft[i] < 67 && ft[i] != 'A') ||
	(ft[i] > 71 && ft[i] < 97 && ft[i] != 'X' && ft[i] != 'S' && ft[i] != 'O')
	|| (ft[i] > 103 && ft[i] < 110 && ft[i] != 'i' && ft[i] != 'k')
	|| (ft[i] > 112 && ft[i] != 's' && ft[i] != 'u' && ft[i] != 'u' && ft[i] != 'x')))
	{
		i = ft_pars_flg_and_size(ft, i, prs);
		i = ft_pars_wd_and_acc(ft, i, prs, res);
	}
	*k = i + 1;
	prs->type = ft[i];
	(prs->type = 's' && prs->sz[5] == 1) ? prs->type = 'S' : 's';
	(prs->type = 'c' && prs->sz[5] == 1) ? prs->type = 'C' : 'c';
	// (ft[i] == 'd' || ft[i] == 'D' || ft[i] == 'i') ? prs->ttype = 's' : prs->ttype;

	// type = "dDioOuUxXcCpfFeEgGaAsSn";
	// *i = ft_pars_flg_and_wd(format, ++(*i), prs);
	// *i = ft_pars_accur(format, *i, prs);
	// *i = ft_pars_size_and_type(format, *i, prs);
	// res->k = *i + 1;
	// j = 0;
	// while (j < 22 && type[j] != prs->type)
	// 	j++;
	// (j < 3) ? prs->ttype = 's' : prs->ttype;
	// (j >= 3 && j < 12) ? prs->ttype = 'u' : prs->ttype;
	// (j >= 12 && j < 20) ? prs->ttype = 'd' : prs->ttype;
	// (j >= 20 ) ? prs->ttype = 'c' : prs->ttype;
	// (prs->flg[0] == 1 || (prs->flg[6] > 0 && prs->type != 'c' && prs->type != 'C' && prs->ttype != 'c')) ? prs->flg[4] = 0 : prs->flg[4];
	// (prs->ttype == 's') ? prs->flg[3] = 0 : prs->flg[3];
	// if (prs->ttype == 'u')
	// {
	// 	prs->flg[1] = 0;
	// 	prs->flg[2] = 0;
	// }
	if (prs->type != '\0')
		ft_get_data(prs, res, i);
	return (i);
}

int		ft_printf(const char *format, ...)
{
	size_t		i;
	size_t		j;
	t_res		res;
	//static char	buf[2048]
	//va_list	ap;
	
	ft_bzero(&res, sizeof(res));
	va_start(res.ap, format);
	i = -1;
	// res.l = 0;
	res.size = 2048;
	//res.sym = buf;
	res.sym = ft_strnew(2048);
	va_copy(res.list, res.ap);
	while (format[++i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			(++i - j > res.size - res.l) ? ft_realloc_t_res(&res, i - j) : 1;
			res.sym = ft_strncpy(&(res.sym[res.l]), &format[j], i - j);
			res.l = res.l + i - j;
			j = ++i;
		}
		else if (format[i] == '%')
			i = ft_parse((char*)(format), i, &res, &j);
		// if (format[i] == '%')
		// {
		// 	(i - j > res.size - res.l) ? ft_realloc_t_res(&res, i - j) : 1;
		// 	res.sym = ft_strncpy(&(res.sym[res.l]), &format[j], i - j);
		// 	res.l = res.l + i - j;
		// 	j = ft_parse((char*)(format), i, &res);
		// }
	}
	i = write(1, res.sym, res.l);
	va_end(res.ap);
	return (i);
}
