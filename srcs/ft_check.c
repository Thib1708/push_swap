/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:57:30 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/12/08 13:07:18 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 2)
		return (0);
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' ')
				return (0);
			j++;
		}
	}
	return (1);
}

int	ft_strs_is_ok(t_pile	*pile)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (pile->size > i)
	{
		j = i + 1;
		while (pile->size > j)
		{
			if (pile->tab[i] == pile->tab[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
