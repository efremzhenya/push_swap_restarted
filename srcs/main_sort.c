/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 04:12:23 by lseema            #+#    #+#             */
/*   Updated: 2020/11/01 05:57:55 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	main_sort(t_elem **stack_a, t_elem **stack_b, t_main **main, t_cmd **cmds)
{
	size_t	mid;
	int		i;
	int		len_b;
	int		count;
	t_elem	*tail;

	// i = 0;
	// tail = *stack_a;
	// while (tail && tail->next && tail->index != 0)
	// 	tail = tail->next;
	// while (tail->index == i++ && tail->next != NULL)
	// {
	// 	tail = tail->prev;
	// 	//tail->sorted = 1;
	// 	//(*main)->next++;
	// 	//tail = tail->prev;
	// }
	// if (tail->next == NULL)
	// {
	// 	while (tail->prev && tail->prev->index != 0)
	// 	{
	// 		/* code */
	// 	}

	// 	(*main)->next++;
	// 	tail = tail->sorted = 1;
	// }


	while (!is_sorted(stack_a))
	{
		i = 0;
		(*main)->max = (*main)->count;
		while ((*stack_a)->index + 1 == (*main)->next || (*stack_a)->next->index + 1 == (*main)->next)
		{
			if ((*stack_a)->next->index + 1 == (*main)->next)
				add_cmd(cmds, do_cmd("sa", stack_a, stack_b, 1));
			(*stack_a)->sorted = 1;
			add_cmd(cmds, do_cmd("ra", stack_a, stack_b, 1));
			(*main)->next++;
		}
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
		while ((*main)->flag > 1 && i--)
		{
			tail = *stack_b;
			while (tail && tail->next)
				tail = tail->next;
			if (tail->index + 1 <= mid - (get_length(stack_b) / 2))
				add_cmd(cmds, do_cmd("rrr", stack_a, stack_b, 1));
			else
				add_cmd(cmds, do_cmd("rra", stack_a, stack_b, 1));
		}

		(*main)->max = mid;
		while (get_length(stack_b) > 0)
		{
			len_b = get_length(stack_b);
			mid = (*main)->max - (len_b / 2); // (*main)->max / 2 + (*main)->next;
			i = 0;
			while (len_b > i && get_length(stack_b) > (len_b / 2))
			{
				if ((*stack_b)->index + 1 <= mid)
				{
					(*stack_b)->flag = (*main)->flag;
					add_cmd(cmds, do_cmd("pa", stack_a, stack_b, 1));
					while ((*stack_a)->index + 1 == (*main)->next || (*stack_a)->next->index + 1 == (*main)->next)
					{
						if ((*stack_a)->next->index + 1 == (*main)->next)
							add_cmd(cmds, do_cmd("sa", stack_a, stack_b, 1));
						(*stack_a)->sorted = 1;
						add_cmd(cmds, do_cmd("ra", stack_a, stack_b, 1));
						(*main)->next++;
					}
				}
				else
					add_cmd(cmds, do_cmd("rb", stack_a, stack_b, 1));
				i++;
			}
		}
	}
	//-----
	// while ((*stack_a)->flag != 0 && (*stack_a)->sorted == 0)
	// {
	// 	if ((*stack_a)->index + 1 == (*main)->next)
	// 	{
	// 		(*stack_a)->sorted = 1;
	// 		add_cmd(cmds, do_cmd("ra", stack_a, stack_b, 1));
	// 		(*main)->next++;
	// 	}
	// 	else
	// 		add_cmd(cmds, do_cmd("pb", stack_a, stack_b, 1));
	//}

}
