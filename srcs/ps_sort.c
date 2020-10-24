/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:29:13 by lseema            #+#    #+#             */
/*   Updated: 2020/10/24 22:34:43 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		start_ps(t_elem **stack_a, t_elem **stack_b, t_main **main, t_cmd **cmds)
{
	if ((*main)->count == 2)
		add_cmd(cmds, do_cmd("sa", stack_a, stack_b));
	else if ((*main)->count == 3)
		sort_stack_of_3(stack_a, cmds);
	else
	{
		refactor_cmds(cmds);
	}
	print_cmds(cmds);
	return (1);
}

void	sort_stack_of_3(t_elem **stack_a, t_cmd **cmds)
{
	int one;
	int two;
	int three;

	one =(*stack_a)->index;
	two = (*stack_a)->next->index;
	three = (*stack_a)->next->next->index;
	if (one > two && two > three && three < one)
	{
		add_cmd(cmds, do_cmd("sa", stack_a, NULL));
		add_cmd(cmds, do_cmd("rra", stack_a, NULL));
	}
	else if (one < two && two > three && three > one)
	{
		add_cmd(cmds, do_cmd("rra", stack_a, NULL));
		add_cmd(cmds, do_cmd("sa", stack_a, NULL));
	}
	else if (one > two && two < three && three < one)
		add_cmd(cmds, do_cmd("ra", stack_a, NULL));
	else
		add_cmd(cmds, do_cmd((one < two && two > three && three < one)
			? "rra" : "sa", stack_a, NULL));
}
