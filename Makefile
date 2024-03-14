# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frankgar <frankgar@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 11:37:45 by frankgar          #+#    #+#              #
#    Updated: 2024/03/14 15:06:57 by frankgar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FLAGS = -Wall -Werror -Wextra -g #-fsanitize=address
INCLUDES = -I ./inc/\
           -I ./libft/\
		   -I ./Minilibx/
SRC = parsing.c parsing_utils.c main.c globals.c init_mlx.c utils.c \
		ilumination.c

DIR_SRC = ./src
DIR_OBJ = $(DIR_SRC)/obj
OBJ = $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))
DEP = $(addprefix $(DIR_OBJ)/, $(SRC:.c=.d))


all: dir $(NAME)

-include $(DEP)
dir:
	make -C ./libft/ --no-print-directory 
	mkdir -p $(DIR_OBJ)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c Makefile
	$(CC) -MMD $(FLAGS)  -c $< -o $@ $(INCLUDES)
$(NAME): $(OBJ) ./libft/libft.a
	$(CC) $(FLAGS) $(OBJ) ./Minilibx/libmlx.a -framework OpenGL -framework AppKit ./libft/libft.a -o $@ $(INCLUDES)
	echo "$(NAME) Created :D"
clean:
	rm -rf $(DIR_OBJ)
	make clean -C ./libft/ --no-print-directory 
	echo "DEPENDENCIES Erased :D"
fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft/ --no-print-directory 
	echo "EVERYTHING Erased D:"
re: fclean all
.PHONY: fclean all clean re dir
.SILENT:
