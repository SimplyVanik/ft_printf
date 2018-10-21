/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:53:33 by vdzhanaz          #+#    #+#             */
/*   Updated: 2018/02/20 15:53:34 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// size_t	stsize(intmax_t *value, char base, char **res, char	*ttyp)
// {
// 	size_t		size;
// 	intmax_t	tmp;
	
// 	tmp = *value;
// 	if (ttyp == "uintmax_t")
// 		(unsigned)tmp;
// 	(base == 'p') ? size = 3 : size = 1;
// 	(base == 'p') ? base = 16 : base;
// 	if (tmp < 0)
// 	{
// 		size++;
// 		while ((tmp / 10) < 0);
// 			size++;
// 	}
// 	while ((tmp / base) > 0)
// 		size++;
// 	*res = ft_strnew(size);
// 	if (ttyp == "uintmax_t")
// 		(unsigned)(*value);
// 	if ((*value) < 0)
// 	{
// 		*res[0] = '-';
// 		size--;
// 	}
// 	return (size);
// }
void	ft_realloc_t_res(t_res *res, size_t len)
{
	char	*new;

	while (res->size - res->l > 2 * len)
		res->size = res->size + res->size / 2 + 1;
	new = ft_strnew(res->size);
	res->sym = ft_strncpy(new, res->sym, res->l);
	ft_strdel(&(res->sym));
	res->sym = new;
}

void	ft_uni(t_res *res, int k, int *arr)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	tmp;

	size = 0;
	i = -1;
	while (arr[++i])
	{
		(arr[i] > 65535 && arr[i] < 2097151) ? size = size + 4 : size;
		(arr[i] > 2047 && arr[i] < 65536) ? size = size + 3 : size;
		(arr[i] > 127 && arr[i] < 2048) ? size = size + 2 : size;
		(arr[i] < 128) ? size++ : size;
		(size < k) ? k -= size : break ;
		tmp = -128;
		res->sym[res->l] = (size == 1) ? (char)arr[i] : tmp;
		while (--size > 0)
		{
			tmp /= 2;
			res->sym[res->l] -= tmp;
			res->sym[res->l + size] = -128;
			j = 1;
			while ( j < 33)
			{
				res->sym[res->l + size] += j * (arr[i] % 2);
				j = j * 2;
				arr[i] = arr[i] / 2;
			}
		} 
		j = 1;
		while (j < (size_t)-tmp && tmp != -128)
		{
			res->sym[res->l + size] += j * (arr[i] % 2);
			j = j * 2;
			arr[i] = arr[i] / 2;
		}
		res->l += ft_strlen(&(res->sym[res->l]));
	}
}


void	ft_itoa_baseu(t_elem *tmp, t_res *res, size_t size)
{
	size_t	j;
	//char	*res;
	char	*tab;
	char	type;

	tab = "0123456789abcdef";
	type = tmp->type;
	j = -1;
	//if (ttyp == 'u')
	//	(unsigned)tmp;
	//res = NULL;
	//if (ttyp == "uintmax_t")
		//(unsigned)value;

	// if (value < 0)
	// 	size = stsize(value / (-10), base) + 2;
	// else
	// 	size = stsize(value, base);
	// res = (char *)malloc(sizeof(char) * (size + 1));
	// res[size] = '\0';
	if (type == 'D' || type == 'd' || type == 'i' || type =='U' || type == 'u')
		type = 10;
	// else if (type == 'o' || type == 'O')
	// 	type = 8;
	// else if (type == 'x' || type == 'X')
	// 	type = 16;
	while(type == 'X' && tab[++j] != '\0')
		tab[j] = ft_toupper(tab[j]);
	(type == 'o' || type == 'O') ? type = 8 : type;
	(type == 'x' || type == 'X' || type == 'p') ? type = 16 : type;
	//size = stsize(&value, type, &res, ttyp);
	//res->l = res->l + size;
	if (tmp->data < 0)
	{
		res->sym[res->l + size] = tab[(-1 * (tmp->data) % 10)];
		(tmp->data) = (tmp->data) / (-10);
	}
	while (--size > 0 /*&& value >= base*/)
	{
		res->sym[res->l + size] = tab[(tmp->data) % type];
		(tmp->data) = (tmp->data) / type;
	}
	res->sym[res->l] = tab[tmp->data];
	//return (res->l);
}

