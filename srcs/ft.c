/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:21:26 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/12/08 12:58:51 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	s(t_pile	*x)
{
	int	tmp;

	if (x->size > 1)
	{
		tmp = x->tab[0];
		x->tab[0] = x->tab[1];
		x->tab[1] = tmp;
	}
}

void	r(t_pile *x)
{
	int	tmp;
	int	i;

	i = -1;
	tmp = x->tab[0];
	while (x->size - 1 > ++i)
		x->tab[i] = x->tab[i + 1];
	x->tab[i] = tmp;
}

void	rr(t_pile *x)
{
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

void	p(t_pile *from, t_pile *to, char	*str)
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
		from->size--;
		while (from->size > ++i)
			from->tab[i] = copy[i + 1];
		copy = to->tab;
		to->tab = malloc(sizeof(int) * (to->size + 1));
		to->size++;
		to->tab[0] = tmp;
		i = 0;
		while (to->size > ++i)
			to->tab[i] = copy[i - 1];
	}
}
