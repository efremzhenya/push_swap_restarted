/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 21:54:25 by lseema            #+#    #+#             */
/*   Updated: 2020/11/05 00:50:33 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_elem		*new_elem(int value)
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
void		add_elem(t_elem **stack, t_elem *elem)
{
	t_elem	*tail;
	t_elem	*tmp2;

	if (!stack || !elem)
		return ;
	tail = *stack;
	while (tail->next)
	{
		tail = tail->next;
	}
	tail->next = elem;
	elem->next = NULL;
	elem->prev = tail;
}

size_t		get_length(t_elem **stack)
{
	t_elem *tail;
	size_t count;

	if (!stack || !*stack)
		return (0);
	tail = *stack;
	count = 1;
	while (tail->next)
	{
		tail = tail->next;
		count++;
	}
	return count;
}

size_t		get_length_flag(t_elem **stack, int flag)
{
	t_elem *tail;
	size_t count;

	if (!stack || !*stack)
		return (0);
	tail = *stack;
	count = 0;
	while (tail)
	{
		if (tail->flag == flag)
			count++;
		tail = tail->next;
	}
	return count;
}

int		get_min_index(t_elem **stack_a)
{
	t_elem	*tmp;
	int		min;

	if (!stack_a || !*stack_a)
		return -1;
	tmp = (*stack_a)->next;
	min = (*stack_a)->index;
	while (tmp)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	return min;
}

int		get_max_ind(t_elem **stack_a)
{
	t_elem	*tmp;
	int		max;

	if (!stack_a || !*stack_a)
		return -1;
	tmp = (*stack_a)->next;
	max = (*stack_a)->index;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return max;
}

int		get_max_index(t_elem **stack_a, int flag)
{
	t_elem	*tmp;
	int		max;

	if (!stack_a || !*stack_a)
		return -1;
	tmp = (*stack_a)->next;
	while (tmp && tmp->flag != flag)
		tmp = tmp->next;
	if (!tmp)
		return -1;
	max = tmp->index;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return max;
}

int		get_flag(t_elem **stack_a, int	index)
{
	t_elem	*tmp;
	index--;

	if (!stack_a || !*stack_a)
		return -1;
	tmp = (*stack_a)->next;
	while (tmp && tmp->index != index)
		tmp = tmp->next;
	if (!tmp)
		return -1;
	return tmp->flag;
}
