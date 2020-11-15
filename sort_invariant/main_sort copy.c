/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 04:12:23 by lseema            #+#    #+#             */
/*   Updated: 2020/11/04 23:47:26 by lseema           ###   ########.fr       */
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

	while (!is_sorted(stack_a))
	{
		if ((*stack_a)->flag > 0 && (*stack_a)->sorted == 0)
		{
			if (((*main)->max = get_max_index(stack_a, (*main)->flag) + 1) > 0)
			{
				while ((*stack_a)->sorted == 0 && (*stack_a)->flag == (*main)->flag)
				{
					if ((*stack_a)->index + 1 == (*main)->next || (*stack_a)->next->index + 1 == (*main)->next)
						check_next(stack_a, stack_b, main, cmds);
					else
						add_cmd(cmds, do_cmd("pb", stack_a, stack_b, 1));
				}
			}
		}
		else
		{
			i = 0;
			check_next(stack_a, stack_b, main, cmds);
			(*main)->max = (*main)->count;
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
			while (i--)
			{
				add_cmd(cmds, do_cmd("rra", stack_a, stack_b, 1));
			}
			(*main)->max = mid;
		}

		if ((*main)->flag == 0)
		{
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
						check_next(stack_a, stack_b, main, cmds);
					}
					else
						add_cmd(cmds, do_cmd("rb", stack_a, stack_b, 1));
					i++;
				}
			}
		}
		else if ((*stack_b)->flag == (*main)->flag)
		{
			while (get_length_flag(stack_b, (*main)->flag) > 0)
			{
				i = 0;
				len_b = get_length_flag(stack_b, (*main)->flag);
				mid = get_max_index(stack_b, (*main)->flag);
				while (len_b > i && get_length_flag(stack_b, (*main)->flag) > (len_b / 2))
				{
					if ((*stack_b)->index + 1 <= mid)
					{
						(*stack_b)->flag = (*main)->flag + 1;
						add_cmd(cmds, do_cmd("pa", stack_a, stack_b, 1));
						check_next(stack_a, stack_b, main, cmds);
					}
					else
						add_cmd(cmds, do_cmd("rb", stack_a, stack_b, 1));
					i++;
				}
				(*main)->flag++;
			}
		}
		else if ((get_length_flag(stack_b, (*main)->flag)) > 0)
		{
			while ((get_length_flag(stack_b, (*main)->flag)) > 0)
			{
				add_cmd(cmds, do_cmd("rra", stack_a, stack_b, 1));
			}
			while (get_length_flag(stack_b, (*main)->flag) > 0)
			{
				i = 0;
				len_b = get_length_flag(stack_b, (*main)->flag);
				mid = get_max_index(stack_b, (*main)->flag);
				while (len_b > i && get_length_flag(stack_b, (*main)->flag) > (len_b / 2))
				{
					if ((*stack_b)->index + 1 <= mid)
					{
						(*stack_b)->flag = (*main)->flag;
						add_cmd(cmds, do_cmd("pa", stack_a, stack_b, 1));
						check_next(stack_a, stack_b, main, cmds);
					}
					else
						add_cmd(cmds, do_cmd("rb", stack_a, stack_b, 1));
					i++;
				}
			}
		}
		else if ((*main)->flag > 0)
		{
			(*main)->flag--;
		}

		while ((*stack_b)->flag > 0)
		{
			while (get_length_flag(stack_b, (*main)->flag) > 0)
			{
				i = 0;
				len_b = get_length_flag(stack_b, (*main)->flag);
				mid = get_max_index(stack_b, (*main)->flag);
				while (len_b > i && get_length_flag(stack_b, (*main)->flag) > (len_b / 2))
				{
					if ((*stack_b)->index + 1 <= mid)
					{
						(*stack_b)->flag = (*main)->flag;
						add_cmd(cmds, do_cmd("pa", stack_a, stack_b, 1));
						check_next(stack_a, stack_b, main, cmds);
					}
					else
						add_cmd(cmds, do_cmd("rb", stack_a, stack_b, 1));
					i++;
				}
			}
		}


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
					check_next(stack_a, stack_b, main, cmds);
				}
				else
					add_cmd(cmds, do_cmd("rb", stack_a, stack_b, 1));
				i++;
			}

			//new
			while ((*stack_a)->flag > 0 && (*stack_a)->sorted == 0)
			{
				while ((*stack_a)->sorted == 0 && (*stack_a)->flag == (*main)->flag)
				{
					if ((*stack_a)->index + 1 == (*main)->next || (*stack_a)->next->index + 1 == (*main)->next)
						check_next(stack_a, stack_b, main, cmds);
					else
						add_cmd(cmds, do_cmd("pb", stack_a, stack_b, 1));
				}
				while ((*stack_b)->flag == (*main)->flag)
				{
					add_cmd(cmds, do_cmd("pa", stack_a, stack_b, 1));
					check_next(stack_a, stack_b, main, cmds);
				}
				(*main)->flag--;
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

void	check_next(t_elem **stack_a, t_elem **stack_b, t_main **main, t_cmd **cmds)
{
	while ((*stack_a)->index + 1 == (*main)->next || (*stack_a)->next->index + 1 == (*main)->next)
	{
		if ((*stack_a)->next->index + 1 == (*main)->next)
			add_cmd(cmds, do_cmd("sa", stack_a, stack_b, 1));
		(*stack_a)->sorted = 1;
		add_cmd(cmds, do_cmd("ra", stack_a, stack_b, 1));
		(*main)->next++;
	}
}
