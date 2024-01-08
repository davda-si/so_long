# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 15:45:08 by davda-si          #+#    #+#              #
#    Updated: 2023/10/11 20:02:26 by davda-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c utils.c check_map.c alct_map.c flood.c error.c graph.c keys.c \
more_utils.c

CC = @cc

CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L. -lXext -L. -lX11

LIBFT_PATH = ./libs/libft
LIBFT = $(LIBFT_PATH)/libft.a

MINILIBX_PATH = ./libs/mlx_linux
MINILIBX = $(MINILIBX_PATH)/libmlx.a

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
	@make -s -C $(LIBFT_PATH)

$(MINILIBX):
	@make -s -C $(MINILIBX_PATH)

clean:
	@rm -f $(OBJS)
	
fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY:         all clean fclean re
