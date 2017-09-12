/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 12:06:24 by mkgosise          #+#    #+#             */
/*   Updated: 2017/08/19 15:49:15 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minsh.h"

static char	*output(char *name)
{
	char	*env;

	if (ft_strncmp(name, "$", 1) == 0 && ft_strlen(name) > 1)
	{
		if ((env = ft_getenv(&name[1])))
			return (env);
		else
			return (NULL);
	}
	else
		return (name);
}

static char	**prepare_out(char **argv)
{
	if (countlist(argv))
	{
		st.i = -1;
		st.ret = ft_listnew(0);
		while (argv[++st.i])
		{
			if (!ft_strcmp(argv[st.i], ">") || !ft_strcmp(argv[st.i], ">>"))
			{
				st.i++;
				if (st.i == countlist(argv))
					return (NULL);
			}
			else
			{
				if ((st.str = output(argv[st.i])))
				{
					st.tmp = ft_listcat(st.ret, st.str);
					ft_free2d((void**)st.ret);
					st.ret = st.tmp;
				}
			}
		}
		return (st.ret);
	}
	return (NULL);
}

char		**do_filter(char **argv)
{
	int		i;
	char	*str;

	i = 0;
	while (argv[i])
	{
		if ((str = filter(argv[i])))
		{
			ft_updatelist(argv, argv[i], str);
			free(str);
		}
		else
		{
			ft_puterr(0, "echo", ": bad assignment of quote", 1);
			return (NULL);
		}
		i++;
	}
	return (argv);
}

static void	print_out(char **data)
{
	int i;

	if (countlist(data) <= 0)
		return ;
	i = 0;
	while (data[i])
	{
		ft_putstr(data[i]);
		if (data[i + 1] != 0)
			ft_putchar(' ');
		i++;
	}
}

void		ft_echo(char **argv)
{
	struct s_echo st;

	if (do_filter(argv) == NULL)
		return ;
	if (ft_item_listcmp(argv, ">") || ft_item_listcmp(argv, ">>"))
	{
		st.all = ft_listdup(argv);
		if ((st.output = prepare_out(&argv[1])) != NULL)
		{
			ft_echo_write(st.all);
			ft_free2d((void**)st.all);
			ft_free2d((void**)st.output);
		}
		else
			ft_puterr(0, "echo", ": no descriptor", 1);
	}
	else
	{
		if ((st.output = prepare_out(&argv[1])) != NULL)
		{
			print_out(st.output);
			ft_free2d((void**)st.output);
		}
		ft_putchar('\n');
	}
}
