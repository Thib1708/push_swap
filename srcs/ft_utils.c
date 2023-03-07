/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:11:23 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/03/07 14:01:36 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

/*Free 2D array*/
void	ft_free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

/*Free a struct*/
void	ft_free_struct(t_stack *x)
{
	free(x->tab);
	free(x);
}

/*Free both struct and exit*/
void	ft_exit(t_stack *a, t_stack *b)
{
	ft_free_struct(a);
	ft_free_struct(b);
	exit(0);
}

/*Free one struct and exit*/
void	ft_exit_one(t_stack *a)
{
	ft_free_struct(a);
	exit(0);
}
