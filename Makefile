# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 11:12:25 by tgiraudo          #+#    #+#              #
#    Updated: 2022/12/08 11:01:17 by tgiraudo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

FLAGS		= -Wall -Wextra -Werror

CC 			= gcc

HEADER_PATH	= include/

HEADER		= ${HEADER_PATH}push_swap.h

INCLUDES 	= -I ${HEADER_PATH}

LIBFT 		= -L ./libft -lft 

SRCS		=	srcs/main.c			\
				srcs/ft_check.c		\
				srcs/ft.c			\
				srcs/push_swap.c	\
				
OBJS		= ${SRCS:.c=.o}

%.o 		: %.c ${HEADER} Makefile
				@${CC} ${FLAGS} ${INCLUDES} -c $< -o $@ 

${NAME}		: ${OBJS}
				@${MAKE} -C ./libft
				@${CC} -g3 ${OBJS} ${LIBFT} -o ${NAME}
				$(info The project compile well)

all			: ${NAME}

clean		:
				@rm -f ${OBJS}
				${info All object files are know deleted}

fclean		: clean
				@${MAKE} fclean -C ./libft
				@rm -f ${NAME}
				${info ${NAME} is know deleted}

re			: fclean all

.PHONY		: all clean fclean re