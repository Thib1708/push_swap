/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:54:56 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/12/08 13:00:56 by tgiraudo         ###   ########.fr       */
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

t_pile	*ft_fill_tab(int argc, char **argv)
{
	t_pile	*pile;
	char	**tmp;
	int		i;

	i = -1;
	pile = malloc(sizeof(t_pile));
	if (argc == 2 && ft_count(argv[1]) > 1)
	{
		pile->size = ft_count(argv[1]);
		tmp = ft_split(argv[1], " ");
		pile->tab = malloc(sizeof(int) * (ft_count(argv[1])));
		while (tmp[++i])
			pile->tab[i] = ft_atoi(tmp[i]);
	}
	else if (argc > 2)
	{
		pile->size = argc - 1;
		pile->tab = malloc(sizeof(char *) * (argc - 1));
		i = 0;
		while (argc > ++i)
			pile->tab[i - 1] = ft_atoi(argv[i]);
	}
	else
		return (NULL);
	return (pile);
}

t_pile	*init_b(void)
{
	t_pile	*b;

	b = malloc(sizeof(t_pile));
	b->size = 0;
	b->tab = ft_calloc(1, sizeof(int));
	return (b);
}

int	main(int argc, char **argv)
{
	t_pile	*a;
	t_pile	*b;

	if (!ft_check_arg(argc, argv))
		return (ft_putstr("Error : argument"), 0);
	a = ft_fill_tab(argc, argv);
	if (!a)
		return (ft_putstr("Error : argument"), 0);
	if (ft_strs_is_ok(a))
		return (ft_putstr("Error : duplicate number"), 0);
	b = init_b();
	push_swap(a, b);
	ft_printf("Stack is sort\n");
	ft_print_stack(a, b);
	return (0);
}
