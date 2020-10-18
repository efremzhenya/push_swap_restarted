/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 20:17:43 by lseema            #+#    #+#             */
/*   Updated: 2020/10/17 20:36:16 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void set_indexes(t_elem **stack_a, int count)
{
	int		arr[count];
	size_t	i;
	size_t	j;
	int		value;
	t_elem	*tmp;

	i = 0;
	tmp = *stack_a;
	arr[i++] = tmp->value;
	while ((tmp = tmp->next))
		arr[i++] = tmp->value;
	for (j = count; j > 1; j--)
	{
		for (i = 0; i < j - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				value = arr[i];
				arr[i] = arr[i + 1];
				arr[i+1] = value;
			}
		}
	};
	tmp = *stack_a;
	while (tmp)
	{
		i = 0;
		while (tmp->value != arr[i++]);
		tmp->index = --i;
		tmp = tmp->next;
	}
}
