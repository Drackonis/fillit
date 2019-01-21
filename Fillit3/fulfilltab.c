/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:31:42 by rkergast          #+#    #+#             */
/*   Updated: 2019/01/17 14:17:16 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_carre	*fill_loop(t_carre *carre, t_piece *piece, t_pos *p, int nbpiece)
{
	t_piece		*first;

	first = piece;
	while (piece)
	{
		p->x = -1;
		while (piece->put != 1 && p->x++ < carre->size)
		{
			p->y = -1;
			while (piece->put != 1 && p->y++ < carre->size)
			{
				if (check_piece(piece, carre, p->x, p->y) == 1)
				{
					piece->put = 1;
					p->y = -1;
					p->x = 0;
					piece = first;
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
	if (piece->previous && piece->previous->index == 0)
		piece = first;
	if (nbpiece == 1)
		carre = onepiece(carre, piece);
	else
		carre = fill_loop(carre, piece, p, nbpiece);
	free(p);
	if (nbpiece != nbpieceposee(first))
		again(nbpiece, first, carre);
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
	static int	try = 0;
	t_piece		*piece;

	piece = first;
	while (piece->next)
		piece = piece->next;
	while (piece->previous && piece->put == 0)
		piece = piece->previous;
	while (piece && deplacerpiece(piece, carre, 0, 0) != 1)
		while (piece && piece->put == 0)
			piece = piece->previous;
	try++;
	piece = piece && piece->next ? piece->next : first;
	if (try == nbpiece * nbpiece * nbpiece)
	{
		try = 0;
		again_loop(first);
		carre->size++;
		carre->tab = fill_tab(create_tab(carre, 0), carre->size);
		carre = fill_it(carre, first, first, nbpiece);
		return ;
	}
	carre = fill_it(carre, first, piece, nbpiece);
}

int		deplacerpiece(t_piece *piece, t_carre *carre, int i, int j)
{
	while (i < carre->size && carre->tab[i][j] != ('A' + piece->index))
	{
		j += j < carre->size ? 1 : -j;
		i += j == 0 ? 1 : 0;
	}
	if (i < 3 && j > 1 && carre->tab[i + 1][j - 2] == 'A' + piece->index)
		j = j - 2;
	else if (i < 3 && j > 0 && carre->tab[i + 1][j - 1] == 'A' + piece->index)
		j--;
	else if (carre->size > 3 && i < 2 && j > 0 &&\
			carre->tab[i + 2][j - 1] == 'A' + piece->index)
		j--;
	carre->tab = rmv_tab('A' + piece->index, carre->tab);
	piece->put = 0;
	while (i < carre->size)
	{
		j = j < carre->size ? j + 1 : 0;
		i = j == 0 ? i + 1 : i;
		if (check_piece(piece, carre, i, j) == 1)
		{
			piece->put = 1;
			return (1);
		}
	}
	return (0);
}
/*
**void	movepiece(t_carre *carre, t_piece *piece, int i, int j)
**{
**	while (i < carre->size)
**	{
**		while (j < carre->size)
**		{
**			if (carre->tab[i][j] == 'A' + piece->index)
**				break ;
**			j++;
**		}
**		j = 0;
**		i++;
**	}
**	carre->tab = rmv_tab('A', carre->tab);
**	if (j < carre->size)
**		j++;
**	else
**	{
**		i++;
**		j = 0;
**	}
**	while (i < carre->size)
**	{
**		while (j < carre->size)
**		{
**			if (check_piece(piece, carre, j, i) == 1)
**				break ;
**			j++;
**		}
**		j = 0;
**		i++;
**	}
**}
*/
