/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 11:54:16 by mkgosise          #+#    #+#             */
/*   Updated: 2017/08/31 12:43:04 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minsh.h"

static int	is_split(char c)
{
	if (c == '\t' || c == ' ' || c == '\n')
		return (1);
	return (0);
}

static int	words(char *str)
{
	int	i;
	int bul;
	int count;

	i = 0;
	bul = 0;
	count = 0;
	while (str[i])
	{
		if (bul == 0 && !is_split(str[i]))
		{
			count++;
			bul = 1;
		}
		if (bul == 1 && is_split(str[i]))
			bul = 0;
		i++;
	}
	return (count);
}

static char	*get_word(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	while (str[i] && !is_split(str[i]))
		i++;
	ret = ft_strnew(i);
	ft_strncpy(ret, str, i);
	return (ret);
}

char		**ft_strsplit_2(char *str)
{
	int		l;
	int		bul;
	char	**ret;

	if (!(l = words(str)))
		return (NULL);
	if (!(ret = (char**)malloc(sizeof(ret) * (l + 1))))
		return (NULL);
	ret[l] = 0;
	l = 0;
	bul = 0;
	while (*str)
	{
		if (bul == 0 && !is_split(*str))
		{
			ret[l] = get_word(str);
			l++;
			bul = 1;
		}
		if (bul == 1 && is_split(*str))
			bul = 0;
		str += 1;
	}
	return (ret);
}
