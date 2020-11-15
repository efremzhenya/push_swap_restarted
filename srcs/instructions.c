/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 20:53:09 by lseema            #+#    #+#             */
/*   Updated: 2020/11/15 06:36:29 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_cmd	*do_cmd(char *cmd, t_elem **stack_a, t_elem **stack_b, int allocate_cmd)
{
	void (*function) (t_elem **stack);

	function = NULL;
	if (*cmd == 's')
		function = swap;
	else if (*cmd == 'r')
		function = (cmd[2] == '\0') ? rotate : rev_rotate;
	if (function == NULL)
		cmd[1] == 'a' ? push(stack_a, stack_b) : push(stack_b, stack_a);
	else if (cmd[1] == 's' || cmd[2] == 'r'
		|| (cmd[1] == 'r' && cmd[2] == '\0'))
	{
		function(stack_a);
		function(stack_b);
	}
	else
		function((cmd[1] == 'a' || cmd[2] == 'a') ? stack_a : stack_b);
	return (allocate_cmd ? new_cmd(cmd) : NULL);
}

void	swap(t_elem **stack)
{
	t_elem		*temp_1;
	t_elem		*temp_2;

	if (get_length(stack) < 2)
		return ;
	temp_1 = *stack;
	temp_2 = (*stack)->next;
	temp_1->next = temp_2->next;
	if (temp_2->next)
		temp_2->next->prev = temp_1;
	*stack = temp_2;
	(*stack)->next = temp_1;
	temp_1->prev = temp_2;
	(*stack)->prev = NULL;
}

void	rotate(t_elem **stack)
{
	t_elem *first;
	t_elem *tail;

	if (stack && *stack && (*stack)->next)
	{
		first = *stack;
		*stack = (*stack)->next;
		tail = *stack;
		tail->prev = NULL;
		while (tail->next)
			tail = tail->next;
		first->prev = tail;
		first->next = NULL;
		tail->next = first;
	}
}

void	rev_rotate(t_elem **stack)
{
	t_elem *last;
	t_elem *tail;

	if (stack && *stack && (*stack)->next)
	{
		tail = *stack;
		while (tail->next)
			tail = tail->next;
		last = tail;
		tail = tail->prev;
		tail->next = NULL;
		last->prev = NULL;
		last->next = *stack;
		(*stack)->prev = last;
		*stack = last;
	}
}

void	push(t_elem **stack2, t_elem **stack1)
{
	t_elem	*tail1;

	if (!*stack1)
		return ;
	tail1 = (*stack1);
	*stack1 = (*stack1)->next;
	if (*stack1)
		(*stack1)->prev = NULL;
	if (!*stack2)
	{
		tail1->next = NULL;
		*stack2 = tail1;
	}
	else
	{
		(*stack2)->prev = tail1;
		tail1->next = *stack2;
		*stack2 = tail1;
	}
}
