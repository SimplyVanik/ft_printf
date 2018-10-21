/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:46:43 by vdzhanaz          #+#    #+#             */
/*   Updated: 2017/11/15 18:46:45 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	new = (t_list*)malloc(sizeof(t_list));
	if (new)
	{
		if ((new->content = ft_memalloc(content_size)))
		{
			if (content)
			{
				new->content = ft_memcpy(new->content, content, content_size);
				new->content_size = content_size;
			}
			else
			{
				new->content = NULL;
				new->content_size = 0;
			}
			new->next = NULL;
		}
		else
			ft_memdel((void**)&new);
		return (new);
	}
	else
		return (NULL);
}
