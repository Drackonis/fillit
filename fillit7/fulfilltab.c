/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:31:42 by rkergast          #+#    #+#             */
/*   Updated: 2019/02/05 16:42:45 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>
t_carre	*fill_loop(t_carre *carre, t_piece *piece, t_pos *p, int nbpiece)
{
	t_piece		*first;

	first = piece;
	while (piece)
	{
		p->x = -1;
		while (piece->put != 1 && p->x++ < carre->size - 1)
		{
			p->y = -1;
			while (piece->put != 1 && p->y++ < carre->size - 1)
			{
				if (check_piece(piece, carre, p->x, p->y) == 1)
				{
					piece->put = 1;
					p->y = 0;
					p->x = 0;
					piece = first;
					while (piece && piece->put)
						piece = piece->next;
					if (nbpiece == nbpieceposee(first))
						return (carre);
				}
			}
		}
		piece = piece->next;
	}
	return (carre);
}

t_carre	*fill_it(t_carre *carre, t_piece *first, t_piece *start, int nbpiece)
{
	t_pos	*p;
	t_piece	*piece;

	piece = start;
	p = new_pos(0, 0);
	if (nbpiece == 1)
		carre = onepiece(carre, piece);
	else
		while (nbpiece != nbpieceposee(first))
		{
			carre = fill_loop(carre, first, p, nbpiece);
			again(nbpiece, first, carre);
		}
	free(p);
	return (carre);
}

void	again_loop(t_piece *piece)
{
	while (piece->next)
	{
		piece->put = 0;
		piece = piece->next;
	}
	piece->put = 0;
}

void	again(int nbpiece, t_piece *first, t_carre *carre)
{
	t_piece		*piece;

	if (nbpiece == nbpieceposee(first))
		return ;
	piece = first;
	while (piece->next)
		piece = piece->next;
	while (piece->previous && !piece->put)
		piece = piece->previous;

	while (piece && nbpieceposee(first) && deplacerpiece(piece, carre, 0, 0) != 1)
	{
		while (piece && piece->previous && !piece->put)
			piece = piece->previous;
	}
	if (allpiecedisorder(carre->tab, carre->size))
	{
		again_loop(first);
		carre->size++;
		carre->tab = fill_tab(create_tab(carre, 0), carre->size);
	}
	return ;
}

int		deplacerpiece(t_piece *piece, t_carre *carre, int i, int j)
{
	while (i < carre->size && carre->tab[i][j] != ('A' + piece->index))
	{
		i = j == carre->size - 1 ? i + 1 : i;
		j = j == carre->size - 1 ? 0 : j + 1;
	}
	j = realj(piece, j);
	carre->tab = rmv_tab('A' + piece->index, carre->tab);
	piece->put = 0;
	while (i < carre->size)
	{
		i = j == carre->size - 1 ? i + 1 : i;
		j = j == carre->size - 1 ? 0 : j + 1;
		if (i < carre->size && check_piece(piece, carre, i, j) == 1)
		{
			piece->put = 1;
			return (1);
		}
	}
	return (0);
}

t_piece	*lastpieceput(t_carre *carre, t_piece *first, char c)
{
	int	i;
	int	j;
	int	b;

	b = c == '\0' ? 1 : 0;	// mettre a 1 lorsqu'on a depasse la piece recherche
	i = carre->size - 1;
	j = carre->size - 1;
	while (i > -1 && j > -1)
	{
		if (carre->tab[i][j] == c)
			b = 1;
		if (b && carre->tab[i][j] != '.' && carre->tab[i][j] != c)
			break ;
		i = j == 0 ? i - 1 : i;
		j = j == 0 ? carre->size - 1 : j - 1;
	}
	if (i < 0 || j < 0)
		return (NULL);
	c = carre->tab[i][j];
	while (first && first->index != c - 65)
		first = first->next;
	return (first);
}
