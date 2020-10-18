/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 15:51:51 by lseema            #+#    #+#             */
/*   Updated: 2020/10/18 20:08:20 by lseema           ###   ########.fr       */
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
	size_t				count;
	int					mode;
	int					max;
	int					flag;
}						t_main;

typedef struct			s_cmd
{
	char				*cmd;
	struct s_cmd		*prev;
	struct s_cmd		*next;
}						t_cmd;

int			validate_args(int argc, char **argv, t_elem **stack_a);
int			validate_num(char *argv);
int			is_num(char *word);
t_elem		*new_elem(int value);
void		add_elem(t_elem **stack, t_elem *elem);
int			is_contain(t_elem **stack, int num);
void		free_stack(t_elem **stack);
void		set_indexes(t_elem **stack_a, int count);
int			is_sorted(t_elem **stack);
size_t		get_length(t_elem **stack);
int			is_mode_on(char *argv);
int			init(t_elem **stack_a, t_elem **stack_b, t_main **main, t_cmd ** cmds);
int			start_ps(t_elem **stack_a, t_elem **stack_b, t_main **main, t_cmd **cmds);

#endif
