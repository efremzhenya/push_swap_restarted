/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 21:18:11 by lseema            #+#    #+#             */
/*   Updated: 2020/10/24 00:29:38 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_cmd	*new_cmd(char *c)
{
	t_cmd	*cmd;

	cmd = (t_cmd*)malloc(sizeof(t_cmd));
	cmd->cmd = c;
	cmd->next = NULL;
	cmd->prev = NULL;
	return cmd;
}

void		add_cmd(t_cmd **cmds, t_cmd *cmd)
{
	t_cmd	*tail;

	if (!cmds || !cmd)
		return;
	if (!*cmds)
		*cmds = cmd;
	else
	{
		tail = *cmds;
		while (tail->next)
			tail = tail->next;
		tail->next = cmd;
		cmd->next = NULL;
		cmd->prev = tail;
	}
}
