/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 23:12:15 by vdzhanaz          #+#    #+#             */
/*   Updated: 2017/11/20 23:12:19 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstrev(t_list *lst)
{
	t_list *buf1;
	t_list *buf2;

	buf1 = NULL;
	buf2 = NULL;
	while (lst)
	{
		buf1 = lst->next;
		lst->next = buf2;
		buf2 = lst;
		lst = buf1;
	}
	return (buf2);
}
