/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:03:55 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/03/15 11:00:18 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/headers/get_next_line.h"
# include "../libft/headers/ft_printf_fd.h"
# include "../libft/headers/libft.h"

typedef struct s_stack
{
	int			*tab;
	int			size;
	long int	min;
	long int	prev;
	int			j;
}	t_stack;

/**********************MAIN*********************/
int		main(int argc, char **argv);
t_stack	*init_b(void);

/**********************SORT*********************/
void	ft_sort(t_stack *a, t_stack *b);
void	sort_big_stack(t_stack *a, t_stack *b);
void	sort_small_stack(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);

/*********************CHECK*********************/
int		ft_check_arg(char **argv);
int		ft_strs_is_ok(t_stack	*stack);
int		is_sort(t_stack *a);

/*******************FILL*TAB********************/
t_stack	*ft_fill_tab(char **argv);
void	ft_replace_index(t_stack *stack);
int		*fill_one_arg(t_stack *stack, char *str);
int		ft_count(const char *str);

/*****************INSTRUCTIONS******************/
void	swap(t_stack	*x, char *str);
void	rotate(t_stack *x);
void	reverse_rotate(t_stack *x);
void	push(t_stack *from, t_stack *to, char	*str);

/*********************UTILS*********************/
void	ft_free_struct(t_stack *x);
void	ft_free_tab(char **tab);
void	ft_exit(t_stack *a, t_stack *b);
void	ft_exit_one(t_stack *a);

#endif