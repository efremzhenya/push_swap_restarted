# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/27 16:30:25 by lseema            #+#    #+#              #
#    Updated: 2020/11/15 18:07:31 by lseema           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
CHECKER = checker
CC = gcc -Wall -Wextra -Werror
SRC_DIR = srcs/
LIBFT_DIR = libft/
OBJ_DIR = obj/
PS_SRCS = push_swap.c\
	validation.c\
	lst_management.c\
	cmd_management.c\
	cleaners.c\
	ps_helpers.c\
	ps_sort.c\
	instructions.c\
	mods.c\
	main_sort.c
CHECKER_SRCS = checker.c\
	validation.c\
	lst_management.c\
	cmd_management.c\
	cleaners.c\
	instructions.c\
	mods.c\
	ps_helpers.c

PS_OBJ = ${PS_SRCS:c=o}
CHECKER_OBJ = ${CHECKER_SRCS:c=o}

all: $(PUSH_SWAP) $(CHECKER)

$(addprefix $(OBJ_DIR), %.o): $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) -I libft/ -I include/ -c -o $@ $^

$(PUSH_SWAP): $(addprefix $(OBJ_DIR), $(PS_OBJ))
	@make -C libft/
	@$(CC) $(addprefix $(OBJ_DIR), $(PS_OBJ)) $(LIBFT_DIR)libft.a -I libft/ -o $(PUSH_SWAP)
	@echo "push_swap compiled"

$(CHECKER): $(addprefix $(OBJ_DIR), $(CHECKER_OBJ))
	$(CC) $(addprefix $(OBJ_DIR), $(CHECKER_OBJ)) $(LIBFT_DIR)libft.a -I libft/ -I includes/ -o $(CHECKER)
	@echo "checker compiled"

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(PUSH_SWAP)
	@rm -f $(CHECKER)

re: fclean all
