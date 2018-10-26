/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <vdzhanaz@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:38:02 by vdzhanaz          #+#    #+#             */
/*   Updated: 2018/10/26 01:11:11 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_get_nxt(t_res *res, char *ft, size_t *i, t_elem *prs)
{
	int		j;
	int		rez;
	va_list tmp;

	rez = 0;
	j = ft_atoi(&ft[++(*i)]);
	while (ft[*i] > 47 && ft[*i] < 58)
		(*i)++;
	if (ft[*i] == '$')
	{
		va_copy(tmp, res->list);
		while (j-- > 0)
			rez = va_arg(tmp, int);
	}
	else if (prs->arg_num > 0)
		while (prs->arg_num-- > 0)
			rez = va_arg(res->ap, int);
	else
		rez = va_arg(res->ap, int);
	if (ft[*i] != '$')
		while (ft[*i - 1] != '*')
			(*i)--;
	else
		(*i)++;
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

size_t	ft_get_acc(char *ft, size_t i, t_elem *prs, t_res *res)
{
	int		j;

	j = 0;
	prs->flg[5] = 1;
	j = ft_atoi(&ft[++i]);
	prs->acc = (ft[i] > 47 && ft[i] < 58) ? j : 0;
	if (ft[i] == '*')
		prs->acc = ft_get_nxt(res, ft, &i, prs);
	(prs->acc < 0) ? prs->flg[5] = 0 : prs->flg[5];
	if (ft[i - 1] != '*')
		while (ft[i] > 47 && ft[i] < 58)
			i++;
	return (i);
}

size_t	ft_pars_wd_and_acc(char *ft, size_t i, t_elem *prs, t_res *res)
{
	int		j;

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
		prs->wd = ft_get_nxt(res, ft, &i, prs);
	if (prs->wd < 0)
	{
		prs->flg[0] = 1;
		prs->wd = -prs->wd;
	}
	if (ft[i] == '.')
		i = ft_get_acc(ft, i, prs, res);
	return (i - 1);
}

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
			else
				prs->sz[j - 5] = 1;
			j = -1;
			if (ft[i + 1] == ft[i])
				i++;
			i++;
		}
	return (i);
}
