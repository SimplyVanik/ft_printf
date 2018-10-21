/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <vdzhanaz@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 18:01:15 by vdzhanaz          #+#    #+#             */
/*   Updated: 2018/10/21 08:04:42 by vdzhanaz         ###   ########.fr       */
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

// typedef struct s_flags
// {
// 	size_t		minus : 1;
// 	size_t		plus : 1;
// 	size_t		space : 1;
// 	size_t		zero : 1;
// 	size_t		hesh : 1;
// }				t_fl;

// typedef struct s_flags
// {
// 	size_t		l : 1;
// 	size_t		ll : 1;
// 	size_t		hh : 1;
// 	size_t		h : 1;
// 	size_t		zero : 1;
// 	size_t		hesh : 1;
// 	size_t		minlenth;
// 	size_t		precision;
// }				t_fl;

typedef struct	s_elem
{
	// t_fl		fl;
	char		flg[6];
//	char		is_wd;
	int			wd;
//	char		is_accur;
	int			acc;
	int			arg_num;
	char		sz[8];
	char		type;
	char		ttype;
	intmax_t	data;
	uintmax_t	udata;
	long double	ldata;
	wchar_t		*pdata;
	char		*tdata;
}				t_elem;

typedef struct		s_res
{
	char			*sym;
	size_t			size;
	size_t			l;
	size_t			k;
	va_list			ap;
	va_list			list;
}					t_res;

int					ft_pars_flg_and_wd(char *format, int i, t_elem *prs);
int					ft_pars_accur(char *format, int i, t_elem *prs);
int					ft_pars_size_and_type(char *format, int i, t_elem *prs);
size_t				ft_parse(char *ft, size_t i, t_res *res, size_t *k);
int					ft_printf(const char *format, ...);
void				ft_realloc_t_res(t_res *res, size_t len);
void				ft_uni(t_res *res, int k, int *arr);
void				ft_itoa_baseu(t_elem *tmp, t_res *res, size_t size1);
void				ft_cast_size(t_elem *tmp, int i);
void				ft_makeres(t_elem *tel, t_res *res, int j, size_t size);
size_t				*ft_set_size(t_elem *p);
size_t				ft_ucode_sz(void *data);
size_t				ft_get_size(t_elem *prs, int j, intmax_t data, uintmax_t udata);

#endif
