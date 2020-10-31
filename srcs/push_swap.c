/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 19:13:58 by lseema            #+#    #+#             */
/*   Updated: 2020/10/31 00:24:52 by lseema           ###   ########.fr       */
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
