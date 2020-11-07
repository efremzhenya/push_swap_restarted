/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 15:51:51 by lseema            #+#    #+#             */
/*   Updated: 2020/11/07 05:01:23 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdio.h>

typedef struct			s_elem
{
	int					value;
	int					index;
	int					flag;
	int					sorted;
	struct s_elem		*prev;
	struct s_elem		*next;
}						t_elem;

typedef struct			s_main
{
	size_t				count;
	size_t				max;
	int					mode;
	int					next;
	int					flag;
	int					any_sorted;
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
void		free_cmds(t_cmd **cmds);
void		set_indexes(t_elem **stack_a, int count);
int			is_sorted(t_elem **stack);
size_t		get_length(t_elem **stack);
int			is_mode_on(char *argv);
int			init(t_elem **stack_a, t_elem **stack_b, t_main **main, t_cmd ** cmds);
int			start_ps(t_elem **stack_a, t_elem **stack_b, t_main **main, t_cmd **cmds);
void		add_cmd(t_cmd **cmds, t_cmd *cmd);
t_cmd		*new_cmd(char *c);
t_cmd		*do_cmd(char *cmd, t_elem **stack_a, t_elem **stack_b, int allocate_cmd);
void		swap(t_elem **stack);
void		rotate(t_elem **stack);
void		rev_rotate(t_elem **stack);
void		push(t_elem **stack2, t_elem **stack1);
void		sort_stack_of_3(t_elem **stack_a, t_cmd **cmds);
void		refactor_cmds(t_cmd **cmds);
void		print_cmds(t_cmd **cmds);
int			get_min_index(t_elem **stack_a);
void		sort_stack_of_5(t_elem **stack_a, t_elem **stack_b, t_cmd **cmds);
void		sort_stack_of_4(t_elem **stack_a, t_elem **stack_b, t_cmd **cmds);
void		read_cmds(t_elem **stack_a, t_elem **stack_b);
void		main_sort(t_elem **stack_a, t_elem **stack_b, t_main **main, t_cmd **cmds);
int			get_max_index(t_elem **stack_a, int flag);
void		check_next(t_elem **stack_a, t_elem **stack_b, t_main **main, t_cmd **cmds);
size_t		get_length_flag(t_elem **stack, int flag);
int			get_max_ind(t_elem **stack_a);
int			get_flag(t_elem **stack_a, int	index);
void		asc_sort_of_3(t_elem **stack_b, t_cmd **cmds);
void	check_next_b(t_elem **stack_a, t_elem **stack_b, t_main **main, t_cmd **cmds, int len_b);

#endif
