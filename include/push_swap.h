/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 15:51:51 by lseema            #+#    #+#             */
/*   Updated: 2020/11/15 17:46:24 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef	struct		s_elem
{
	int				value;
	int				index;
	int				flag;
	int				sorted;
	struct s_elem	*prev;
	struct s_elem	*next;
}					t_elem;

typedef	struct		s_main
{
	int				count;
	int				max;
	int				mode;
	int				next;
	int				flag;
	int				any_sorted;
	int				koef;
}					t_main;

typedef	struct		s_cmd
{
	char			*cmd;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}					t_cmd;

int					init_main(t_main **main);
int					validate_args(int c, char **argv, t_elem **a, int chckr);
int					validate_num(char *argv);
t_elem				*new_elem(int value);
int					add_elem(t_elem **stack, t_elem *elem);
int					is_contain(t_elem **stack, int num);
void				free_stack(t_elem **stack);
void				free_cmds(t_cmd **cmds);
void				free_all(t_elem **a, t_elem **b, t_cmd **cmds, t_main **m);
void				set_indexes(t_elem **stack_a, size_t count, size_t i);
void				set_indexes_part2(t_elem **stack_a, int *arr);
int					is_sorted(t_elem **stack);
int					get_length(t_elem **stack);
int					is_mode_on(char *argv);
int					start_ps(t_elem **a, t_elem **b, t_main **main, t_cmd **c);
void				add_cmd(t_cmd **cmds, t_cmd *cmd);
t_cmd				*new_cmd(char *c);
t_cmd				*do_cmd(char *cmd, t_elem **a, t_elem **b, int alloc_cmd);
void				swap(t_elem **stack);
void				rotate(t_elem **stack);
void				rev_rotate(t_elem **stack);
void				push(t_elem **stack2, t_elem **stack1);
void				refactor_cmds(t_cmd **cmds);
void				print_cmds(t_cmd **cmds);
int					get_min_index(t_elem **stack_a);
void				sort_stack_of_3(t_elem **stack_a, t_cmd **cmds);
void				sort_stack_of_5(t_elem **a, t_elem **b, t_cmd **cmds);
void				sort_stack_of_4(t_elem **a, t_elem **b, t_cmd **cmds);
void				asc_sort_of_3(t_elem **stack_b, t_cmd **cmds);
void				read_cmds(t_elem **stack_a, t_elem **stack_b, int mode);
void				main_sort(t_elem **s, t_elem **b, t_main **m, t_cmd **c);
void				check_next(t_elem **a, t_elem **b, t_main **m, t_cmd **c);
void				check_next_b(t_elem **a, t_elem **b, t_main **m, t_cmd **c);
int					get_max_ind(t_elem **stack_a);
int					get_flag(t_elem **stack_a, int index);
int					validate_string(char *str, t_elem **stack_a);
void				part_a(t_elem **a, t_elem **b, t_main **main, t_cmd **cmds);
void				part_b(t_elem **a, t_elem **b, t_main **main, t_cmd **cmds);
void				part_c(t_elem **a, t_elem **b, t_main **main, t_cmd **cmds);
void				part_d(t_elem **a, t_elem **b, t_main **main, t_cmd **cmds);
void				draw(t_elem **stack_a, t_elem **stack_b);
void				draw_stack(t_elem *elem);

#endif
