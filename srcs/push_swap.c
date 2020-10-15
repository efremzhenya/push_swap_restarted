/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 19:13:58 by lseema            #+#    #+#             */
/*   Updated: 2020/10/15 22:43:25 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
	t_elem	*stack_a;
	t_elem	*stack_b;
	t_main	*main;

	if (!validate_args(argc, argv, &stack_a))
	{
		free_stack(&stack_a);
		return (write(1, "Error\n", 6));
	};
	set_indexes(&stack_a, argc - 1);
	free_stack(&stack_a);
	return (0);
}

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

int validate_args(int argc, char **argv, t_elem **stack_a)
{
	int num;

	if (argc < 1)
		return (0);
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
	return (1);
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
