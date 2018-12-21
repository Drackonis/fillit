/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:12:15 by bviollet          #+#    #+#             */
/*   Updated: 2018/12/21 21:04:40 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	movepieces(char **str, int i, int j, int nbpiece)
{
	int	a;
	int	*tab;

	a = 1;
	while (i < ft_numberline(str) + 1)
	{
		if (str[i][0] == '\0')
		{
			free(tab);
			a = 1;
		}
		while (j < 4)
		{
			if (str[i][j] == '#' && a == 1)
			{
				tab = movediff(str, i, j, nbpiece);
				a = movepieces2(&nbpiece);
			}
			if (str[i][j] == '#' && a == 0)
				movep(str, i, j, tab);
			j++;
		}
		i++;
		j = 0;
	}
}

void	movep(char **str, int i, int j, int *tab)
{
	str[i - tab[0]][j - tab[1]] = '#';
	if (tab[0] != 0 || tab[1] != 0)
		str[i][j] = '.';
}

int		movepieces2(int *nbpiece)
{
	*nbpiece = *nbpiece + 1;
	return (0);
}

int		*movediff(char **str, int i, int j, int nbpiece)
{
	int	*tab;

	tab = malloc(sizeof(int) * 2);
	if (i > 0 && j > 1 && str[i + 1][j - 2] == '#')
	{
		if (j == 2)
			j = 0;
		else
			j = 1;
	}
	else if (i > 0 && j > 0 && str[i + 1][j - 1] == '#')
		j--;
	tab[1] = j;
	tab[0] = i - nbpiece * 5;
	return (tab);
}
