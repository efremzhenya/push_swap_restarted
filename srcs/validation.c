/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 22:09:53 by lseema            #+#    #+#             */
/*   Updated: 2020/11/15 06:37:00 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

int		validate_args(int count, char **argv, t_elem **stack_a)
{
	int		num;
	int		mode;

	if (count > 0)
		argv++;
	if (count == 2)
		return (validate_string(*argv, stack_a));
	if ((mode = is_mode_on(*argv)) > 0)
		argv++;
	if (!*argv)
		return (0);
	while (*argv)
	{
		if (!validate_num(*argv))
			return (0);
		num = ft_atoi(*argv);
		if (!*stack_a)
			*stack_a = new_elem(num);
		else if (is_contain(stack_a, num) || !add_elem(stack_a, new_elem(num)))
			return (0);
		argv++;
	}
	return (mode ? mode + 1 : 1);
}

int		validate_string(char *str, t_elem **stack_a)
{
	char	**temp;
	int		i;
	int		result;

	temp = ft_strsplit(str, ' ');
	result = validate_args(-1, temp, stack_a);
	i = 0;
	while (temp[i])
		free(temp[i++]);
	free(temp);
	return (result);
}

int		validate_num(char *argv)
{
	long long	res;
	int			i;

	res = ft_atoi(argv);
	if (ft_strlen(argv) > 12 || res < -2147483648 || res > 2147483647)
		return (0);
	i = 0;
	while (argv[i] != '\0')
		if (argv[i] == '-' && i == 0 && ft_strlen(argv) > 1)
			i++;
		else if (!ft_isdigit(argv[i++]))
			return (0);
	return (1);
}
