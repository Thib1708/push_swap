/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:11:23 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/11 11:17:25 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_print_stack(t_stack *a, t_stack *b)
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
	ft_printf("- -\na b \n");
}

void	ft_free_struct(t_stack *x)
{
	free(x->tab);
	free(x);
}

void	ft_exit(t_stack *a, t_stack *b)
{
	ft_free_struct(a);
	ft_free_struct(b);
	exit(0);
}
