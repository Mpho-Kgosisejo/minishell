/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 14:04:48 by mkgosise          #+#    #+#             */
/*   Updated: 2017/09/04 09:04:17 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minsh.h"

static char	*bin_app(char *app)
{
	struct s_binapp	st;

	st.i = 0;
	if (ft_strchr(app, '/'))
		if (access(app, F_OK) != -1 && access(app, X_OK) != -1)
			return (ft_strdup(app));
	if (ft_getenv("PATH") != NULL)
	{
		st.paths = ft_strsplit(ft_getenv("PATH"), ':');
		while (st.paths[st.i])
		{
			st.path = ft_strjoin(st.paths[st.i++], "/");
			st.tmp = ft_strjoin(st.path, app);
			free(st.path);
			st.path = st.tmp;
			if (access(st.path, F_OK) != -1 && access(st.path, X_OK) != -1)
			{
				ft_free2d((void**)st.paths);
				return (st.path);
			}
			free(st.path);
		}
		ft_free2d((void**)st.paths);
	}
	return (NULL);
}

static int	cust_app(char **cmd)
{
	if ((ft_strcmp(*cmd, "env") == 0) ||
			(ft_strcmp(*cmd, "setenv") == 0) ||
			(ft_strcmp(*cmd, "unsetenv") == 0))
		ft_env_handler(cmd);
	else if (ft_strcmp(*cmd, "cd") == 0)
		ft_chdir(&cmd[1]);
	else if (ft_strcmp(*cmd, "echo") == 0)
		ft_echo(cmd);
	else
		return (-1);
	return (1);
}

static void	do_cmd(char **in)
{
	struct s_do_cmd	dc;

	if (countlist(dc.cmd = ft_listdup(in)))
	{
		if ((ft_strcmp(*dc.cmd, "cd") == 0) || (ft_strcmp(*dc.cmd, "env") == 0)
				|| (ft_strcmp(*dc.cmd, "echo") == 0) ||
				(ft_strcmp(*dc.cmd, "setenv") == 0)
				|| (ft_strcmp(*dc.cmd, "unsetenv") == 0))
		{
			if (cust_app(dc.cmd) == -1)
				ft_puterr(1, *dc.cmd, "Unable to run: ", 1);
		}
		else if ((dc.path = bin_app(*dc.cmd)) != NULL)
		{
			ft_open_app(dc.path, dc.cmd);
			free(dc.path);
		}
		else
			ft_puterr(0, *dc.cmd, ": command not found", 1);
		ft_free2d((void**)dc.cmd);
	}
}

static char	**cmd_prompt(void)
{
	struct s_cmd_prompt st;
	t_make				mk;

	mk.x = 0;
	st.tmp2 = show_user_name();
	if ((st.tmp = ft_strtrim(st.tmp2)) == NULL)
	{
		free(st.tmp2);
		return (NULL);
	}
	free(st.tmp2);
	if ((st.tmp2 = filter(st.tmp)) == NULL)
	{
		free(st.tmp);
		ft_puterr(0, "shell", ": closing qoute not found", 1);
		return (NULL);
	}
	free(st.tmp);
	if ((st.ret = ft_makeargs(st.tmp2, mk)) == NULL)
	{
		free(st.tmp2);
		return (NULL);
	}
	free(st.tmp2);
	return (st.ret);
}

int			main(void)
{
	struct s_main	st;
	extern char		**environ;

	get_env(ft_listdup(environ));
	update_envp_pwds("OLDPWD");
	while (1)
	{
		st.in = cmd_prompt();
		if (countlist(st.in) > 0 && st.in != NULL)
		{
			if (ft_strcmp(*st.in, "exit") == 0)
			{
				ft_free2d((void**)st.in);
				break ;
			}
			else
				do_cmd(st.in);
		}
		ft_free2d((void**)st.in);
	}
	ft_free2d((void**)get_env(NULL));
	return (0);
}
