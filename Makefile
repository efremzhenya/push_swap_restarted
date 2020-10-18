# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/27 16:30:25 by lseema            #+#    #+#              #
#    Updated: 2020/10/18 20:00:12 by lseema           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
# CC = gcc -g -Wall -Wextra -Werror
CC = gcc -g
SRC_DIR = srcs/
LIBFT_DIR = libft/
OBJ_DIR = obj/
PS_SRCS = push_swap.c validation.c lst.c cleaners.c ps_helpers.c ps_sort.c

PS_OBJ = ${PS_SRCS:c=o}

all: $(PUSH_SWAP)

$(addprefix $(OBJ_DIR), %.o): $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -I libft/ -I include/ -c -o $@ $^

$(PUSH_SWAP): $(addprefix $(OBJ_DIR), $(PS_OBJ))
	@$(CC) $(addprefix $(OBJ_DIR), $(PS_OBJ)) $(LIBFT_DIR)libft.a -I libft/ -o $(PUSH_SWAP)
	@echo "push_swap compiled"

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(PUSH_SWAP)

re: fclean all
