/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 22:09:53 by lseema            #+#    #+#             */
/*   Updated: 2020/10/31 02:59:37 by lseema           ###   ########.fr       */
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
	return (0);
}

int		is_sorted(t_elem **stack)
{
	t_elem	*tail;

	if (!stack || !*stack)
		return (0);
	else if (!((*stack)->next))
		return (1);
	tail = *stack;
	while (tail->next)
	{
		if (tail->value > (tail->next)->value)
			return (0);
		tail = tail->next;
	}
	return (1);
}

int validate_args(int argc, char **argv, t_elem **stack_a)
{
	int num;
	int mode;

	if (argc <= 1)
		return (0);
	if ((mode = is_mode_on(*argv)) > 0)
		argv++;
	for (size_t i = 1; i < argc; i++)
	{
		argv++;
		if (!validate_num(*argv))
			return (0);
		num = ft_atoi(*argv);
		if (i == 1)
			*stack_a = new_elem(num);
		else
		{
			if (is_contain(stack_a, num))
				return (0);
			add_elem(stack_a, new_elem(num));
		}
	}
	return (mode ? mode + 1 : 1);
}

int validate_num(char *argv)
{
	long long res;

	res = ft_atoi(argv);
	if (ft_strlen(argv) > 12 || !is_num(argv)
		|| res < -2147483648 || res > 2147483647)
		return (0);
	else
		return (1);
}
