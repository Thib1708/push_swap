/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:03:55 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/02/16 11:55:34 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/headers/get_next_line.h"
# include "../libft/headers/ft_printf_fd.h"
# include "../libft/headers/libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

typedef struct s_args
{
	t_stack		*stack;
	int			size;
	long int	min;
	long int	prev;
}	t_args;

/**********************MAIN*********************/
int		main(int argc, char **argv);
t_args	*init_b(void);

// /**********************SORT*********************/
// void	ft_sort(t_args *a, t_args *b);
// void	sort_big_args(t_args *a, t_args *b);
// void	sort_small_args(t_args *a, t_args *b);
// void	sort_three(t_args *a);
// void	sort_four(t_args *a, t_args *b);

/*********************STACK*********************/
void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
t_stack	*ft_stacknew(int content);
int	ft_stacksize(t_stack *stack);
t_stack	*ft_stacklast(t_stack *stack);

int 	ft_is_integer(char  *arg);
void    ft_print_stack(t_stack *stack);
int 	ft_fill_stack(t_args *args, char **argv);
int ft_allready_exist(t_args *args, int nb);

#endif