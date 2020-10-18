/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 00:07:15 by lseema            #+#    #+#             */
/*   Updated: 2020/10/17 20:18:22 by lseema           ###   ########.fr       */
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
