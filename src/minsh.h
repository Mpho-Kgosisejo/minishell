/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minsh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 14:08:28 by mkgosise          #+#    #+#             */
/*   Updated: 2017/08/31 12:42:52 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINSH_H
# define MINSH_H

# include "../libft/libft.h"
# include <sys/stat.h>

struct			s_do_cmd
{
	char *path;
	char **cmd;
};

struct			s_setenv_handler
{
	int		i;
	char	**var;
	char	*value;
};

struct			s_setenv
{
	char *tmp;
	char *env;
	char *newenv;
	char **tmpenv;
};

struct			s_main
{
	char **in;
	char *tmp;
};

struct			s_binapp
{
	char	*tmp;
	char	*path;
	char	**paths;
	int		i;
};

struct			s_cmd_prompt
{
	char	*tmp;
	char	*tmp2;
	char	**ret;
	char	*user;
};

struct			s_prepare_out
{
	int		i;
	char	**ret;
	char	**tmp;
	char	*str;
}				st;

struct			s_echo_write
{
	int		i;
	int		is_append;
	char	*tmp;
	char	*str;
	char	*file;
};

struct			s_echo
{
	char	**all;
	char	**output;
};

typedef struct	s_makeargs
{
	int		x;
	int		i;
	char	c;
	char	*tmp;
	char	**ret;
	char	**tmpl;
}				t_make;

void			ft_echo(char **cmd);
void			ft_env_handler(char **cmd);
void			ft_setenv_handler(char **cmd);
void			ft_unsetenv_handler(char **cmd);
void			ft_chdir(char **cmd);
void			update_envp_pwds(char *env);
void			ft_open_app(char *path, char **cmd);
char			*filter(char *str);
char			*ft_puterr(int ch, char *name, char *mssg, int new_line);
int				ft_item_listcmp(char **list, char *item);
char			*ft_getenv(char *name);
int				ft_setenv(char *name, char *value);
int				ft_unsetenv(char *name);
char			**ft_makeargs(char *input, t_make mk);
int				ft_echo_write(char **all);
char			**get_env(char **new);
char			*show_user_name(void);
char			**ft_strsplit_2(char *str);

#endif
