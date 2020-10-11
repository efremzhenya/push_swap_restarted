/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 22:09:53 by lseema            #+#    #+#             */
/*   Updated: 2020/10/10 23:59:18 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		is_num(char *word)
{
	int i;

	i = 0;
	while (word[i] != '\0')
		if (word[i] == '-' && i == 0 && ft_strlen(word) > 1)
			i++;
		else if (!ft_isdigit(word[i++]))
			return (0);
	return (1);
}

int		is_contain(t_elem **stack, int num)
{
	t_elem *tail;

	tail = *stack;
	while (tail != NULL)
	{
		if (tail->value == num)
			return (1);
		tail = tail->next;
	}
	return(0);
}
