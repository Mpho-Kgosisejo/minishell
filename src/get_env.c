/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 15:33:02 by mkgosise          #+#    #+#             */
/*   Updated: 2017/08/19 15:54:59 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minsh.h"

char	**get_env(char **new)
{
	static char	**ret;

	if (new == NULL)
	{
		if (ret == NULL)
			return (NULL);
		return (ret);
	}
	return ((ret = new));
}
