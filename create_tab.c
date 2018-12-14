/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:31:42 by rkergast          #+#    #+#             */
/*   Updated: 2018/12/14 16:18:35 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char **g_tab = NULL;

t_carre		*create_tab(int size)
{
	int			i;
	t_carre		*carre;

	i = 0;
	carre = ft_memalloc(sizeof(t_carre));
	carre->size = size;
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
	carre->tab = g_tab;
	return (carre);
}

t_carre		*fill_tab(t_carre *carre)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i != carre->size && j != carre->size)
	{
		carre->tab[j][i] = '.';
		i++;
		if (i >= carre->size)
		{
			i = 0;
			j++;
		}
	}
	return (carre);
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

void	place_piece(t_piece *piece, t_carre *carre, t_pos *pos, char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < piece->width)
	{
		j = 0;
		while (j < piece->height)
		{
			if (piece->tab[j][i] == '#')
				carre->tab[pos->y + j][pos->x + i] = c;
			j++;
		}
		i++;
	}
	ft_memdel((void **)&pos);
}

int	check_piece(t_piece *piece, t_carre *carre, int x, int y)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < piece->width)
	{
		j = 0;
		while (j < piece->height)
		{
			if (piece->tab[j][i] == '#' && carre->tab[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	place_piece(piece, carre, new_pos(x, y), piece->skin);
	return (1);
}

t_carre		*fill_it(t_carre *carre)
{
	int		i;
	int		j;

	i = 0;
	while (i < carre->size)
	{
		j = 0;
		while (j < carre->size)
		{
			if (carre->tab[i][j] == '.')
			{
				carre->tab[i][j] = 'P';
			}
			j++;
		}
		i++;
	}
	return (carre);
}

int		main(void)
{
	t_carre *carre;
	int		size;
	int		i;

	size = 12;
	i = 0;
	carre = create_tab(size);
	carre = fill_tab(carre);
	carre = fill_it(carre);
	while (i < size)
	{
		printf ("%s\n", carre->tab[i]);
		i++;
	}
	return 0;
}

