# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/29 12:03:29 by bmuselet          #+#    #+#              #
#    Updated: 2018/01/29 12:03:32 by bmuselet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

SRC_PATH = 	srcs
SRC_NAME = 	main.c\
			reader.c\
			init_camera.c\
			vector_calc1.c\
			vector_calc2.c\
			key.c\
			draw.c\
			sphere.c\
			cone.c\
			light.c\
			plan_cylindre.c\
			light.c\
			utils.c\
			utils2.c\
			init_data.c\
			exit_properly.c\
			init_objects.c\
			check_objects.c\
			color.c\
			transformations.c\
			
			
OBJ_PATH = objs
OBJ_NAME = $(SRC_NAME:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

CPPFLAGS = -I includes -I libft/libft.h

LDFLAGS = -L libft
LDLIBS = -lft -lm -lmlx -framework OpenGL -framework AppKit

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: libft $(NAME)

$(NAME): $(OBJ) libft/libft.a
	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@echo "\033[1;91mCompilation rtv1 complete !\033[0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $< $(CPPFLAGS) -o $@

libft:
	@make -C libft

clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "\033[1;91m$(OBJ_NAME) removed !\033[0m"

fclean:
	@make -C libft fclean
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "\033[1;91m$(OBJ_NAME) removed !\033[0m"
	@rm -f $(NAME)
	@echo "\033[1;91m$(NAME) removed !\033[0m"

re: fclean all

norme:
	norminette $(SRC)
	norminette includes/*.h

.PHONY: all clean fclean re libft norme
