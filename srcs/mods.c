/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mods.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 03:00:13 by lseema            #+#    #+#             */
/*   Updated: 2020/11/15 06:22:51 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_mode_on(char *argv)
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
	return (text + (vizualize * 2));
}
