/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:31:42 by rkergast          #+#    #+#             */
/*   Updated: 2018/12/12 16:41:07 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char **g_tab = NULL;

char	**create_tab(int size)
{
	int		i;

	i = 0;
	if (g_tab)
	{
		while (g_tab[i])
		{
			free(g_tab[i]);
			g_tab = NULL;
			i++;
		}
	}
	i = 0;
	if (!(g_tab = (char**)malloc(sizeof(char*) * size + 1)))
		return (NULL);
	while (i <= size)
	{
		if (!(g_tab[i] = (char*)malloc(sizeof(char*) * size + 1)))
			return (NULL);
		g_tab[i][size + 1] = '\0';
		i++;
	}
	g_tab[i] = NULL;
	return (g_tab);
}


char	**rmv_tab(char c, char **tab)
{
	int		i;
	int		j;

	j = 0;
	if (c < 65 || c > 90)
		return (NULL);
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (tab[j][i] == c)
				tab[j][i] = '.';
			i++;
		}
		j++;
	}
	return (tab);
}
/*
int		main(void)
{
	char **tab;
	int		size;
	int		i;
	int		j;

	tab = NULL;
	size = 12;
	i = 0;
	j = 0;
	tab = create_tab(size);
	while (i != size && j != size)
	{
		tab[j][i] = 'A' + i + j;
		i++;
		if (i >= size)
		{
			i = 0;
			j++;
		}
	}
	i = 0;
	while (i < size)
	{
		printf ("%s\n", tab[i]);
		i++;
	}
	printf ("---------- rmv_tab F/K/R : -------------\n");
	tab = rmv_tab('F', tab);
	tab = rmv_tab('K', tab);
	tab = rmv_tab('R', tab);
	i = 0;
	while (i < size)
	{
		printf ("%s\n", tab[i]);
		i++;
	}
	return 0;
}
*/
