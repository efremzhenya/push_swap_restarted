/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mods.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 03:00:13 by lseema            #+#    #+#             */
/*   Updated: 2020/11/15 15:27:14 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_mode_on(char *argv)
{
	int vizualize;

	vizualize = 0;
	if (argv && *argv == '-')
	{
		argv++;
		if (*argv && (*argv == 'V' || *argv == 'v'))
			vizualize = 1;
	}
	return (vizualize);
}
