/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:13:44 by mkgosise          #+#    #+#             */
/*   Updated: 2017/08/19 15:49:02 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minsh.h"
#include <stdio.h>

static int	do_chdir(char *path)
{
	if (path != NULL)
	{
		if (chdir(path) == -1)
		{
			ft_puterr(1, path, "cd: not a directory: ", 1);
			return (-1);
		}
		return (1);
	}
	return (-1);
}

static void	do_userhome(char *path)
{
	char *newpath;

	newpath = ft_strjoin(ft_getenv("HOME"), &path[1]);
	do_chdir(newpath);
	free(newpath);
}

static void	do_oldpwd(char *path)
{
	char *newpath;

	newpath = ft_strjoin(ft_getenv("OLDPWD"), &path[1]);
	if (do_chdir(newpath) == 1)
		ft_putendl(newpath);
	free(newpath);
}

void		ft_chdir(char **cmd)
{
	struct stat	st;

	if (countlist(cmd) == 0)
		do_chdir(ft_getenv("HOME"));
	else if (ft_strncmp(cmd[0], "~", 1) == 0)
		do_userhome(cmd[0]);
	else if (ft_strncmp(cmd[0], "-", 1) == 0)
		do_oldpwd(cmd[0]);
	else if (countlist(cmd) == 1)
	{
		lstat(cmd[0], &st);
		if (S_ISDIR(st.st_mode) || S_ISREG(st.st_mode))
			do_chdir(cmd[0]);
		else
			ft_puterr(1, cmd[0], "cd: can not open: ", 1);
	}
	else if (countlist(cmd) > 1)
		ft_puterr(0, "cd", ": too many arguments", 1);
	else
		ft_puterr(0, "cd", ": something went wrong, cd stopped", 1);
	update_envp_pwds("OLDPWD");
	update_envp_pwds("PWD");
}
