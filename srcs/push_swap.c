/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 19:13:58 by lseema            #+#    #+#             */
/*   Updated: 2020/11/15 06:24:56 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int		init_main(t_main **main)
{
	if (!(*main = (t_main *)malloc(sizeof(t_main))))
		return (0);
	(*main)->next = 1;
	(*main)->flag = 0;
	(*main)->any_sorted = 0;
	return (1);
}

int		main(int argc, char **argv)
{
	t_elem	*a;
	t_elem	*b;
	t_main	*main;
	t_cmd	*cmds;

	init_main(&main);
	a = NULL;
	b = NULL;
	cmds = NULL;
	if (argc <= 1 || !argv || !(main->mode = validate_args(argc, argv, &a)))
		return (error());
	if (argc == -1 || is_sorted(&a))
	{
		free_all(&a, &b, &cmds, &main);
		return (0);
	}
	set_indexes(&a, main->count = get_length(&a), 0);
	start_ps(&a, &b, &main, &cmds);
	free_all(&a, &b, &cmds, &main);
	return (0);
}
