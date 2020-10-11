/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 21:54:25 by lseema            #+#    #+#             */
/*   Updated: 2020/10/10 22:50:28 by lseema           ###   ########.fr       */
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
