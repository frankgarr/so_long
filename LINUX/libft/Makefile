# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frankgar <frankgar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/17 20:46:05 by frankgar          #+#    #+#              #
#    Updated: 2024/02/23 13:02:29 by frankgar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

SRC = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strlen.c \
		ft_strrchr.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c  ft_putnbr_fd.c \
		get_next_line.c get_next_line_utils.c \
		ft_printf.c ft_fd_printf.c

DIR_OBJ = ./obj
OBJ = $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))
DEP = $(addprefix $(DIR_OBJ)/, $(SRC:.c=.d))

all: dir $(NAME)

dir:
	mkdir -p $(DIR_OBJ)

$(DIR_OBJ)/%.o: %.c Makefile
	$(CC) $(CFLAGS) -MMD -c $< -o $@
	echo "Compiling: $<"

$(NAME): $(OBJ) Makefile 
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -rf $(DIR_OBJ) $(DIR_DEP)

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(DEP)
.PHONY: fclean all clean re
.SILENT:
