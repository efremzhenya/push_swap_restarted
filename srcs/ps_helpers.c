/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 20:17:43 by lseema            #+#    #+#             */
/*   Updated: 2020/11/15 17:42:54 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	set_indexes(t_elem **stack_a, size_t j, size_t i)
{
	int		arr[j];
	int		value;
	t_elem	*tmp;

	tmp = *stack_a;
	arr[i++] = tmp->value;
	while ((tmp = tmp->next))
		arr[i++] = tmp->value;
	while (j > 1)
	{
		i = 0;
		while (i < j - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				value = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = value;
			}
			i++;
		}
		j--;
	}
	set_indexes_part2(stack_a, arr);
}

void	set_indexes_part2(t_elem **stack_a, int *arr)
{
	t_elem	*tmp;
	int		i;

	tmp = *stack_a;
	while (tmp)
	{
		i = 0;
		while (tmp->value != arr[i])
			i++;
		tmp->index = i;
		tmp = tmp->next;
	}
}

void	check_next(t_elem **a, t_elem **b, t_main **main, t_cmd **cmds)
{
	while ((*a)->index + 1 == (*main)->next
		|| (*a)->next->index + 1 == (*main)->next)
	{
		if ((*a)->next->index + 1 == (*main)->next)
		{
			if (*b && (*b)->next && (*b)->next->index + 1 == (*main)->next + 1)
				add_cmd(cmds, do_cmd("ss", a, b, 1));
			else
				add_cmd(cmds, do_cmd("sa", a, b, 1));
		}
		(*a)->sorted = 1;
		add_cmd(cmds, do_cmd("ra", a, b, 1));
		(*main)->next++;
		(*main)->any_sorted = 1;
	}
}

void	check_next_b(t_elem **a, t_elem **b, t_main **main, t_cmd **cmds)
{
	if ((*b) && ((*b)->index + 1 == (*main)->next))
	{
		while ((*b) && ((*b)->index + 1 == (*main)->next))
		{
			add_cmd(cmds, do_cmd("pa", a, b, 1));
			check_next(a, b, main, cmds);
		}
	}
}

int		get_flag(t_elem **stack_a, int index)
{
	t_elem	*tmp;

	index--;
	if (!stack_a || !*stack_a)
		return (-1);
	tmp = (*stack_a)->next;
	while (tmp && tmp->index != index)
		tmp = tmp->next;
	if (!tmp)
		return (-1);
	return (tmp->flag);
}
