/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:23:57 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/02/16 12:01:16 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int ft_allready_exist(t_args *args, int nb)
{
    t_stack *stack;

    stack = args->stack;
    while (stack)
    {
        if (stack->content == nb)
            return (1);
        stack = stack->next;
    }
    return (0);
}

int ft_is_integer(char  *arg)
{
    int i;

    i = -1;
    if (ft_atoi(arg) > 2147483647 || ft_atoi(arg) < -2147483648)
        return (0);
    while (arg[++i])
    {
        if (arg[i] == '-' && !ft_isdigit(arg[i + 1]))
            return (0);
        if (arg[i] == '-' && i > 0)
            return (0);
        if (!ft_isdigit(arg[i]) && arg[i] != '-')
            return (0);
    }
    return (1);
}

void    ft_print_stack(t_stack *stack)
{
    t_stack *tmp;

    tmp = stack;
    while (tmp)
    {
        printf("%d\n", tmp->content);
        tmp = tmp->next;
    }
}