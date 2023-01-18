# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 11:12:25 by tgiraudo          #+#    #+#              #
#    Updated: 2022/12/13 12:25:38 by tgiraudo         ###   ########.fr        #
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
				srcs/instruction.c	\
				srcs/ft_sort.c		\
				srcs/ft_fill_tab.c	\
				srcs/utils.c		\
				
OBJS		= ${SRCS:.c=.o}

%.o 		: %.c ${HEADER} Makefile
				@${CC} ${FLAGS} ${INCLUDES} -c $< -o $@ 

${NAME}		: ${OBJS}
				@${MAKE} -C ./libft
				@${CC} -g3 ${OBJS} ${LIBFT} -o ${NAME}
				@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

all			: ${NAME}

clean		:
				@rm -f ${OBJS}
				@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean		: clean
				@${MAKE} fclean -C ./libft
				@rm -f ${NAME}
				@echo "$(RED)${NAME} deleted!$(DEFAULT)"

re			: fclean all

.PHONY		: all clean fclean re

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m