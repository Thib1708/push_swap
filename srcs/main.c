/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:54:56 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/12/07 14:42:26 by tgiraudo         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_pile	*a;

	if (!ft_check_arg(argc, argv))
		ft_printf("error");
	a = ft_fill_tab(argc, argv);
	if (ft_strs_is_ok(a))
		ft_printf("pile error");
	return (0);
}
