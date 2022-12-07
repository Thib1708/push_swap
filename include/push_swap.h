/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:03:55 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/12/07 14:41:19 by tgiraudo         ###   ########.fr       */
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
	int	size;
}	t_pile;

int		ft_check_arg(int argc, char **argv);
t_pile	*ft_fill_tab(int argc, char **argv);
int		ft_count(const char *str);
int		ft_strs_is_ok(t_pile	*pile);

#endif