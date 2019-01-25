/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:37:22 by rkergast          #+#    #+#             */
/*   Updated: 2019/01/10 15:51:44 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_sqrt_up(int nb)
{
	int		i;

	i = 2;
	while (i * i < nb)
		i++;
	return (i);
}

void		taille(t_pos *tab0, t_pos *tab1, char **ptr)
{
	if (ptr[tab0->x][tab0->y] == '#')
	{
		if (tab1->x < tab0->x)
			tab1->x = tab0->x;
		if (tab1->y < tab0->y)
			tab1->y = tab0->y;
	}
}

int			nbpieceposee(t_piece *first)
{
	int		final;
	t_piece	*piece;

	final = 0;
	piece = first;
	while (piece->next)
	{
		if (piece->put == 1)
			final++;
		piece = piece->next;
	}
	if (piece->put == 1)
		final++;
	return (final);
}

void		place_piece(t_piece *piece, t_carre *carre, t_pos *pos, int c)
{
	int		i;
	int		j;

	i = 0;
	while (pos->x + i < carre->size && i < piece->ij.x + 1)
	{
		j = 0;
		while (pos->y + j < carre->size && j < piece->ij.y + 1)
		{
			if (piece->ptr[i][j] == '#')
				carre->tab[pos->x + i][pos->y + j] = 'A' + c;
			j++;
		}
		i++;
	}
	if (pos)
		free(pos);
}

int			check_piece(t_piece *piece, t_carre *carre, int x, int y)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (x + i < carre->size && i < piece->ij.x + 1)
	{
		j = 0;
		while (y + j < carre->size && j < piece->ij.y + 1)
		{
			if (piece->ptr[i][j] == '#' && carre->tab[x + i][y + j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	if (j < piece->ij.y + 1 || i < piece->ij.x + 1)
		return (0);
	place_piece(piece, carre, new_pos(x, y), piece->index);
	return (1);
}
