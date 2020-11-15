/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 23:30:51 by lseema            #+#    #+#             */
/*   Updated: 2020/11/15 17:32:19 by lseema           ###   ########.fr       */
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
	if (!(mode = validate_args(argc, argv, &stack_a, 1)))
	{
		free_stack(&stack_a);
		return (write(1, "Error\n", 6));
	}
	read_cmds(&stack_a, &stack_b, mode);
	if (is_sorted(&stack_a) && (get_length(&stack_b) == 0))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(&stack_a, &stack_b, &cmds, NULL);
	return (0);
}

void	read_cmds(t_elem **stack_a, t_elem **stack_b, int mode)
{
	char	*raw_cmd;

	while (get_next_line(0, &raw_cmd) > 0)
	{
		if (!ft_strcmp(raw_cmd, "pa") || !ft_strcmp(raw_cmd, "pb") ||
		!ft_strcmp(raw_cmd, "sa") || !ft_strcmp(raw_cmd, "sb") ||
		!ft_strcmp(raw_cmd, "ss") || !ft_strcmp(raw_cmd, "ra") ||
		!ft_strcmp(raw_cmd, "rb") || !ft_strcmp(raw_cmd, "rr") ||
		!ft_strcmp(raw_cmd, "rra") || !ft_strcmp(raw_cmd, "rrb") ||
		!ft_strcmp(raw_cmd, "rrr"))
		{
			do_cmd(raw_cmd, stack_a, stack_b, 0);
			if (mode == 2)
				draw(stack_a, stack_b);
		}
		else
			write(1, "Error\n", 6);
		free(raw_cmd);
	}
}

void	draw(t_elem **stack_a, t_elem **stack_b)
{
	size_t	len;
	t_elem	*tmpa;
	t_elem	*tmpb;

	len = get_length(stack_a) > get_length(stack_b)
		? get_length(stack_a) : get_length(stack_b);
	tmpa = *stack_a;
	tmpb = *stack_b;
	ft_putstr_fd("+---Stack A---+---Stack B---+\n", 1);
	while (len--)
	{
		draw_stack(tmpa);
		if (tmpa)
			tmpa = tmpa->next;
		draw_stack(tmpb);
		if (tmpb)
			tmpb = tmpb->next;
		write(1, "|\n", 2);
	}
	ft_putstr_fd("|___________________________|\n", 1);
}

void	draw_stack(t_elem *elem)
{
	int		i;
	char	*str;

	i = 13;
	write(1, "|", 1);
	if (elem)
	{
		str = ft_itoa(elem->value);
		i -= ft_strlen(str);
		while (i--)
			write(1, " ", 1);
		ft_putstr_fd(str, 1);
		free(str);
	}
	else
	{
		while (i--)
			write(1, " ", 1);
	}
}
