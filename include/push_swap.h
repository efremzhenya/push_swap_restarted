/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 15:51:51 by lseema            #+#    #+#             */
/*   Updated: 2020/10/11 00:12:58 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdio.h>

typedef struct			s_elem
{
	long long			value;
	int					index;
	int					flag;
	struct s_elem		*prev;
	struct s_elem		*next;
}						t_elem;

typedef struct			s_main
{

}						t_main;

int			validate_args(int argc, char **argv, t_elem **stack_a);
int			validate_num(char *argv);
int			is_num(char *word);
t_elem		*new_elem(int value);
void		add_elem(t_elem **stack, t_elem *elem);
int			is_contain(t_elem **stack, int num);
void		free_stack(t_elem **stack);

#endif