// char	*ft_dtoa_baseu(long double value, int accur)
// {
// 	intmax_t	temp;
// 	char		*tmp;
	
// 	temp = (intmax_t)value;
// 	tmp = ft_itoa_baseu(temp, 'd', 'intmax_t', -1);
// 	value = value - temp;
// 	(value < 0) ? value = -1 * value : value;
// 	temp = ft_strlen(tmp);
// 	res = ft_strnew(temp + accur + 1);
// 	res[temp] = '.';
// 	while (res[++temp] != '\0')
// 	{
// 		value = value * 10;
// 		accur = (int)value;
// 		value = value - accur;
// 		res[temp] = value + 48;
// 	}
// 	temp = ft_strlen(tmp);
// 	while (--temp >= 0)
// 		res[temp] = tmp[temp];
// 	ft_memdel(tmp);
// 	return (res);
// }

// void	ft_cast_size(t_elem *tmp)
// {
// 	if (tmp->ttype == 's')
// 	{
// 		(tmp->type == 'D' || tmp->sz == 'l') ? (long int)(tmp->data) : tmp->data;
// 		(tmp->sz == 'm') ? (long long int)(tmp->data) : tmp->data;
// 		(tmp->sz == 'h') ? (short)(tmp->data) : tmp->data;
// 		(tmp->sz == 'j') ? (char)(tmp->data) : tmp->data;
// 		(tmp->sz == 'L') ? (int64)(tmp->data) : tmp->data;
// 		(tmp->sz == 'z' || tmp->sz == 't') ? (ptrdiff_t)(tmp->data) : tmp->data;
// 	}
// 	else if (tmp->ttype == 'u')
// 	{
// 		// if (tmp->type == 'C' || (tmp->type == 'c' && tmp->sz == 'l'))
// 		// 	(unsigned int)(*(tmp->data));
// 		if (tmp->type == 'O' || tmp->sz == 'l' || tmp->type == 'U')
// 			(unsigned long int)(*(tmp->data));
// 		(tmp->sz == 'm') ? (unsigned long long int)(tmp->data) : tmp->data;
// 		(tmp->sz == 'h') ? (unsigned short)(tmp->data) : tmp->data;
// 		(tmp->sz == 'j' || tmp->type == 'c') ? (unsigned char)(tmp->data) : tmp->data;
// 		(tmp->sz == 'L') ? (unsigned int64)(tmp->data) : tmp->data;
// 		(tmp->sz == 'z' || tmp->sz == 't') ? (size_t)(tmp->data) : tmp->data;
// 		if (tmp->type == 'C' || (tmp->type == 'c' && tmp->sz == 'l'))
// 			(unsigned int)(tmp->data);
// 	}
// 	(tmp->ttype == 'd' && tmp->sz !='L') ? double(tmp->ldata) : tmp->ldata;
// 	(tmp->type =='s'&& tmp->sz != 'l') ? (unsigned char *)(tmp->pdata) : tmp->data;
// 	(tmp->flg[1] == 1 || (tmp->data) < 0) ? tmp->flg[3] = 0 : tmp->flg[3];
// }

