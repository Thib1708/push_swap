# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 11:12:25 by tgiraudo          #+#    #+#              #
#    Updated: 2023/03/15 11:04:40 by tgiraudo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

FLAGS		= -Wall -Wextra -Werror

MAKEFLAGS += --no-print-directory

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

all			: ascii ${NAME}

${DIR_OBJS}%.o 		: %.c ${HEADER} Makefile
				@mkdir -p $(shell dirname $@)
				@printf "${YELLOW}\033[2KCreating ${NAME}'s objects : $@\r"
				@${CC} ${FLAGS} ${INCLUDES} -c $< -o $@ 
				@printf "${GREEN}\033[2KCreating ${NAME}'s objects : DONE\r"

${NAME}		:ascii lib ${OBJS}
				@printf "\n${YELLOW}Compiling ${NAME}..."
				@${CC} ${OBJS} ${LIBFT} -o ${NAME}
				@echo "\r${GREEN}Compiling ${NAME} : DONE${DEFAULT}"

lib :
		@make -C ./libft

ascii :
		@printf "$$ASCII"

clean		:
				@echo "${RED}Deleting objects..."
				@rm -rf ${DIR_OBJS}

fclean		: clean
				@echo "${RED}Cleaning libft..."
				@${MAKE} fclean -C ./libft
				@echo "${RED}Deleting executable...\n${DEFAULT}"
				@rm -f ${NAME}

re			: fclean all

define ASCII
                 _                               
                | |                              
 _ __  _   _ ___| |__    _____      ____ _ _ __  
| '_ \| | | / __| '_ \  / __\ \ /\ / / _` | '_ \ 
| |_) | |_| \__ \ | | | \__ \\\ V  V / (_| | |_) |
| .__/ \__,_|___/_| |_| |___/ \_/\_/ \__,_| .__/ 
| |                                       | |    
|_|                                       |_|    


endef
export ASCII


${DIR_OBJS} :
				mkdir -p ${DIR_OBJS}
.PHONY		: all clean fclean re

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m