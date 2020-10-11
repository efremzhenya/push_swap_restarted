/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 19:13:58 by lseema            #+#    #+#             */
/*   Updated: 2020/10/11 00:14:07 by lseema           ###   ########.fr       */
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
	return (0);
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
