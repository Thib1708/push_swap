/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:21:26 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/12/09 18:30:41 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap(t_stack	*x, char *str)
{
	ft_putstr(str);
	int	tmp;

	if (x->size > 1)
	{
		tmp = x->tab[0];
		x->tab[0] = x->tab[1];
		x->tab[1] = tmp;
	}
}

void	rotate(t_stack *x)
{
	ft_putstr("ra\n");
	int	tmp;
	int	i;

	i = -1;
	tmp = x->tab[0];
	while (x->size - 1 > ++i)
	{
		x->tab[i] = x->tab[i + 1];
	}
	x->tab[i] = tmp;
}

void	reverse_rotate(t_stack *x)
{
	ft_putstr("rra\n");
	int	tmp;
	int	i;

	i = x->size - 1;
	tmp = x->tab[i];
	while (i > 0)
	{
		x->tab[i] = x->tab[i - 1];
		i--;
	}
	x->tab[i] = tmp;
}

void	push(t_stack *from, t_stack *to, char *str)
{
	int	tmp;
	int	*copy;
	int	i;

	i = -1;
	if (from->size > 0)
	{
		ft_putstr(str);
		tmp = from->tab[0];
		copy = from->tab;
		from->tab = malloc(sizeof(int) * (from->size - 1));
		if (!from->tab)
			ft_exit(from, to);
		from->size--;
		while (from->size > ++i)
			from->tab[i] = copy[i + 1];
		free(copy);
		copy = to->tab;
		to->tab = malloc(sizeof(int) * (to->size + 1));
		if (!to->tab)
			ft_exit(from, to);
		to->size++;
		to->tab[0] = tmp;
		i = 0;
		while (to->size > ++i)
			to->tab[i] = copy[i - 1];
		free(copy);
	}
}
