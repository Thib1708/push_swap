/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:15:22 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/12/09 18:58:55 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_sort(t_stack *a, t_stack *b)
{
	if (!is_sort(a))
	{
		if (a->size > 5)
			sort_big_stack(a, b);
		else 
			sort_small_stack(a, b);
	}
}

void	sort_big_stack(t_stack *a, t_stack *b)
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
			if (((a->tab[0] >> index) & 1) == 0)
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

void	sort_small_stack(t_stack *a, t_stack *b)
{
	int size;
	int i;
	
	if (a->size == 2)
		return (rotate(a));
	else if (a->size == 3)
		return (sort_three(a));
	else if (a->size == 4)
		return (sort_four(a, b));
	size = a->size;
	i = -1;
	while(size > ++i)
	{
		if (a->tab[0] < 2)
			push(a, b, "pb\n");
		else 
			rotate(a);
	}
	if (b->tab[0] == 0)
		swap(b, "sb\n");
	sort_three(a);
	while(b->size)
		push(b, a, "pa\n");
}

void	sort_three(t_stack *a)
{
		if (a->tab[0] > a->tab[1] && a->tab[1] < a->tab[2]
			&& a->tab[2] < a->tab[0])
			return (rotate(a));
		if (a->tab[0] > a->tab[1] && a->tab[1] < a->tab[2]
			&& a->tab[2] > a->tab[0])
			return (swap(a, "sa\n"));
		if (a->tab[0] < a->tab[1] && a->tab[1] > a->tab[2]
			&& a->tab[2] < a->tab[0])
			return (reverse_rotate(a));
		if (a->tab[0] < a->tab[1] && a->tab[1] > a->tab[2]
			&& a->tab[2] > a->tab[0])
		{
			swap(a, "sa\n");
			return (rotate(a));
		}
		if (a->tab[0] > a->tab[1] && a->tab[1] > a->tab[2])
		{
			swap(a, "sa\n");
			return (reverse_rotate(a));
		}
}

void	sort_four(t_stack *a, t_stack *b)
{
	if(!is_sort(a))
	{
		push(a, b, "pb\n");
		sort_three(a);
		push(b, a, "pa\n");
		if (a->tab[0] == 2)
		{
			swap(a, "sa\n");
			rotate(a);
			swap(a, "sa\n");
			reverse_rotate(a);
		}
		else if (a->tab[0] == 3)
			rotate(a);
		else if (a->tab[0] == 1)
			swap(a, "sa\n");
	}
}

