/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:34:57 by vdzhanaz          #+#    #+#             */
/*   Updated: 2017/11/17 14:35:00 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *nlst;
	t_list *buf;

	if (!lst)
		return (NULL);
	nlst = (t_list*)malloc(sizeof(t_list));
	if (!f || !nlst)
		return (NULL);
	nlst = f(lst);
	buf = nlst;
	while (lst->next)
	{
		nlst->next = (t_list*)malloc(sizeof(t_list));
		if (!nlst->next)
		{
			ft_lstdel(&buf, &ft_delcont);
			return (NULL);
		}
		nlst->next = f(lst->next);
		nlst = nlst->next;
		lst = lst->next;
	}
	nlst->next = NULL;
	return (buf);
}
