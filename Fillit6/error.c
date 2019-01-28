/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:56:30 by rkergast          #+#    #+#             */
/*   Updated: 2019/01/26 15:04:43 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		checkaround(char **str, int i, int j, int last)
{
	if (!last && str[i + 1] != NULL && str[i + 1][j] == '#')
		return (1);
	if (!last && j < 3 && str[i][j + 1] == '#')
		return (1);
	if (last && j > 0 && str[i][j - 1] == '#')
		return (1);
	if (last && i > 0 && str[i - 1][j] == '#')
		return (1);
	return (0);
}

int		sharpvalid(char **s, int t[2], int k, char dir)
{
	if (k <= 3 && t[1] < 3 && dir != 'g' && s[t[0]][t[1] + 1] == '#')
	{
		t[1] = t[1] + 1;
		return (sharpvalid(s, t, k + 1, 'd'));
	}
	if (k <= 3 && t[1] > 0 && dir != 'd' && s[t[0]][t[1] - 1] == '#')
	{
		t[1] = t[1] - 1;
		return (sharpvalid(s, t, k + 1, 'g'));
	}
	if (k <= 3 && t[0] > 0 && dir != 'h' && s[t[0] - 1][t[1]] == '#')
	{
		t[0] = t[0] - 1;
		return (sharpvalid(s, t, k + 1, 'b'));
	}
	if (k <= 3 && dir != 'b' && t[0] < ft_nbline(s) && s[t[0] + 1][t[1]] == '#')
	{
		t[0] = t[0] + 1;
		return (sharpvalid(s, t, k + 1, 'h'));
	}
	if (k >= 4)
		return (1);
	if (dir == 'd' || dir == 'g')
		return (sharpvalid(s, t, k - 1, 'a'));
	return (0);
}

int		ft_error2(int *i, int *ii, int *j, char **str)
{
	int	k;

	k = 0;
	while (str[*i + *ii] && str[*i + *ii][0] != '\0')
	{
		*j = 0;
		while (str[*i + *ii][*j] != '\0')
		{
			if (str[*i + *ii][*j] != '.' && str[*i + *ii][*j] != '#')
				return (-1);
			if (str[*i + *ii][*j] == '#')
			{
				if (k++ == 0 && check_errorft(str, *i + *ii, *j) == -1)
					return (-1);
			}
			*j = *j + 1;
		}
		*ii = *ii + 1;
	}
	return (k);
}

int		ft_err3(int i, char **str, int j, char mode)
{
	int	tab;

	tab = 10;
	while (mode == 'l' && str[i] && str[i][0])
	{
		if (ft_strchr(str[i], '#') && tab == 10)
			tab = 1;
		else if (!ft_strchr(str[i], '#') && tab == 1)
			tab = 0;
		else if (ft_strchr(str[i++], '#') && tab == 0)
			return (0);
	}
	while (mode == 'c' && str[i][j] && j++ < 3)
	{
		if (ft_strchrcol(str, i, j, '#') && tab == 10)
			tab = 1;
		else if (!ft_strchrcol(str, i, j, '#') && tab == 1)
			tab = 0;
		else if (ft_strchrcol(str, i, j, '#') && tab == 0)
			return (0);
	}
	return (1);
}

int		error(char **str)
{
	int		i;
	int		j;
	int		k;
	int		ii;

	i = 0;
	j = 0;
	while ((i <= ft_nbline(str)) && (str[i] != NULL))
	{
		k = 0;
		ii = 0;
		if (str[i][0] != '\0' && ((!ft_err3(i, str, -1, 'l')) ||\
					!ft_err3(i, str, -1, 'l')))
			return (0);
		while (str[i + ii] && str[i + ii][0] != '\0')
		{
			j = 0;
			if ((k = ft_error2(&i, &ii, &j, str)) == -1)
				return (0);
		}
		if ((ii != 4 || j != 4 || k != 4) || (ii == 0 && k == 0))
			return (0);
		i = i + ii + 1;
	}
	return (1);
}
