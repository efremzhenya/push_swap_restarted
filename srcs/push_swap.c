/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 19:13:58 by lseema            #+#    #+#             */
/*   Updated: 2020/10/24 01:37:58 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
	t_elem	*stack_a;
	t_elem	*stack_b;
	t_main	*main;
	t_cmd	*cmds;

	main = (t_main *)malloc(sizeof(t_main));
	stack_a = NULL;
	stack_b = NULL;
	cmds = NULL;
	if (!(main->mode = validate_args(argc, argv, &stack_a)))
	{
		free_stack(&stack_a);
		free(main);
		return (write(1, "Error\n", 6));
	}
	else if (is_sorted(&stack_a))
	{
		free_stack(&stack_a);
		free(main);
		return (0);
	};
	main->count = (main->mode > 1 ? argc - 2 : argc - 1);
	set_indexes(&stack_a, main->count);
	start_ps(&stack_a, &stack_b, &main, &cmds);
	free_stack(&stack_a);
	free_stack(&stack_b);
	free_cmds(&cmds);
	free(main);
	return (0);
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
int is_mode_on(char *argv)
{
	int text;
	int vizualize;

	text = 0;
	vizualize = 0;
	if (argv && *argv == '-')
	{
		argv++;
		while (*argv != '\0')
		{
			if (*argv == 'T' || *argv == 't')
				text = 1;
			if (*argv == 'V' || *argv == 'v')
				vizualize = 1;
			argv++;
		}
	}
	return text + (vizualize * 2);
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
