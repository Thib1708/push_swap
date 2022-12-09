/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:57:30 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/12/09 18:32:58 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc == 1)
		return (0);
	if (argc == 2 && ft_count(argv[1]) < 2)
		return (0);
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' '
				&& argv[i][j] != '-')
				return (0);
			j++;
		}
	}
	return (1);
}

int	ft_strs_is_ok(t_stack	*stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (stack->size > i)
	{
		j = i + 1;
		while (stack->size > j)
		{
			if (stack->tab[i] == stack->tab[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sort(t_stack *a)
{
	int	i;

	i = -1;
	while (a->size - 1 > ++i)
		if (a->tab[i] > a->tab[i + 1])
			return (0);
	return (1);
}
