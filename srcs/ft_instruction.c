/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:21:26 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/03/14 16:47:20 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

/*Swap the two top number of the stack 
(1 0 2) -> (0 1 2)*/
void	swap(t_stack *x, char *str)
{
	int	tmp;

	ft_printf_fd(1, "%s", str);
	if (x->size > 1)
	{
		tmp = x->tab[0];
		x->tab[0] = x->tab[1];
		x->tab[1] = tmp;
	}
}

/*All the number goes one rank down, the last one become the first one
(1 2 0) -> (0 1 2)*/
void	rotate(t_stack *x)
{
	int	tmp;
	int	i;

	ft_printf_fd(1, "ra\n");
	i = -1;
	tmp = x->tab[0];
	while (x->size - 1 > ++i)
	{
		x->tab[i] = x->tab[i + 1];
	}
	x->tab[i] = tmp;
}

/*All the number goes one rank up, the first one become the last one 
(2 0 1) -> (0 1 2)*/
void	reverse_rotate(t_stack *x)
{
	int	tmp;
	int	i;

	ft_printf_fd(1, "rra\n");
	i = x->size - 1;
	tmp = x->tab[i];
	while (i > 0)
	{
		x->tab[i] = x->tab[i - 1];
		i--;
	}
	x->tab[i] = tmp;
}

/*Put the top number on the other stack 
(2 0) (1) -> (0) (2 1)*/
void	push(t_stack *from, t_stack *to, char *str)
{
	int	tmp;
	int	*copy;
	int	i;

	i = -1;
	if (from->size < 0)
		return ;
	ft_printf_fd(1, "%s", str);
	tmp = from->tab[0];
	copy = from->tab;
	from->tab = malloc(sizeof(int) * (from->size-- - 1));
	if (!from->tab)
		ft_exit(from, to);
	while (from->size > ++i)
		from->tab[i] = copy[i + 1];
	free(copy);
	copy = to->tab;
	to->tab = malloc(sizeof(int) * (to->size++ + 1));
	if (!to->tab)
		ft_exit(from, to);
	to->tab[0] = tmp;
	i = 0;
	while (to->size > ++i)
		to->tab[i] = copy[i - 1];
	free(copy);
}
