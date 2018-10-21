/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelelem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 23:03:46 by vdzhanaz          #+#    #+#             */
/*   Updated: 2017/11/20 23:03:47 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelelem(t_list **alst, void (*del)(void *, size_t))
{
	t_list *buf;

	if (alst != NULL && del != NULL && *alst != NULL)
	{
		buf = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = buf;
	}
}
