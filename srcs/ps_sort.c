/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:29:13 by lseema            #+#    #+#             */
/*   Updated: 2020/10/24 01:45:11 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		start_ps(t_elem **stack_a, t_elem **stack_b, t_main **main, t_cmd **cmds)
{
	if ((*main)->count == 2)
		add_cmd(cmds, do_cmd("sa", stack_a, stack_b));
	else if ((*main)->count == 3)
		sort_three_num(stack_a, stack_b, cmds);
	return (1);
}

void	sort_three_num(t_elem **stack_a, t_elem **stack_b, t_cmd **cmds)
{

}
