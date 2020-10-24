/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 21:18:11 by lseema            #+#    #+#             */
/*   Updated: 2020/10/24 22:26:56 by lseema           ###   ########.fr       */
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

void	refactor_cmds(t_cmd **cmds)
{
	t_cmd	*tail;
	int		len1;
	int		len2;

	if (!cmds || !*cmds || !(*cmds)->next)
		return;
	tail = *cmds;
	while (tail && tail->next)
	{
		len1 = ft_strlen(tail->cmd) - 1;
		len2 = ft_strlen(tail->next->cmd) - 1;
		if (tail->cmd[0] != 'p' && tail->next->cmd[0] == tail->cmd[0] &&
			len1 == len2 && tail->cmd[len1] != tail->next->cmd[len2] &&
			tail->cmd[len1] != tail->cmd[0] &&
			tail->next->cmd[len2] != tail->next->cmd[0])
			{
				if (tail->cmd[0] == 's')
					tail->cmd = "ss";
				else
					tail->cmd = (len1 == 2) ? "rrr" : "rr";
				tail->next->cmd = NULL;
				tail = tail->next;
			}
		tail = tail->next;
	}
}

void	print_cmds(t_cmd **cmds)
{
	t_cmd *out;

	if (!cmds)
		return;
	out = *cmds;
	while (out)
	{
		if (out->cmd)
		{
			ft_putstr(out->cmd);
			ft_putchar('\n');
		}
		out = out->next;
	};
}

void	free_cmds(t_cmd **cmds)
{
	t_cmd *tail;

	if (*cmds)
	{
		tail = *cmds;
		while (tail->next)
		{
			*cmds = tail;
			tail = tail->next;
			free(*cmds);
		}
		free(tail);
	}
}
