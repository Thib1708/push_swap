# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 11:12:25 by tgiraudo          #+#    #+#              #
#    Updated: 2023/01/17 18:46:54 by tgiraudo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

FLAGS		= -Wall -Wextra -Werror

CC 			= gcc

HEADER_PATH	= include/

DIR_OBJS = .objs/

DIR_SRCS = srcs/

HEADER		= ${HEADER_PATH}push_swap.h

INCLUDES 	= -I ${HEADER_PATH}

LIBFT 		= -L ./libft -lft 

LIST_SRCS		=	main.c			\
				ft_check.c			\
				ft_instruction.c	\
				ft_sort.c			\
				ft_fill_tab.c		\
				ft_utils.c			\

OBJS = $(patsubst %.c, $(DIR_OBJS)%.o, $(SRCS))

SRCS = ${addprefix ${DIR_SRCS}, ${LIST_SRCS}}

all			: ${NAME}

${DIR_OBJS}%.o 		: %.c 
				@mkdir -p $(shell dirname $@)
				@printf "${YELLOW}\033[2KCreating ${NAME}'s objects : $@\r"
				@${CC} -g3 ${FLAGS} ${INCLUDES} -c $< -o $@ 
				@printf "${GREEN}\033[2KCreating ${NAME}'s objects : DONE\r"

${NAME}		: lib ${OBJS}
				@printf "\n\n${YELLOW}Compiling ${NAME}..."
				@${CC} -g3 ${OBJS} ${LIBFT} -o ${NAME}
				@echo "\r${GREEN}Compiling ${NAME} : DONE${DEFAULT}\n"

lib :
		@make -C ./libft

clean		:
				@echo "${RED}Deleting objects..."
				@rm -rf ${DIR_OBJS}

fclean		: clean
				@echo "\n${RED}Cleaning libft..."
				@${MAKE} fclean -C ./libft
				@echo "\n${RED}Deleting executable...\n${DEFAULT}"
				@rm -f ${NAME}

re			: fclean all

${DIR_OBJS} :
				mkdir -p ${DIR_OBJS}
.PHONY		: all clean fclean re

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m