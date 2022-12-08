/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:15:22 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/12/08 19:40:26 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"


void	ft_print_stack(t_pile *a, t_pile *b)
{
	int	o;

	o = 0;
	while (o < a->size || o < b->size)
	{
		if (o < a->size)
			ft_printf("%d ", a->tab[o]);
		else
			ft_printf("  ");
		if (o < b->size)
			ft_printf("%d\n", b->tab[o]);
		else
			ft_printf(" \n");
		o++;
	}
	o = 0;
	ft_printf("- -\na b");
}

void	push_swap(t_pile *a, t_pile *b)
{
	int	i;
	int	size;
	int	index;

	index = -1;
	while (!is_sort(a))
	{
		size = a->size;
		i = 0;
		index++;
		while (size > i)
		{
			if (((a->tab_index[0] >> index) & 1) == 0)
				push(a, b, "pb\n");
			else
				rotate(a);
			i++;
		}
		while (b->size)
		{
			push(b, a, "pa\n");
		}
	}
}
