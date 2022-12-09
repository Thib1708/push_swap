/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:54:56 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/12/09 15:12:54 by tgiraudo         ###   ########.fr       */
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
		{
			pile->tab[i] = ft_atoi(tmp[i]);
			free(tmp[i]);
		}
		free(tmp);
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

void	ft_fill_index(t_pile *pile)
{
	int min;
	int i;
	int index;
	int j;
	int prec;

	j = 0;
	prec = -2147483648;
	pile->tab_index = malloc(sizeof(int) * (pile->size));
	while(j < pile->size)
	{
		i = -1;
		min = 2147483647;
		while (pile->size > ++i)
			if (pile->tab[i] <= min && pile->tab[i] > prec)
			{
				min = pile->tab[i];
				index = i;
			}
		prec = min;
		pile->tab_index[index] = j++;
	}
}

t_pile	*init_b(void)
{
	t_pile	*b;

	b = malloc(sizeof(t_pile));
	if (!b)
		return (NULL);
	b->size = 0;
	b->tab = ft_calloc(1, sizeof(int));
	b->tab_index = ft_calloc(1, sizeof(int));
	if(!b->tab)
		return (NULL);
	return (b);
}

void	ft_free_struct(t_pile *x)
{
	free(x->tab);
	free(x->tab_index);
	free(x);
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
	ft_fill_index(a);
	if (ft_strs_is_ok(a))
	{
		ft_free_struct(a);
		return (ft_putstr("Error : duplicate number"), 0);
	}
	b = init_b();
	if (!b)
		return (ft_free_struct(a), 1);
	ft_sort(a, b);
	// ft_print_stack(a, b);
	ft_free_struct(a);
	ft_free_struct(b);
	return (0);
}
