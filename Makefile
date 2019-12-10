# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/29 15:59:04 by rsticks           #+#    #+#              #
#    Updated: 2019/12/10 18:10:42 by rsticks          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS_PATH = ./src/
SRCS_FILES = ft_printf.c main.c parser.c integer.c transform.c \
			additional.c u_integer.c o_integer.c x_integer.c
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))

LIB_SRCS_PATH = ./libft/
LIB_SRCS_FILES = ft_strcmp.c ft_putnbr.c ft_putchar_fd.c ft_atoi.c ft_itoa.c ft_strlen.c
LIB_SRCS = $(addprefix $(LIB_SRCS_PATH), $(LIB_SRCS_FILES))

LIB_OBJECTS_PATH = ./objs/
LIB_OBJECTS_FILES = $(LIB_SRCS_FILES:.c=.o)
LIB_OBJECTS = $(addprefix $(LIB_OBJECTS_PATH), $(LIB_OBJECTS_FILES))

OBJECTS_PATH = ./objs/
OBJECTS_FILES = $(SRCS_FILES:.c=.o)
OBJECTS = $(addprefix $(OBJECTS_PATH), $(OBJECTS_FILES))

COMPILE = gcc -Wall -Wextra

INCLUDES = -I./includes -I./libs/libft
HEADERS_PATH = ./includes/
HEADERS_FILES = ft_printf.h
HEADERS = $(addprefix $(HEADERS_PATH), $(HEADERS_FILES))

COLOR_RESET = \033[0m
COLOR_RENDERING = \033[0;33m
COLOR_SUCCESS = \033[0;32m

all: $(NAME)

$(NAME): $(OBJECTS) $(LIB_OBJECTS) $(HEADERS)
	@echo "$(COLOR_RENDERING)Compiling...$(COLOR_RESET)"
	@ar rc $(NAME) $(OBJECTS) $(LIB_OBJECTS) $(LIB)
	@ranlib $(NAME)
	@echo "\033[A\033[K\033[A"
	@echo "$(COLOR_SUCCESS)SUCCESS$(COLOR_RESET)"
	@echo "$(COLOR_SUCCESS)FINISHED$(COLOR_RESET)"

$(OBJECTS_PATH)%.o: $(SRCS_PATH)%.c
	@$(COMPILE) $(INCLUDES) -g -c $< -o $@

$(LIB_OBJECTS_PATH)%.o: $(LIB_SRCS_PATH)%.c
	@$(COMPILE) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(COLOR_RENDERING)Cleaning...$(COLOR_RESET)"
	@rm -f $(OBJECTS)
	@rm -f $(LIB_OBJECTS)
	@echo "\033[A\033[K\033[A"
	@echo "$(COLOR_SUCCESS)OK$(COLOR_RESET)"

fclean: clean
	@rm -f $(NAME)
	@rm -f ft_printf
re: fclean all

main: all

	@$(COMPILE) -o ft_printf $(OBJECTS) libft/libft.a
	@echo "$(COLOR_SUCCESS)OK$(COLOR_RESET)"