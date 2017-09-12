/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 13:00:14 by mkgosise          #+#    #+#             */
/*   Updated: 2017/07/29 12:29:57 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minsh.h"

char	*ft_puterr(int ch, char *name, char *mssg, int new_line)
{
	int		i;

	i = 0;
	while (i != 2)
	{
		if (ch == 0)
		{
			ft_putcolor("[0;31m");
			ft_putstr(name);
			ch = 1;
		}
		else
		{
			ft_putcolor("[0;39m");
			ft_putstr(mssg);
			ch = 0;
		}
		ft_putcolor("[0;39m");
		i++;
	}
	if (new_line)
		ft_putchar('\n');
	return (NULL);
}
