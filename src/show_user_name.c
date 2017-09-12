/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_user_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 17:06:15 by mkgosise          #+#    #+#             */
/*   Updated: 2017/08/30 15:02:10 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minsh.h"

char	*show_user_name(void)
{
	char *user;

	if ((user = ft_getenv("USER")) != NULL)
	{
		ft_putstr("(");
		ft_putcolor("[0;32m");
		ft_putstr(user);
		ft_putcolor("[0;39m");
		ft_putstr(")");
	}
	ft_putstr("$> ");
	return (getin());
}
