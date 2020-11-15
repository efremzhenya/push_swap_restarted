/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 21:54:25 by lseema            #+#    #+#             */
/*   Updated: 2020/11/15 17:45:35 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_elem	*new_elem(int value)
{
	t_elem *elem;

	if (!(elem = (t_elem *)malloc(sizeof(t_elem))))
		return (NULL);
	elem->value = value;
	elem->index = 0;
	elem->flag = 0;
	elem->sorted = 0;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

int		add_elem(t_elem **stack, t_elem *elem)
{
	t_elem	*tail;

	if (!stack || !elem)
		return (0);
	tail = *stack;
	while (tail->next)
	{
		tail = tail->next;
	}
	tail->next = elem;
	elem->next = NULL;
	elem->prev = tail;
	return (1);
}

int		get_length(t_elem **stack)
{
	t_elem	*tail;
	int		count;

	if (!stack || !*stack)
		return (0);
	tail = *stack;
	count = 1;
	while (tail->next)
	{
		tail = tail->next;
		count++;
	}
	return (count);
}

int		get_min_index(t_elem **stack_a)
{
	t_elem	*tmp;
	int		min;

	if (!stack_a || !*stack_a)
		return (-1);
	tmp = (*stack_a)->next;
	min = (*stack_a)->index;
	while (tmp)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	return (min);
}

int		get_max_ind(t_elem **stack_a)
{
	t_elem	*tmp;
	int		max;

	if (!stack_a || !*stack_a)
		return (-1);
	tmp = (*stack_a)->next;
	max = (*stack_a)->index;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}
