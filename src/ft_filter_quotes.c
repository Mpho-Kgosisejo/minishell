/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filter_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 14:05:40 by mkgosise          #+#    #+#             */
/*   Updated: 2017/08/30 13:57:18 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minsh.h"

char	*filter(char *str)
{
	char	c;
	int		l;

	c = 0;
	l = 0;
	if (str[0] == '"' || str[0] == '\'')
	{
		c = str[0];
	}
	if (c)
	{
		l = ft_strlen(str) - 1;
		if (str[l] == c || str[l] == c)
		{
			return (ft_strsub(str, 1, l - 1));
		}
		else
			return (NULL);
	}
	return (ft_strdup(str));
}
