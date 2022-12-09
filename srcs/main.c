/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:54:56 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/12/09 18:12:45 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_stack	*init_b(void)
{
	t_stack	*b;

	b = malloc(sizeof(t_stack));
	if (!b)
		return (NULL);
	b->size = 0;
	b->tab = ft_calloc(1, sizeof(int));
	b->tab_index = ft_calloc(1, sizeof(int));
	if(!b->tab)
		return (NULL);
	return (b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (!ft_check_arg(argc, argv))
		return (ft_putstr("Error : argument"), 0);
	a = ft_fill_tab(argc, argv);
	if (!a)
		return (ft_putstr("Error : argument"), 0);
	if (ft_strs_is_ok(a))
	{
		ft_free_struct(a);
		return (ft_putstr("Error : duplicate number"), 0);
	}
	b = init_b();
	if (!b)
		return (ft_free_struct(a), 1);
	ft_sort(a, b);
	ft_free_struct(a);
	ft_free_struct(b);
	return (0);
}
