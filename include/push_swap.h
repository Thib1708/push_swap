/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:03:55 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/12/09 16:10:15 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/headers/get_next_line.h"
# include "../libft/headers/ft_printf.h"
# include "../libft/headers/libft.h"

typedef struct s_pile
{
	int	*tab;
	int	*tab_index;
	int	size;
}	t_pile;

int		ft_check_arg(int argc, char **argv);
t_pile	*ft_fill_tab(int argc, char **argv);
int		ft_count(const char *str);
int		ft_strs_is_ok(t_pile	*pile);
void	swap(t_pile	*x, char *str);
void	rotate(t_pile *x);
void	reverse_rotate(t_pile *x);
void	push(t_pile *from, t_pile *to, char *str);
void	ft_sort(t_pile *a, t_pile *b);
void	sort_big_stack(t_pile *a, t_pile *b);
void	sort_small_stack(t_pile *a, t_pile *b);
int		is_sort(t_pile *a);
void	ft_print_stack(t_pile *a, t_pile *b);
void	ft_free_struct(t_pile *x);
void	ft_exit(t_pile *a, t_pile *b);

#endif