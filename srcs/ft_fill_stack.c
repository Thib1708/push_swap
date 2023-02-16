/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:12:02 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/02/16 13:38:23 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	*ft_fill_tab(t_args *args)
{
	t_stack	*stack;
	int		*tab;
	int		i;

	stack = args->stack;
	tab = malloc(sizeof (int) * (ft_stacksize(stack)));
	if (!tab)
		return (NULL);
	i = -1;
	while (stack)
	{
		tab[++i] = stack->content;
		stack = stack->next;
	}
	return (tab);
}

int	*ft_sort_tab(int *tab, int size)
{
	int i;
	int j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i;
		while (j > 0 && tab[j - 1] > tab[j])
		{
			tmp = tab[j];
			tab[j] = tab[j - 1];
			tab[j - 1] = tmp;
			j--;
		}
		i++;
	}
	i = -1;
	return (tab);
}

void	ft_replace_index(t_args *args)
{
	int	*sort_tab;
	int	size;
	t_stack	*stack;
	int i;
	
	ft_print_stack(args->stack);
	printf("\n\n\n");
	stack = args->stack;
	size = ft_stacksize(stack);
	sort_tab = ft_fill_tab(args);
	if (!sort_tab)
		return (NULL);
	sort_tab = ft_sort_tab(sort_tab, size);
	while (stack)
	{
		i = 0;
		while (i < size && sort_tab[i] != stack->content)
			i++;
		stack->content = i;
		stack = stack->next;
	}
}

int	ft_add_arg(t_args *args, char *split_arg)
{
	t_stack *new;
	
	if (!ft_is_integer(split_arg))
		return (0);
	if (ft_allready_exist(args, ft_atoi(split_arg)))
		return (0);
	new = ft_stacknew((ft_atoi(split_arg)));
	ft_stackadd_back(&args->stack, new);
	return (1);
}

int	ft_fill_stack(t_args *args, char **argv)
{
	char	**split_arg;
	int i;
	int j;

	args->stack = NULL;
	i = -1;
	while (argv[++i])
	{
		split_arg = ft_split(argv[i], " ");
		if (!split_arg)
			return (printf("Malloc"), 0);
		j = -1;
		while (split_arg[++j])
			if (!ft_add_arg(args, split_arg[j]))
				return (ft_printf_fd(STDERR_FILENO, "Error\n"), 0);
	}
	ft_replace_index(args);
	return (1);
}