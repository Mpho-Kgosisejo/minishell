/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 13:50:12 by mkgosise          #+#    #+#             */
/*   Updated: 2017/08/19 15:51:26 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minsh.h"

static int	do_unset(char *name)
{
	if (ft_unsetenv(name) == 0)
		return (1);
	else
		return (0);
}

void		ft_unsetenv_handler(char **cmd)
{
	int i;

	if (countlist(cmd))
	{
		i = 0;
		while (cmd[i])
		{
			if (do_unset(cmd[i]) == -1)
				ft_puterr(0, NULL, "Error unsetting env", 1);
			i++;
		}
	}
}
