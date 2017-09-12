/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makeargs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 12:18:30 by mkgosise          #+#    #+#             */
/*   Updated: 2017/08/31 12:55:44 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minsh.h"

static char	**appendlist(char **list, char *in, int start, int end)
{
	char **tmpl;
	char *tmp;

	tmp = ft_strsub(in, start, end);
	tmpl = ft_listcat(list, tmp);
	free(tmp);
	ft_free2d((void**)list);
	return (list = tmpl);
}

static char	**err(char **list)
{
	ft_puterr(0, "shell", ": closing qoute not found", 1);
	ft_free2d((void**)list);
	return (NULL);
}

static void	skipspace(char *i, t_make *sa)
{
	while ((i[sa->x] != ' ' && i[sa->x] != '\'' && i[sa->x] != '"') && i[sa->x])
		sa->x++;
	if (sa->x != sa->i)
	{
		sa->ret = appendlist(sa->ret, i, sa->i, (sa->x - sa->i));
		sa->i = sa->x;
	}
}

char		**ft_makeargs(char *i, t_make st)
{
	if (!ft_strchr(i, '\'') && !ft_strchr(i, '"'))
		return (ft_strsplit_2(i));
	st.i = 0;
	st.ret = ft_listnew(0);
	while (i[st.i])
	{
		st.x = st.i;
		skipspace(i, &st);
		if ((i[st.i] == '\'' || i[st.i] == '"') && i[st.i])
		{
			st.c = i[st.i];
			st.x = 1;
			while (i[st.x + st.i] != st.c && i[st.x + st.i])
				st.x++;
			if (i[st.x + st.i] != st.c)
				return (err(st.ret));
			st.ret = appendlist(st.ret, i, st.i, (st.x + 1));
			st.i += st.x;
			st.c = 0;
		}
		if ((size_t)st.i++ > ft_strlen(i))
			break ;
	}
	return (st.ret);
}
