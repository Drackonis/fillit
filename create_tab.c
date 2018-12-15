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

static t_carre		*create_tab(int size)
{
	int			i;
	t_carre		*carre;
	char	**g_tab;

	i = 0;
	g_tab = NULL;
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

static t_carre		*fill_tab(t_carre *carre)
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

static char	**rmv_tab(char c, char **tab)
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

static t_pos	*new_pos(int x, int y)
{
	t_pos	*pos;

	pos = ft_memalloc(sizeof(t_pos));
	pos->x = x;
	pos->y = y;
	return (pos);
}

static void	place_piece(t_piece *piece, t_carre *carre, t_pos *pos, int c)
{
	int	i;
	int	j;

	i = 0;
	printf ("x : %d // y : %d\n", piece->ij.x, piece->ij.y);
	while (i < piece->ij.y + 1)
	{
		j = 0;
		while (j < piece->ij.x + 1)
		{
			printf ("\n%c|%d|%d\n", piece->ptr[j][i], i , j);
			if (piece->ptr[j][i] == '#')
				carre->tab[pos->y + j][pos->x + i] = 'A' + c;
			j++;
		}
		i++;
	}
	ft_memdel((void **)&pos);
}

static int	check_piece(t_piece *piece, t_carre *carre, int x, int y)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < piece->ij.y + 1)
	{
		j = 0;
		while (j < piece->ij.x + 1)
		{
			if (piece->ptr[j][i] == '#' && carre->tab[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	printf ("PLACE PIECE\n");
	place_piece(piece, carre, new_pos(x, y), piece->index);
	return (1);
}

static t_carre		*fill_it(t_carre *carre, t_piece *first, int nbpiece)
{
	int		i;
	int		j;
	int		t;
	t_piece		*piece;

	i = 0;
	t = 0;
	piece = first;
	while (i < carre->size)
	{
		j = 0;
		while (j < carre->size)
		{
			if (carre->tab[i][j] == '.')
			{
				while (t == 0)
				{
					printf ("CHECK PIECE %d\n\n\n", piece->index);
					while (piece->put == 1 && piece->next)
						piece = piece->next;
					t = check_piece(piece, carre, j, i);
					if (t == 1)
						piece->put = 1;
					if (!piece->next)
						break ;
					piece = piece->next;
				}
				t = 0;
				piece = first;
			}
			j++;
		}
		i++;
	}
	return (carre);
}

int		main_create_tab(t_piece *first, int nbpiece)
{
	t_carre *carre;
	int	size;
	int		i;

	i = 0;
	printf ("\n\n\n-------------------------------------------\n\n\n");
	size = ft_sqrt_up(nbpiece * 4);
	printf ("size : %d // nbpiece : %d\n\n", size, nbpiece);
	carre = create_tab(size);
	carre = fill_tab(carre);
	carre = fill_it(carre, first, nbpiece);
	while (i < size)
	{
		printf ("%s\n", carre->tab[i]);
		i++;
	}
	return 0;
}