int		ft_makeres(t_elem *tel, size_t i, char *format, t_res *res)
{
	//char type[23];
	size_t	size;

	//ft_cast_size(tel);
	(tel->type == '%') ? size = 1 : size = ft_set_size(tel);
	(size + res->l > res->size && size > tel->wd) ? ft_realloc(res, size) : 1;
	(tel->wd + res->l > res->size) ? ft_realloc(res, tel->wd) : 1;
	if (tel->type = 'n')
	{
		*(tel->pdata) = res->l;
		return (i);
	}
	(tel->flg[4] == 1) ? ch = '0': ch = ' ';
	//(tel->wd + res->l > res->size || size[1] + res->l > res->size) ? ft_rello() : 1;
	// (tel->flg[3] == 1 && tel->type = 'o') ? size++ : size;
	// (tel->accur > size) ? size = tel->accur: size;
	// (tle->flg[1] == 1 || tel->flg[2] == 1 || *(tel->data) < 0) ? tel->wd-- : 1;
	// (tel->flg[3] == 1 && (tel->type = 'x' || tel->type = 'X')) ? tel->wd = tel->wd - 2 : 1;
	// (ch == '0' && tel->wd > size) ? size = tel->wd : 1;
	(tel->flg[2] == 1) ? res->sym[++(res->l)] = ' ' : res->sym[(res->l)];
	if (tel->flg[0] == 1)
		while (--(tl->wd) > size)
			res->sym[res->l + tl->wd + 1] = ch;
	while ((tl->wd)-- > size)
		res->sym[(res->l)++] = ch;
	if 	(tel->flg[3] == 1 && (tel->type = 'x' || tel->type = 'X'))
	{
		res->sym[(res->l)++] = '0';
		res->sym[(res->l)++] = tel->type;
	}
	(*(tel->data) > 0 && tel->flg[2]) ? res->sym[(res->l)++] = '+' : res->sym[(res->l)];
	(*(tel->data) < 0) ? res->sym[(res->l)++] = '-' : res->sym[(res->l)];
	(tel->ttype == 's' || tel->type == 'u') ? res->l = ft_itoa_baseu(tel, res, size) : res->l;
	if (tel->type == 's')
		res->sym = ft_strncpy(&(res->sym[res->l]), tel->pdata, size);
	(tel->type == 'c') ? res->sym[(res->l)++] = *(tel->data) : 1;
	(tel->type == '%') ? res->sym[(res->l)++] = '%' : 1;
	(tel->type == 'S' || (tel->type = 's' && tel->wd = 'l')) ? ft_uni(res, size, tel->pdata) : 1;
	(tel->type == 'C' || (tel->type = 'c' && tel->wd = 'l')) ? ft_uni(res, size, &(tel->data)) : 1;
	res->l = res->l + ft_strlen(&(res->sym[res->l]));// while (++(res->l) + (tl->wd) < size[1])
	// 	res->sym[res->l] = ch;
	// size = i;
	while (format[++i] != '%' || format[i] != '\0')
		;
	if (format[i] == '\0')
	{
		(i - res->k > res->size - res->l) ? ft_realloc_t_res(res, i - res->k) : 1;
		res->sym = ft_strncpy(&(res->sym[res->l]), &format[res->k], i - res->k);
		res->l = res->l + i - res->k;
	}
	return (i - 1);



	// while (++(res->l) + (tl->wd) < size[1])
	// 	res->sym[res->l] = ch;
	// (tel->flg[1] == 1 && *(tel->data) >= 0) ? res->sym[++(res->l)] = '+' : res->sym[(res->l)];
	// if (tel->flg[1] == 1 && *(tel->data) >= 0 || *(tel->data) < 0)
	// 	res->sym[++(res->l)] = '-';
	// (tel->flg[2] == 1 ) ? res->sym[++(res->l)] = ' ' : res->sym[(res->l)];


	// if ((tel->ttype == 'uintmax_t' || tel->ttype == "intmax_t") && tel->type != 'C'
	// && tel->type != 'c' && tel->type != 'n' && tel->type != 'p')
	// 	tmp = ft_atoi_baseu(*(tel->data), tel->type, tel->ttype, -1);
	// if(tel->type == 'p')
	// {
	// 	tmp = ft_atoi_baseu(tel->data, tel->type, tel->ttype, -1);
	// 	tmp[0] = '0';
	// 	tmp[1] = 'x';
	// }
	// if (tel->type == 's')
	// {
	// 	tmp = ft_strnew(ft_strlen((char*)(tel->data)));
	// 	tmp = ft_strncpy(tmp, (char*)(tel->data), tel->accur)
	// }
	//type = "dDioOuUxXcCpnfFeEgGaAsS";
	// j = i;
	// while (--j > 0 && !(format[j] == '%' && format[j - 1] != '%'))
	// 	;
	// if (format[j] == '%')
	// 	while ()
	// 		j++;
	
}