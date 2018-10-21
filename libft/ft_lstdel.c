/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:03:35 by vdzhanaz          #+#    #+#             */
/*   Updated: 2017/11/16 18:03:36 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *buf;

	if (alst != NULL && del != NULL)
	{
		while (*alst)
		{
			buf = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = buf;
		}
	}
}
