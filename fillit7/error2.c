/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:56:30 by rkergast          #+#    #+#             */
/*   Updated: 2019/01/26 15:05:40 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_errorft(char **str, int tab1, int tab2)
{
	int	t[2];

	t[0] = tab1;
	t[1] = tab2;
	if (!isconx(str, tab1, tab2))
		return (-1);
	if (!sharpvalid(str, t, 1, 'a'))
		return (-1);
	return (1);
}

int		isconx(char **s, int i, int j)
{
	int	k;
	int	ii;

	ii = 0;
	k = 0;
	while (s[i] && s[i][0])
	{
		if (s[i][j] == '#')
		{
			if (++k == 4 && checkaround(s, i, j, 1))
				return (1);
			if (checkaround(s, i, j, 0) == 0)
			{
				if (ii)
					ii = 0;
				else
					return (0);
			}
			if (j < 3 && s[i][j + 1] == '#' && s[i + 1] && s[i + 1][j] == '#')
				ii = 1;
		}
		i += j == 3 ? 1 : 0;
		j += j == 3 ? -j : 1;
	}
	return (1);
}
