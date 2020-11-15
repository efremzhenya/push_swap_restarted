/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 04:12:23 by lseema            #+#    #+#             */
/*   Updated: 2020/11/15 17:47:06 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	part_a(t_elem **a, t_elem **b, t_main **main, t_cmd **cmds)
{
	int		mid;
	int		len;
	int		i;

	i = 0;
	mid = ((*main)->max - (*main)->next) / 2 + (*main)->next;
	(*main)->flag++;
	len = (*main)->max - (*main)->next + 1;
	while (len > i && (*main)->max - mid + 1 > get_length(b))
	{
		add_cmd(cmds, do_cmd((*a)->index + 1 <= mid ? "pb" : "ra", a, b, 1));
		i++;
	}
	i = i - get_length(b);
	while ((*main)->any_sorted && i--)
		if (*b && (*b)->index + 1 != (*main)->next)
			add_cmd(cmds, do_cmd("rrr", a, b, 1));
		else
			add_cmd(cmds, do_cmd("rra", a, b, 1));
	(*main)->max = mid;
}

void	part_b(t_elem **a, t_elem **b, t_main **main, t_cmd **cmds)
{
	while (get_length(b) > 1)
	{
		if (get_length(b) == 2)
		{
			if ((*b)->next->index + 1 == (*main)->next)
				add_cmd(cmds, do_cmd("rb", a, b, 1));
			check_next_b(a, b, main, cmds);
			break ;
		}
		part_c(a, b, main, cmds);
		(*main)->flag++;
	}
}

void	part_c(t_elem **a, t_elem **b, t_main **main, t_cmd **cmds)
{
	int		mid;
	int		len;
	int		i;

	i = 0;
	(*main)->max = get_max_ind(b) + 1;
	len = get_length(b) / 2;
	mid = (*main)->max - len;
	while (len > i && get_length(b) > (len / 2))
	{
		if ((*b) && ((*b)->index + 1 == (*main)->next))
			while ((*b) && ((*b)->index + 1 == (*main)->next) && len++)
			{
				add_cmd(cmds, do_cmd("pa", a, b, 1));
				check_next(a, b, main, cmds);
			}
		else if ((*b)->index + 1 >= mid)
			part_d(a, b, main, cmds);
		else
			add_cmd(cmds, do_cmd("rb", a, b, 1));
		check_next_b(a, b, main, cmds);
		i++;
	}
}

void	part_d(t_elem **a, t_elem **b, t_main **main, t_cmd **cmds)
{
	if ((*b)->index >= get_max_ind(b) - (*main)->koef)
	{
		(*b)->flag = (*main)->flag;
		add_cmd(cmds, do_cmd("pa", a, b, 1));
	}
	else
		add_cmd(cmds, do_cmd("rb", a, b, 1));
	check_next(a, b, main, cmds);
}

void	main_sort(t_elem **a, t_elem **b, t_main **main, t_cmd **cmds)
{
	(*main)->max = (*main)->count;
	check_next(a, b, main, cmds);
	check_next_b(a, b, main, cmds);
	if ((*a)->flag > 0 && (*a)->sorted == 0)
	{
		(*main)->flag = (*a)->flag;
		(*main)->max = (*a)->index + 1;
		while ((*a)->sorted == 0 && (*a)->flag >= get_flag(a, (*main)->next)
			&& get_flag(a, (*main)->next) != -1)
			if ((*a)->index + 1 == (*main)->next
				|| (*a)->next->index + 1 == (*main)->next)
				check_next(a, b, main, cmds);
			else
			{
				(*main)->max = (*a)->index + 1 > (*main)->max ?
					(*a)->index + 1 : (*main)->max;
				add_cmd(cmds, do_cmd("pb", a, b, 1));
			}
	}
	else
		part_a(a, b, main, cmds);
	part_b(a, b, main, cmds);
}
