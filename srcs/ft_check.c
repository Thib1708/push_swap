/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:57:30 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/03/15 14:00:05 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

/*Check if args are integer*/
int	ft_check_arg(char **a)
{
	int	i;
	int	j;
	int	digit;

	i = 0;
	while (a[++i])
	{
		j = -1;
		digit = 0;
		while (a[i][++j])
		{
			if (!ft_isdigit(a[i][j]) && a[i][j] != ' ' \
			&& a[i][j] != '-' && a[i][j] != '+')
				return (0);
			if ((a[i][j] == '-' || a[i][j] == '+') && ft_isdigit(a[i][j - 1]))
				return (0);
			if ((a[i][j] == '-' || a[i][j] == '+') && !ft_isdigit(a[i][j + 1]))
				return (0);
			if (ft_isdigit(a[i][j]))
				digit = 1;
		}
		if (!digit)
			return (0);
	}
	return (1);
}

/*Check is a number is present only once*/
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

/*Check is the stack is sort*/
int	is_sort(t_stack *a)
{
	int	i;

	i = -1;
	while (a->size - 1 > ++i)
		if (a->tab[i] > a->tab[i + 1])
			return (0);
	return (1);
}
