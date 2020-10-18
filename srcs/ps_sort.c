/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:29:13 by lseema            #+#    #+#             */
/*   Updated: 2020/10/18 20:08:42 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	start_ps(t_elem **stack_a, t_elem **stack_b, t_main **main, t_cmd **cmds)
{

	if (!(init(stack_a, stack_b, main, cmds)))
		return (0);
	if ((*main)->count <= 3)
	{

	}
	else if ((*main)->count <= 5)
	{

	}
	else
	{

	}
	return (1);
}
