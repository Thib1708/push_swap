/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:57:30 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/02/21 14:27:41 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_check_arg(int argc, char **av)
{
	int	i;
	int	j;
	int	digit;

	i = 0;
	(void)argc;
	while (av[++i])
	{
		j = -1;
		digit = 0;
		while (av[i][++j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != ' ' && av[i][j] != '-')
				return (0);
			if (av[i][j] == '-' && ft_isdigit(av[i][j - 1]))
				return (0);
			if (av[i][j] == '-' && !ft_isdigit(av[i][j + 1]))
				return (0);
			if (ft_isdigit(av[i][j]))
				digit = 1;
		}
		if (!digit)
			return (0);
	}
	return (1);
}

int	ft_strs_is_ok(t_stack	*stack)
{
	int	i;
	int	j;

	i = -1;
	while (stack->size > ++i)
	{
		j = i;
		while (stack->size > ++j)
			if (stack->tab[i] == stack->tab[j])
				return (ft_printf_fd(STDERR_FILENO, "Error\n"), 0);
	}
	return (1);
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
