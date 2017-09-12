/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 16:37:30 by mkgosise          #+#    #+#             */
/*   Updated: 2017/07/30 17:41:44 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minsh.h"
#include <sys/types.h>
#include <fcntl.h>

static int	do_write(char *file, int is_append, char *data)
{
	int	fd;

	if (is_append)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	else
		fd = open(file, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		ft_puterr(0, "echo", ": error trying to write to file", 1);
		return (-1);
	}
	ft_putendl_fd(data, fd);
	if (close(fd) == -1)
	{
		ft_puterr(0, "echo", ": error trying to close file", 1);
	}
	return (1);
}

int			ft_echo_write(char **all)
{
	struct s_echo_write st;

	st.i = 1;
	st.is_append = 0;
	st.str = ft_strnew(1);
	while (all[st.i])
	{
		if (!ft_strcmp(all[st.i], ">") || !ft_strcmp(all[st.i], ">>"))
		{
			if (ft_strcmp(all[st.i], ">>") == 0)
				st.is_append = 1;
			st.file = all[st.i + 1];
			st.i += 2;
			continue ;
		}
		st.tmp = ft_strjoin(st.str, all[st.i]);
		free(st.str);
		st.str = ft_strjoin(st.tmp, " ");
		free(st.tmp);
		st.i++;
	}
	do_write(st.file, st.is_append, st.str);
	free(st.str);
	return (1);
}
