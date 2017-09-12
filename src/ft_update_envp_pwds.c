/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_envp_pwds.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 14:08:59 by mkgosise          #+#    #+#             */
/*   Updated: 2017/07/29 14:14:59 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minsh.h"

void		update_envp_pwds(char *env)
{
	char cwd[4096];

	if (ft_strcmp("PWD", env) == 0)
	{
		getcwd(cwd, sizeof(cwd));
		ft_setenv("PWD", cwd);
	}
	else if (ft_strcmp("OLDPWD", env) == 0)
	{
		if (ft_getenv("PWD") != NULL)
			ft_setenv("OLDPWD", ft_getenv("PWD"));
	}
}
