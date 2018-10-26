/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <vdzhanaz@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 18:01:15 by vdzhanaz          #+#    #+#             */
/*   Updated: 2018/10/25 22:52:12 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <inttypes.h>
# include <stdbool.h>
# include <wchar.h>
# include <stdarg.h>
# include <libft.h>
# include <limits.h>

typedef struct		s_elem
{
	char			flg[6];
	int				wd;
	int				acc;
	int				arg_num;
	char			sz[8];
	char			type;
	char			ttype;
	intmax_t		data;
	uintmax_t		udata;
	long double		ldata;
	wchar_t			*pdata;
	char			*tdata;
}					t_elem;

typedef struct		s_res
{
	char			*sym;
	size_t			size;
	size_t			l;
	size_t			k;
	va_list			ap;
	va_list			list;
}					t_res;

int					ft_get_nxt(t_res *res, char *ft, size_t *i, t_elem *prs);
void				ft_realloc_t_res(t_res *res, size_t len);
size_t				ft_get_acc(char *ft, size_t i, t_elem *prs, t_res *res);
size_t				ft_pars_wd_and_acc(char *ft, size_t i, t_elem *prs,
t_res *res);
size_t				ft_pars_flg_and_size(char *ft, size_t i, t_elem *prs);
void				ft_uni_make(t_res *res, size_t *size, int arr);
void				ft_uni(t_res *res, size_t k, t_elem *prs);
size_t				ft_get_size(t_elem *prs, int bs, intmax_t data,
uintmax_t udata);
void				ft_itoa_baseu(t_elem *tmp, t_res *res, int size, int type);
void				ft_pointer(t_res *res, t_elem *prs);
void				ft_makeres(t_elem *prs, t_res *res, int j, int size);
size_t				ft_wch_format(t_elem *prs, size_t size);
void				ft_formating(t_elem *prs, t_res *res, int j);
void				ft_cast_size(t_elem *tmp, int i);
void				ft_get_data(t_elem *prs, t_res *res, int j);
size_t				ft_parse(char *ft, size_t i, t_res *res, size_t j);
int					ft_printf(const char *format, ...);

#endif
