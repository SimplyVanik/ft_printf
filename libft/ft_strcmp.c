/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 19:47:54 by vdzhanaz          #+#    #+#             */
/*   Updated: 2017/10/27 20:01:38 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*t1;
	unsigned char	*t2;

	if (!s1 && !s2)
		return (0);
	t1 = (unsigned char*)s1;
	t2 = (unsigned char*)s2;
	i = 0;
	while (t1[i] != '\0' && t2[i] != '\0' && t1[i] == t2[i])
		i++;
	return (t1[i] - t2[i]);
}
