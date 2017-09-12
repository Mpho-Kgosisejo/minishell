/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 16:29:48 by mkgosise          #+#    #+#             */
/*   Updated: 2017/08/31 13:16:23 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minsh.h"

int			ft_unsetenv(char *name)
{
	char	**environ;
	int		i;

	environ = get_env(NULL);
	if (ft_getenv(name))
	{
		i = 0;
		while (environ[i])
		{
			if (ft_strncmp(environ[i], name, ft_strlen(name)) == 0 &&
					environ[i][ft_strlen(name)] == '=')
			{
				ft_list_del_el(environ, environ[i]);
				break ;
			}
			i++;
		}
		return (1);
	}
	return (0);
}

static int	update_env(char *name, char *value)
{
	char			**environ;
	struct s_setenv st;

	environ = get_env(NULL);
	st.tmp = ft_strjoin(name, "=");
	st.env = ft_strjoin(st.tmp, ft_getenv(name));
	st.newenv = ft_strjoin(st.tmp, value);
	free(st.tmp);
	if (ft_updatelist(environ, st.env, st.newenv) == -1)
		return (-1);
	free(st.newenv);
	free(st.env);
	return (1);
}

int			ft_setenv(char *name, char *value)
{
	char			**environ;
	struct s_setenv	st;

	environ = get_env(NULL);
	if (ft_getenv(name))
	{
		if (update_env(name, value) == -1)
			return (-1);
	}
	else
	{
		st.tmp = ft_strjoin(name, "=");
		st.env = ft_strjoin(st.tmp, value);
		free(st.tmp);
		if ((st.tmpenv = ft_listcat(environ, st.env)) == NULL)
			return (-1);
		else
		{
			free(st.env);
			ft_free2d((void**)environ);
			get_env(st.tmpenv);
		}
	}
	return (0);
}

char		*ft_getenv(char *name)
{
	int			i;
	int			strlen;
	char		**environ;

	i = 0;
	environ = get_env(NULL);
	strlen = ft_strlen(name);
	while (environ[i])
	{
		if (ft_strncmp(environ[i], name, strlen) == 0 &&
				environ[i][ft_strlen(name)] == '=')
			return (&environ[i][strlen + 1]);
		i++;
	}
	return (NULL);
}

void		ft_env_handler(char **cmd)
{
	int			i;
	char		**environ;

	environ = get_env(NULL);
	if (ft_strcmp(cmd[0], "env") == 0)
	{
		i = 0;
		while (environ[i])
		{
			ft_putendl(environ[i]);
			i++;
		}
	}
	else if (ft_strcmp(cmd[0], "setenv") == 0)
		ft_setenv_handler(&cmd[1]);
	else if (ft_strcmp(cmd[0], "unsetenv") == 0)
		ft_unsetenv_handler(&cmd[1]);
}
