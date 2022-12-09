/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:15:22 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/12/09 15:14:03 by tgiraudo         ###   ########.fr       */
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
			ft_printf("%d ", a->tab_index[o]);
		else
			ft_printf("  ");
		if (o < b->size)
			ft_printf("%d\n", b->tab[o]);
		else
			ft_printf(" \n");
		o++;
	}
	o = 0;
	ft_printf("- -\na b \n");
}

void	ft_sort(t_pile *a, t_pile *b)
{
	if (!is_sort(a))
	{
		if (a->size > 5)
			sort_big_stack(a, b);
		else 
			sort_small_stack(a, b);
	}
}

void	sort_big_stack(t_pile *a, t_pile *b)
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

void	sort_three(t_pile *a)
{
		if (a->tab[0] > a->tab[1] && a->tab[1] < a->tab[2] && a->tab[2] < a->tab[0])
			return (rotate(a));
		if (a->tab[0] > a->tab[1] && a->tab[1] < a->tab[2] && a->tab[2] > a->tab[0])
			return (swap(a));
		if (a->tab[0] < a->tab[1] && a->tab[1] > a->tab[2] && a->tab[2] < a->tab[0])
			return (reverse_rotate(a));
		if (a->tab[0] < a->tab[1] && a->tab[1] > a->tab[2] && a->tab[2] > a->tab[0])
		{
			swap(a);
			return (rotate(a));
		}
		if (a->tab[0] > a->tab[1] && a->tab[1] > a->tab[2])
		{
			swap(a);
			return (reverse_rotate(a));
		}
}

void	sort_four(t_pile *a, t_pile *b)
{
	if(!is_sort(a))
	{
		push(a, b, "pb\n");
		sort_three(a);
		push(b, a, "pa\n");
		if (a->tab_index[0] > a->tab_index[2] && a->tab_index[0] < a->tab_index[3])
		{
			swap(a);
			rotate(a);
			swap(a);
			reverse_rotate(a);
		}
		else if (a->tab_index[0] > a->tab_index[3])
			rotate(a);
		else if (a->tab_index[0] > a->tab_index[1] && a->tab_index[0] < a->tab_index[2])
			swap(a);
	}
}

void	sort_small_stack(t_pile *a, t_pile *b)
{
	if (a->size == 2)
		return (rotate(a));
	else if (a->size == 3)
		return (sort_three(a));
	else if (a->size == 4)
		return (sort_four(a, b));
	push(a, b, "pb\n");
	sort_four(a, b);
	push(b, a, "pa\n");
	if (a->tab_index[0] == 4)
		rotate(a);
	else if (a->tab_index[0] == 1)
		swap(a);
	else if (a->tab_index[0] == 3)
	{
		reverse_rotate(a);
		swap(a);
		rotate(a);
		rotate(a);
	}
	else if (a->tab_index[0] == 2)
	{
		swap(a);
		rotate(a);
		swap(a);
		reverse_rotate(a);
	}
}