/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 04:12:23 by lseema            #+#    #+#             */
/*   Updated: 2020/11/07 08:49:52 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	main_sort(t_elem **stack_a, t_elem **stack_b, t_main **main, t_cmd **cmds)
{
	size_t	mid;
	int		i;
	int		len_b;
	int		count;

	while (!is_sorted(stack_a) || get_length(stack_b) > 0)
	{
		i = 0;
		(*main)->max = (*main)->count;
		check_next(stack_a, stack_b, main, cmds);
		check_next_b(stack_a, stack_b, main, cmds, 0);
		if ((*stack_a)->flag > 0 && (*stack_a)->sorted == 0)
		{
			(*main)->flag = (*stack_a)->flag;
			(*main)->max = (*stack_a)->index + 1;
			while ((*stack_a)->sorted == 0 && (*stack_a)->flag >= get_flag(stack_a, (*main)->next) && get_flag(stack_a, (*main)->next) != -1)
			{
				if ((*stack_a)->index + 1 == (*main)->next || (*stack_a)->next->index + 1 == (*main)->next)
				{
					check_next(stack_a, stack_b, main, cmds);
				}
				else
				{
					(*main)->max = (*stack_a)->index + 1 > (*main)->max ? (*stack_a)->index + 1 : (*main)->max;
					add_cmd(cmds, do_cmd("pb", stack_a, stack_b, 1));
				}
			}
		}
		else
		{
			mid = ((*main)->max - (*main)->next) / 2 + (*main)->next;
			(*main)->flag++;
			len_b = (*main)->max - (*main)->next + 1;
			while (len_b > i && (*main)->max - mid + 1 > get_length(stack_b))
			{
				if ((*stack_a)->index + 1 <= mid)
					add_cmd(cmds, do_cmd("pb", stack_a, stack_b, 1));
				else
					add_cmd(cmds, do_cmd("ra", stack_a, stack_b, 1));
				i++;
			}

			i = i - get_length(stack_b);
			while ((*main)->any_sorted && i--)
			{
				if (*stack_b && (*stack_b)->index + 1 != (*main)->next)
					add_cmd(cmds, do_cmd("rrr", stack_a, stack_b, 1));
				else
					add_cmd(cmds, do_cmd("rra", stack_a, stack_b, 1));
			}
			(*main)->max = mid;
		}

		while (get_length(stack_b) > 0)
		{
			if (get_length(stack_b) == 1)
				break;
			else if (get_length(stack_b) == 2)
			{
				if ((*stack_b)->next->index + 1 == (*main)->next)
					add_cmd(cmds, do_cmd("rb", stack_a, stack_b, 1));
				check_next_b(stack_a, stack_b, main, cmds, 0);
				break;
			}

			len_b = get_length(stack_b);
			(*main)->max = get_max_ind(stack_b) + 1;
			mid = (*main)->max - (len_b / 2); // (*main)->max / 2 + (*main)->next;
			i = 0;
			while (len_b > i && get_length(stack_b) > (len_b / 2))
			{
				if ((*stack_b) && ((*stack_b)->index + 1 == (*main)->next)) //|| (((*stack_b)->next) && (*stack_b)->next->index + 1 == (*main)->next)))
				{
					while ((*stack_b) && ((*stack_b)->index + 1 == (*main)->next))// || (((*stack_b)->next) && (*stack_b)->next->index + 1 == (*main)->next)))
					{
						// if ((*stack_b)->next && (*stack_b)->next->index + 1 == (*main)->next)
						// 	add_cmd(cmds, do_cmd("sb", stack_a, stack_b, 1));
						add_cmd(cmds, do_cmd("pa", stack_a, stack_b, 1));
						check_next(stack_a, stack_b, main, cmds);
						len_b++;
					}
				}
				else if ((*stack_b)->index + 1 >= mid)
				{
					int koef = 1;
					if ((*main)->count >= 400)
						koef = 18;
					else if ((*main)->count >= 100)
						koef = 5;

					if ((*stack_b)->index >= get_max_ind(stack_b) - koef)
					{
						(*stack_b)->flag = (*main)->flag;
						add_cmd(cmds, do_cmd("pa", stack_a, stack_b, 1));
					}
					else
						add_cmd(cmds, do_cmd("rb", stack_a, stack_b, 1));

					check_next(stack_a, stack_b, main, cmds);
				}
				else
				{
					add_cmd(cmds, do_cmd("rb", stack_a, stack_b, 1));
				}
				check_next_b(stack_a, stack_b, main, cmds, len_b);
				i++;
			}
			(*main)->flag++;

		}
	}
}

void	check_next(t_elem **stack_a, t_elem **stack_b, t_main **main, t_cmd **cmds)
{
	t_elem	*tail;

	while ((*stack_a)->index + 1 == (*main)->next || (*stack_a)->next->index + 1 == (*main)->next)
	{
		if ((*stack_a)->next->index + 1 == (*main)->next)
		{
			if ((*stack_b) && (*stack_b)->next && (*stack_b)->next->index + 1 == (*main)->next + 1)
				add_cmd(cmds, do_cmd("ss", stack_a, stack_b, 1));
			else
				add_cmd(cmds, do_cmd("sa", stack_a, stack_b, 1));
		}
		(*stack_a)->sorted = 1;
		add_cmd(cmds, do_cmd("ra", stack_a, stack_b, 1));
		(*main)->next++;
		(*main)->any_sorted = 1;
		// tail = *stack_b;
		// while (tail && tail->next)
		// 	tail = tail->next;
		// if (tail && tail->index + 1 == (*main)->next)
		// 	add_cmd(cmds, do_cmd("rrb", stack_a, stack_b, 1));
	}
}

void	check_next_b(t_elem **stack_a, t_elem **stack_b, t_main **main, t_cmd **cmds, int len_b)
{
	if ((*stack_b) && ((*stack_b)->index + 1 == (*main)->next)) //|| (((*stack_b)->next) && (*stack_b)->next->index + 1 == (*main)->next)))
	{
		while ((*stack_b) && ((*stack_b)->index + 1 == (*main)->next))// || (((*stack_b)->next) && (*stack_b)->next->index + 1 == (*main)->next)))
		{
			// if ((*stack_b)->next && (*stack_b)->next->index + 1 == (*main)->next)
			// 	add_cmd(cmds, do_cmd("sb", stack_a, stack_b, 1));
			add_cmd(cmds, do_cmd("pa", stack_a, stack_b, 1));
			check_next(stack_a, stack_b, main, cmds);
			len_b++;
		}
	}
}
