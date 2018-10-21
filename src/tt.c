/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:46:46 by vdzhanaz          #+#    #+#             */
/*   Updated: 2018/04/05 14:46:48 by vdzhanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




{
	char	*flags;
	char	*sizes;
	int		j;

	flags = "-+ #0";
	sizes = "Ljztlh";
	while (ft[i] != '\0' && (ft[i] < 67 && ft[i] != 'A' && ft[i] != '%' || ft[i]
	> 71 && ft[i] < 97 && ft[i] != 'X' && ft[i] != 'S' && ft[i] != 'O' || ft[i]
	> 103 && ft[i] < 110 && ft[i] != 'i' && ft[i] != 'k' || ft[i] > 112 && ft[i]
	!= 's' && ft[i] != 'u' && ft[i] != 'u' && ft[i] != 'x'))
	{
		if (ft[i] == '.')
		{
			i++;
			prs->flg[6] = 1;
			// if (ft[i++] == '*')
			// 	prs->flg[6] = '*';
			// else
			// {
			if (ft[i] == '*')
			{	
				prs->flg[6] = '*';
				i++
			}
			else if (ft[i] < 48 && ft[i] > 57)
				prs->accur = 0;
				//(ft[i++] == '-') ? prs->flg[0] = 1 : prs->flg[0];
			else
			{	
				prs->accur = ft_atoi(&ft[i]);
				while (ft[i] > 47 && ft[i] < 58)
					i++;
			}
		}
		//(ft[i++] == '*') ? prs->flg[5] = '*' : prs->flg[5];
		if (ft[i] == '*')
		{
			prs->flg[5] = '*';
			i++;
		}
		if (ft[i] > 48 && ft[i] < 58)
		{	
			j = ft_atoi(&format[i]);
			while (ft[i] > 47 && ft[i] < 58)
				i++;
			if (ft[i] == '$') // test how it works with '*' for acc or wd
			{
				prs->arg_nbr = j;
				i++;
			}
			else
			{
				prs->flg[5] = 1;
				prs->wd = j;
			}
		}
		j = -1;
		while (flags[++j] != '\0')
			if (flags[j] == ft[i])
			{
				prs->flg[j] = 1;
				j = -1;
				i++;
			}
		while (sizes[++j] != '\0')
			if (sizes[j] == ft[i])
			{
				if (ft[i + 1] == 'l' && ft[i++] == 'l')
					prs->sz[6] = 1;
				else if (ft[i + 1] == 'h' && ft[i++] == 'h')
					prs->sz[7] = 1;
				else
					prs->flg[j] = 1;
				j = -1;
				i++;
			}
	}
}