/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:29:13 by lseema            #+#    #+#             */
/*   Updated: 2020/11/15 17:43:08 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		start_ps(t_elem **a, t_elem **b, t_main **main, t_cmd **cmds)
{
	if ((*main)->count == 2)
		add_cmd(cmds, do_cmd("sa", a, b, 1));
	else if ((*main)->count == 3)
		sort_stack_of_3(a, cmds);
	else if ((*main)->count == 4)
		sort_stack_of_4(a, b, cmds);
	else if ((*main)->count == 5)
		sort_stack_of_5(a, b, cmds);
	else
	{
		if ((*main)->count >= 400)
			(*main)->koef = 18;
		else
			(*main)->koef = (*main)->count >= 100 ? 5 : 1;
		while (!is_sorted(a) || get_length(b) > 0)
			main_sort(a, b, main, cmds);
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

	one = (*stack_a)->index;
	two = (*stack_a)->next->index;
	three = (*stack_a)->next->next->index;
	if (one > two && two > three && three < one)
	{
		add_cmd(cmds, do_cmd("sa", stack_a, NULL, 1));
		add_cmd(cmds, do_cmd("rra", stack_a, NULL, 1));
	}
	else if (one < two && two > three && three > one)
	{
		add_cmd(cmds, do_cmd("rra", stack_a, NULL, 1));
		add_cmd(cmds, do_cmd("sa", stack_a, NULL, 1));
	}
	else if (one > two && two < three && three < one)
		add_cmd(cmds, do_cmd("ra", stack_a, NULL, 1));
	else if (one < two && two > three && three < one)
		add_cmd(cmds, do_cmd("rra", stack_a, NULL, 1));
	else if (one > two && two < three && three > one)
		add_cmd(cmds, do_cmd("sa", stack_a, NULL, 1));
}

void	sort_stack_of_4(t_elem **stack_a, t_elem **stack_b, t_cmd **cmds)
{
	int		min_index;

	if ((min_index = get_min_index(stack_a)) == -1)
		return ;
	while ((*stack_a)->index != min_index)
	{
		if ((*stack_a)->next->index == min_index)
			add_cmd(cmds, do_cmd("ra", stack_a, NULL, 1));
		else
			add_cmd(cmds, do_cmd("rra", stack_a, NULL, 1));
	}
	add_cmd(cmds, do_cmd("pb", stack_a, stack_b, 1));
	sort_stack_of_3(stack_a, cmds);
	add_cmd(cmds, do_cmd("pa", stack_a, stack_b, 1));
}

void	sort_stack_of_5(t_elem **stack_a, t_elem **stack_b, t_cmd **cmds)
{
	t_elem	*tmp;

	tmp = *stack_a;
	while ((*stack_a)->index != 0)
	{
		if ((*stack_a)->next->index == 0 || (*stack_a)->next->next->index == 0)
			add_cmd(cmds, do_cmd("ra", stack_a, NULL, 1));
		else
			add_cmd(cmds, do_cmd("rra", stack_a, NULL, 1));
	}
	add_cmd(cmds, do_cmd("pb", stack_a, stack_b, 1));
	sort_stack_of_4(stack_a, stack_b, cmds);
	add_cmd(cmds, do_cmd("pa", stack_a, stack_b, 1));
}

void	asc_sort_of_3(t_elem **stack_b, t_cmd **cmds)
{
	int one;
	int two;
	int three;

	one = (*stack_b)->index;
	two = (*stack_b)->next->index;
	three = (*stack_b)->next->next->index;
	if (one < two && two > three && three < one)
		add_cmd(cmds, do_cmd("sb", NULL, stack_b, 1));
	else if (one > two && two < three && three > one)
		add_cmd(cmds, do_cmd("rrb", NULL, stack_b, 1));
	else if (one < two && two > three && three > one)
		add_cmd(cmds, do_cmd("rb", NULL, stack_b, 1));
	else if (one > two && two < three && three < one)
	{
		add_cmd(cmds, do_cmd("sb", NULL, stack_b, 1));
		add_cmd(cmds, do_cmd("rb", NULL, stack_b, 1));
	}
	else if (one < two && two < three && three > one)
	{
		add_cmd(cmds, do_cmd("rb", NULL, stack_b, 1));
		add_cmd(cmds, do_cmd("sb", NULL, stack_b, 1));
	}
}
