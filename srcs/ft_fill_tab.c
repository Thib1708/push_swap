/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:59:41 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/02/15 09:59:34 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_count(const char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (ft_strrchr(" ", str[i]) && str[i])
			i++;
		while (ft_strrchr(" ", str[i]) == NULL && str[i])
		{
			i++;
			if (ft_strrchr(" ", str[i]) || !str[i])
				count++;
		}
	}
	return (count);
}

int	*fill_one_arg(t_stack *stack, char *str)
{
	int		i;
	char	**tmp;

	i = -1;
	stack->size = ft_count(str);
	tmp = ft_split(str, " ");
	if (!tmp)
		return (NULL);
	stack->tab = malloc(sizeof(int) * (ft_count(str)));
	if (!stack->tab)
		return (NULL);
	while (tmp[++i])
	{
		if (ft_atoi(tmp[i]) > 2147483647 || \
			ft_atoi(tmp[i]) < -2147483648)
			return (ft_free_struct(stack), \
			ft_printf_fd(STDERR_FILENO, "Error\n"), \
			ft_free_tab(tmp), NULL);
		stack->tab[i] = ft_atoi(tmp[i]);
	}
	ft_free_tab(tmp);
	return (stack->tab);
}

t_stack	*ft_fill_tab(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	stack = malloc(sizeof(t_stack));
	if (argc == 2 && ft_count(argv[1]) > 1)
	{
		stack->tab = fill_one_arg(stack, argv[1]);
		if (!stack->tab)
			return (NULL);
		return (stack);
	}
	stack->size = argc - 1;
	stack->tab = malloc(sizeof(int) * (argc - 1));
	i = 0;
	while (argc > ++i)
	{
		if (ft_atoi(argv[i]) > 2147483647 || \
		ft_atoi(argv[i]) < -2147483648)
			return (ft_free_struct(stack), \
			ft_printf_fd(STDERR_FILENO, "Error\n"), NULL);
		stack->tab[i - 1] = ft_atoi(argv[i]);
	}
	return (stack);
}

void	ft_replace_index(t_stack *stack)
{
	int	i;
	int	j;
	int	*tmp;
	int	index;

	j = 0;
	stack->prev = -2147483649;
	tmp = malloc(sizeof(int) * (stack->size));
	while (j < stack->size)
	{
		i = -1;
		stack->min = 2147483648;
		while (stack->size > ++i)
		{
			if (stack->tab[i] <= stack->min && stack->tab[i] > stack->prev)
			{
				stack->min = stack->tab[i];
				index = i;
			}
		}
		stack->prev = stack->min;
		tmp[index] = j++;
	}
	free(stack->tab);
	stack->tab = tmp;
}
