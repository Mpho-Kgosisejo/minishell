/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_app.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 14:45:56 by mkgosise          #+#    #+#             */
/*   Updated: 2017/08/30 15:17:58 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minsh.h"

void	ft_open_app(char *path, char **cmd)
{
	pid_t		pid;
	char		**environ;

	environ = get_env(NULL);
	if ((pid = fork()) == 0)
	{
		if (execve(path, cmd, environ) == -1)
		{
			ft_puterr(1, ft_strrchr(path, '/'),
					"Error trying to open program: ", 1);
			exit(1);
		}
	}
	else
		waitpid(pid, 0, 0);
}
