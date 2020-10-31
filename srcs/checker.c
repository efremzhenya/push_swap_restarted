/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 23:30:51 by lseema            #+#    #+#             */
/*   Updated: 2020/10/31 02:56:52 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		main(int argc, char **argv)
{
	t_elem	*stack_a;
	t_elem	*stack_b;
	t_cmd	*cmds;
	int		mode;

	stack_a = NULL;
	stack_b = NULL;
	cmds = NULL;
	if (argc < 2)
		return (0);
	if (!(mode = validate_args(argc, argv, &stack_a)))
	{
		free_stack(&stack_a);
		return (write(1, "Error\n", 6));
	}
	read_cmds(&stack_a, &stack_b);
	write(1, is_sorted(&stack_a) && (get_length(&stack_b) == 0) ? "OK\n" : "KO\n", 3);
	free_stack(&stack_a);
	free_stack(&stack_b);
	free_cmds(&cmds);
	return (0);
}

void	read_cmds(t_elem **stack_a, t_elem **stack_b)
{
	int		fd;
	char	*raw_cmd;

	while (get_next_line(0, &raw_cmd) > 0)
	{
		if (!ft_strcmp(raw_cmd, "pa") || !ft_strcmp(raw_cmd , "pb") ||
			!ft_strcmp(raw_cmd, "sa") || !ft_strcmp(raw_cmd, "sb") ||
			!ft_strcmp(raw_cmd, "ss") || !ft_strcmp(raw_cmd, "ra") ||
			!ft_strcmp(raw_cmd, "rb") || !ft_strcmp(raw_cmd, "rr") ||
			!ft_strcmp(raw_cmd, "rra") || !ft_strcmp(raw_cmd, "rrb") ||
			!ft_strcmp(raw_cmd, "rrr"))
			do_cmd(raw_cmd, stack_a, stack_b, 0);
		else
			write(1, "Error\n", 6);
		free(raw_cmd);
	}
}
