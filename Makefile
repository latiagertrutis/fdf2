# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 17:20:08 by mrodrigu          #+#    #+#              #
#    Updated: 2018/04/26 07:59:58 by mrodrigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : compile norme all clean fclean re

NAME = fdf

INCL_DIR = includes/

FLAGS = -Wall -Wextra 

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

MLX_LINUX = -lm -L/usr/local/lib/ -lmlx -lX11 -lXext 

FUNCTIONS = input_reader.c \
			success.c \
			exit_failure.c \
			window.c \
			hooks.c \
			key_pressed.c \
			leave_program.c \
			print_map.c \
			draw_line.c \
			line_interpret.c \
			resize_point.c \
			traslate_point.c \
			rotate_point.c \
			line_writter.c \
			main.c \
			create_image.c \
			project_point.c \
			put_legend.c \
			update_legend.c \
			restart.c \
			end_fdf.c \
			free_list_map.c

HEADERS = $(INCL_DIR)fdf.h

GNL_FUNC = get_next_line.c

LIBFT = libft/libft.a

LIBFT_DIR = libft/

SRC_DIR = srcs/

GNL_DIR = get_next_line/

OBJ_DIR = objects/

FUNCTION_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(FUNCTIONS))

GNL_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(GNL_FUNC))

UNAME = $(shell uname -s)

ifeq ($(UNAME),Linux)
	COMPILER = gcc $(FLAGS) $(FUNCTION_OBJ) $(GNL_OBJ) -o $(NAME) $(MLX_LINUX) -I $(INCL_DIR) $(LIBFT)
else
	COMPILER = gcc $(FLAGS) $(FUNCTION_OBJ) $(GNL_OBJ) -o $(NAME) $(MLX_FLAGS) -I $(INCL_DIR) $(LIBFT)
endif

all : $(NAME)

$(NAME) : $(FUNCTION_OBJ) $(LIBFT) $(GNL_OBJ) $(HEADERS)
	$(COMPILER)
$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	gcc $(FLAGS) -I$(INCL_DIR) -c $<
	mkdir -p $(OBJ_DIR)
	mv -f $(@F) $(OBJ_DIR)

$(OBJ_DIR)%.o : $(GNL_DIR)%.c
	gcc $(FLAGS) -I$(INCL_DIR) -c $<
	mkdir -p $(OBJ_DIR)
	mv -f $(@F) $(OBJ_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean
	make

test:
	make
	gcc $(FLAGS) $(FUNCTION_OBJ) $(GNL_OBJ) -o $(NAME) $(MLX_FLAGS) -I $(INCL_DIR) $(LIBFT)

linux:
	make
	gcc $(FLAGS) $(FUNCTION_OBJ) $(GNL_OBJ) -o $(NAME) $(MLX_LINUX) -I $(INCL_DIR) $(LIBFT)
