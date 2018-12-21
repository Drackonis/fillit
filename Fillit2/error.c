/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:49:34 by bviollet          #+#    #+#             */
/*   Updated: 2018/12/21 14:52:07 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_numberline(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	i--;
	return (i);
}

int		sharpvalid(char **str, int tab[2], int k, char dir)
{
	if (k <= 3 && tab[1] < 4 && dir != 'g' && str[tab[0]][tab[1] + 1] == '#')
	{
		tab[1] = tab[1] + 1; /* check j + 1 */
		return (sharpvalid(str, tab, k + 1, 'd'));
	}
	if (k <= 3 && tab[1] > 0 && dir != 'd' && str[tab[0]][tab[1] - 1] == '#')
	{
		tab[1] = tab[1] - 1; /* check j - 1*/
		return (sharpvalid(str, tab, k + 1, 'g'));
	}
	if (k <= 3 && tab[0] > 0 && dir != 'h' && str[tab[0] - 1][tab[1]] == '#')
	{
		tab[0] = tab[0] - 1; /* check i - 1 */
		return (sharpvalid(str, tab, k + 1, 'b'));
	}
	if (k <= 3 && dir != 'b' && str[tab[0] + 1][tab[1]] == '#')
	{
		tab[0] = tab[0] + 1; /* check i + 1 */
		return (sharpvalid(str, tab, k + 1, 'h'));
	}
	if (k >= 4)
		return (1);
	if (dir == 'd' || dir == 'g')
		return (sharpvalid(str, tab, k - 1, 'a'));
	return (0);
}

int		ft_error2(int *i, int *ii, int *j, char **str)
{
	int	k;
	int	tab[2];

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
				tab[0] = *i + *ii;
				tab[1] = *j;
				if (k == 0)
					if (!(sharpvalid(str, tab, 1, 'a')))
						return (-1);
				k++;
			}
			*j = *j + 1;
		}
		*ii = *ii + 1;
	}
	return (k);
}

int		error(char **str)
{
	int		i;
	int		j;
	int		k;
	int		ii;

	i = 0;
	j = 0;
	while ((i <= ft_numberline(str)) && (str[i] != NULL))
	{
		k = 0;
		ii = 0;
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
