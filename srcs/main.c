/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:54:56 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/03/15 11:18:54 by tgiraudo         ###   ########.fr       */
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
	if (!b->tab)
		return (free(b), NULL);
	return (b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	if (!ft_check_arg(argv))
		return (ft_printf_fd(STDERR_FILENO, "Error\n"), 0);
	a = ft_fill_tab(argv);
	if (!a)
		return (0);
	if (!ft_strs_is_ok(a))
		return (ft_free_struct(a), 0);
	ft_replace_index(a);
	b = init_b();
	if (!b)
		return (ft_free_struct(a), 1);
	ft_sort(a, b);
	ft_free_struct(a);
	ft_free_struct(b);
	return (0);
}
