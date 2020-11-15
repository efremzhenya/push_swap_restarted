/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 00:07:15 by lseema            #+#    #+#             */
/*   Updated: 2020/11/15 06:24:01 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_elem **stack)
{
	t_elem *tail;

	if (*stack)
	{
		tail = *stack;
		while (tail->next)
		{
			*stack = tail;
			tail = tail->next;
			free(*stack);
		}
		free(tail);
	}
}

void	free_all(t_elem **a, t_elem **b, t_cmd **cmds, t_main **main)
{
	if (*a)
		free_stack(a);
	if (*b)
		free_stack(b);
	if (*cmds)
		free_cmds(cmds);
	if (*main)
		free(*main);
}
