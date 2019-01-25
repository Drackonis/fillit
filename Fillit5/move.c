/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:12:15 by bviollet          #+#    #+#             */
/*   Updated: 2019/01/25 16:13:37 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>
void	movepieces(char **str, int i, int j, int nbpiece)
{
	int	a;
	int	*tab;

//	afficher(str);
//	ft_putstr("\n------\n");
	a = 1;
	while (++i < ft_numberline(str) + 1)
	{
		if (str[i][0] == '\0')
		{
			free(tab);
			a = 1;
		}
		while (j++ < 4)
		{
			if (str[i][j] == '#' && a == 1)
			{
				tab = movediff(str, i, j, nbpiece);
			//printf("Tab0 : %d, tab1 : %d\n", tab[0], tab[1]);
				a = movepieces2(&nbpiece);
			}
			if (str[i][j] == '#' && a == 0)
				movep(str, i, j, tab);
		}
		j = -1;
	}
	if (tab)
		free(tab);
//	afficher(str);
}

void	movep(char **str, int i, int j, int *tab)
{
	if (i - tab[0] < 0 || j - tab[1] < 0)
		return ;
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

//printf("i : %d, j : %d\n", i, j);
	if (!(tab = malloc(sizeof(int) * 2)))
		exit(-1);
	if (i < ft_numberline(str) && j > 1 && str[i + 1][j - 2] == '#')
		j = j - 2;
	else if (i + 1 <= ft_numberline(str) && j > 0 && str[i + 1][j - 1] == '#')
		j--;
	else if (i + 2 <= ft_numberline(str) && j > 0 && str[i + 2][j - 1] == '#')
		j--;
//printf("i : %d, j : %d\n", i, j);
	tab[1] = j;
	tab[0] = i - nbpiece * 5;
	return (tab);
}
