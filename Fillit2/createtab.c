/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:31:42 by rkergast          #+#    #+#             */
/*   Updated: 2018/12/22 13:32:55 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main_create_tab(t_piece *first, int nbpiece)
{
	t_carre *carre;
	int		i;

	carre = (t_carre*)malloc(sizeof(carre));
	i = 0;
	carre->size = ft_sqrt_up(nbpiece * 4);
	//carre->tab = (char**)malloc(sizeof(carre->tab) * 1);
	carre->tab = NULL;
	carre->tab = fill_tab(create_tab(carre), carre->size);
	afficher(carre->tab);
	carre = fill_it(carre, first, first,  nbpiece);

	afficher(carre->tab);
	
	if (carre->tab)
	{
		while (carre->tab[i])
			free(carre->tab[i++]);
		free(carre->tab);
	}
	free(carre);
	return (0);
}

char		**create_tab(t_carre *carre)
{
	int			i;
	char	**tmp;

	tmp = carre->tab;
	i = 0;
	if (!(carre->tab = (char**)malloc(sizeof(char*) * (carre->size + 1))))
		exit (-1);
	while (i < carre->size) /* !!!ERREUR EVENTUELLE  avant <= mais on malloc NULL a la fin a priori donc < seulement */
	{
		if (!(carre->tab[i] = (char*)malloc(sizeof(char*) * (carre->size + 1))))
			exit (-1);
		carre->tab[i][carre->size] = '\0';
		i++;
	}
	carre->tab[carre->size] = NULL;
	i = 0;
	if (tmp)
	{
		while (tmp[i])
			free(tmp[i++]);
		free(tmp);
	}
	return (carre->tab);
}

char		**fill_tab(char **tab, int size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;

	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			tab[i][j] = '.';
			j++;
		}
		i++;
	}
	return (tab);
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

t_pos	*new_pos(int x, int y)
{
	t_pos	*pos;

	pos = ft_memalloc(sizeof(t_pos));
	pos->x = x;
	pos->y = y;
	return (pos);
}
