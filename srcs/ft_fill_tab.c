/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:59:41 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/12/09 18:18:05 by tgiraudo         ###   ########.fr       */
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

void	fill_one_arg(t_stack *stack, char *str)
{
	int		i;
	char	**tmp;

	i = 0;
	stack->size = ft_count(str);
	tmp = ft_split(str, " ");
	stack->tab = malloc(sizeof(int) * (ft_count(str)));
	while (tmp[++i])
	{
		stack->tab[i] = ft_atoi(tmp[i]);
		free(tmp[i]);
	}
	free(tmp);
}

t_stack	*ft_fill_tab(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	stack = malloc(sizeof(t_stack));
	if (argc == 2 && ft_count(argv[1]) > 1)
		fill_one_arg(stack, argv[1]);
	else if (argc > 2)
	{
		stack->size = argc - 1;
		stack->tab = malloc(sizeof(char *) * (argc - 1));
		i = 0;
		while (argc > ++i)
			stack->tab[i - 1] = ft_atoi(argv[i]);
	}
	else
		return (NULL);
	ft_fill_index(stack);
	return (stack);
}

void	ft_fill_index(t_stack *stack)
{
	int	i;
	int	j;
	int	index;
	int	min;
	int	prec;

	j = 0;
	prec = -2147483648;
	stack->tab_index = malloc(sizeof(int) * (stack->size));
	while(j < stack->size)
	{
		i = -1;
		min = 2147483647;
		while (stack->size > ++i)
			if (stack->tab[i] <= min && stack->tab[i] > prec)
			{
				min = stack->tab[i];
				index = i;
			}
		prec = min;
		stack->tab_index[index] = j++;
	}
}
