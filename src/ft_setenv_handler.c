/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 13:48:37 by mkgosise          #+#    #+#             */
/*   Updated: 2017/08/31 13:16:25 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minsh.h"

static int	do_set(char *vname, char *value)
{
	if (ft_setenv(vname, value) == 0)
		return (1);
	else
		return (-1);
}

void		ft_setenv_handler(char **cmd)
{
	struct s_setenv_handler st;

	st.i = 0;
	if (countlist(cmd))
		while (cmd[st.i])
		{
			if (countlist((st.var = ft_strsplit(cmd[st.i++], '='))) == 2)
			{
				if ((st.value = filter(st.var[1])))
				{
					if (do_set(st.var[0], st.value) == -1)
						ft_puterr(0, NULL, "Error setting env", 1);
					free(st.value);
				}
				else
					ft_puterr(0, "setenv", ": bad assignment", 1);
				ft_free2d((void**)st.var);
			}
			else
			{
				ft_puterr(0, "setenv", ": bad assignment", 1);
				ft_free2d((void**)st.var);
				break ;
			}
		}
}
