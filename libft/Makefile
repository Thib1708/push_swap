# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 12:53:06 by tgiraudo          #+#    #+#              #
#    Updated: 2023/01/15 13:28:30 by tgiraudo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

FLAGS = -Wall -Wextra -Werror

DIR_OBJS = .objs/

OBJS = $(patsubst %.c, $(DIR_OBJS)%.o, $(SRCS))

INCLUDES		= -I ${HEADERS_PATH}

HEADERS_PATH = headers/

HEADERS =	${HEADERS_PATH}ft_printf.h \
			${HEADERS_PATH}get_next_line.h \
			${HEADERS_PATH}get_next_line_bonus.h \
			${HEADERS_PATH}libft.h

SRCS	=	libft/ft_strlen.c				\
			libft/ft_isalpha.c				\
			libft/ft_isalnum.c				\
			libft/ft_isprint.c 				\
			libft/ft_isascii.c 				\
			libft/ft_isdigit.c 				\
			libft/ft_memcpy.c 				\
			libft/ft_memmove.c				\
			libft/ft_bzero.c				\
			libft/ft_memset.c				\
			libft/ft_strlcpy.c				\
			libft/ft_strlcat.c				\
			libft/ft_toupper.c				\
			libft/ft_tolower.c				\
			libft/ft_strncmp.c				\
			libft/ft_strchr.c				\
			libft/ft_strrchr.c				\
			libft/ft_memchr.c				\
			libft/ft_atoi.c					\
			libft/ft_memcmp.c				\
			libft/ft_strnstr.c				\
			libft/ft_split.c				\
			libft/ft_calloc.c				\
			libft/ft_strdup.c				\
			libft/ft_substr.c				\
			libft/ft_strjoin.c				\
			libft/ft_strtrim.c				\
			libft/ft_itoa.c					\
			libft/ft_strmapi.c				\
			libft/ft_striteri.c				\
			libft/ft_putchar_fd.c			\
			libft/ft_putstr_fd.c			\
			libft/ft_putendl_fd.c			\
			libft/ft_putnbr_fd.c			\
			libft/ft_lstnew_bonus.c			\
			libft/ft_lstadd_front_bonus.c	\
			libft/ft_lstsize_bonus.c		\
			libft/ft_lstlast_bonus.c		\
			libft/ft_lstdelone_bonus.c		\
			libft/ft_lstadd_back_bonus.c	\
			libft/ft_lstclear_bonus.c		\
			libft/ft_lstiter_bonus.c		\
			libft/ft_lstmap_bonus.c			\
\
			get_next_line/get_next_line.c				\
			get_next_line/get_next_line_utils.c			\
			get_next_line/get_next_line_bonus.c			\
			get_next_line/get_next_line_utils_bonus.c	\
\
			printf/ft_printf_utils_2.c	\
			printf/ft_printf_utils.c	\
			printf/ft_printf.c


${DIR_OBJS}%.o	:	%.c ${HEADERS} Makefile
			@mkdir -p $(shell dirname $@)
			@printf "${YELLOW}\033[2KCreating libft's objects : $@\r"
			@cc ${FLAGS} ${INCLUDES} -c $< -o $@
			@printf "${GREEN}\033[2KCreating libft's objects : DONE\r"

${NAME}			:	${OBJS}
			@printf "\n\n${YELLOW}Compiling libft..."
			@ar rc ${NAME} ${OBJS}
			@echo "\r${GREEN}Compiling libft : DONE${DEFAULT}\n"

all	:	${NAME}

clean:
			@rm -rf ${DIR_OBJS}

fclean:		clean
			@rm -f ${NAME}

re:			fclean all

.PHONY: all clean fclean re

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m