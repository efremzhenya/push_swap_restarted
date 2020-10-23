/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 00:07:15 by lseema            #+#    #+#             */
/*   Updated: 2020/10/24 00:34:05 by lseema           ###   ########.fr       */
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

void	free_cmds(t_cmd **cmds)
{
	t_cmd *tail;

	if (*cmds)
	{
		tail = *cmds;
		while (tail->next)
		{
			*cmds = tail;
			tail = tail->next;
			free(*cmds);
		}
		free(tail);
	}
}
