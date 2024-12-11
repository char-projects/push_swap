# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/23 01:15:04 by cschnath          #+#    #+#              #
#    Updated: 2024/12/11 13:39:53 by cschnath         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap

CFLAGS  = -Wall -Wextra -Werror
SRC		= checks.c errors.c init.c main.c push.c rev_rotate.c rotate.c sort.c swap.c switch.c utils.c utils2.c
OBJ		= ${SRC:.c=.o}
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	@gcc $(CFLAGS) $(OBJ) $(MLX) -o $(NAME) $(LIBFT)

$(LIBFT):
	@make -C libft/src

clean:
	@rm -rf $(OBJ)
	@make -C libft/src clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/src fclean

%.o: %.c
	@gcc $(CFLAGS) -o $@ -c $<

re: fclean all

.PHONY: all clean fclean re