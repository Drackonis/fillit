/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:31:42 by rkergast          #+#    #+#             */
/*   Updated: 2019/02/01 21:23:22 by bviollet         ###   ########.fr       */
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
//printf("Piece : %c, i : %d, j : %d\n", piece->index + 65, p->x, p->y);
				if (check_piece(piece, carre, p->x, p->y) == 1)
				{
					piece->put = 1;
					p->y = 0;
					p->x = 0;
					piece = first;
					//while (piece && piece->put)
					//	piece = piece->next;
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

							int try = 0;
	piece = start;
//afficher(carre->tab);
	p = new_pos(0, 0);
//	if (piece->previous && piece->previous->index == 0)
//		piece = first;
	if (nbpiece == 1)
		carre = onepiece(carre, piece);
	else
		while (nbpiece != nbpieceposee(first))
		{
			while (piece && piece->put)
				piece = piece->next;
			carre = fill_loop(carre, first, p, nbpiece);
afficher(carre->tab);
printf("FillLoop : Try : %d\n", try);
			again(nbpiece, first, carre);
afficher(carre->tab);
printf("Deplacer : Try : %d\n", try++);
	getchar();
		//again(nbpiece, first, carre);	/* !!!!!!!!!!!!  CHANGEMENT ICI AVAT RECURSIVE, if au lieu de while */
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
//afficher(carre->tab);
	piece = first;
	while (piece->next)
		piece = piece->next;
	//piece = piece->next;
//printf("LAST PIECE: %c\n", piece->index + 65);
	while (piece->previous && !piece->put)
		piece = piece->previous;
//printf("LAST PIECE PUT: %c\n", piece->index + 65);
//piece = lastpieceput(carre, first);
	while (nbpieceposee(first) && piece && deplacerpiece(piece, carre, 0, 0) != 1)
	{
		while (piece->previous && !piece->put)
			piece = piece->previous;
	}
		//printf("{PREV DEL}LAST PIECE PUT: %c\n", piece->index + 65);
	//	piece = lastpieceput(carre, first);
		//piece = previouspieceput(carre, first, piece->index);
//printf("Previous piece put: %c\n", piece->index + 65);
//getchar();
		//piece = previouspieceput(carre, first, piece->index);
//printf("ENDEPLACE\n");
	//piece = piece && piece->next ? piece->next : first;
//printf("Before piece disorder\n");
	if (allpiecedisorder(carre->tab, carre->size))
	{
		again_loop(first);
		carre->size++;
		carre->tab = fill_tab(create_tab(carre, 0), carre->size);
		return ;
	}
	piece = first;  							/* LEQUEL ?? */
//	piece = lastpieceput(carre, first);
//printf("Before retsart fillit\n");
	return ;
	//carre = fill_it(carre, first, piece, nbpiece);       /* !!!!!!!!!!!!  CHANGEMENT ICI AVAT RECURSIVE */
}

int		deplacerpiece(t_piece *piece, t_carre *carre, int i, int j)
{
	while (i < carre->size - 1 && carre->tab[i][j] != ('A' + piece->index))
	{
		i = j == carre->size - 1 ? i + 1 : i;
		j = j == carre->size - 1 ? 0 : j + 1;
		/*j += j < carre->size - 1 ? 1 : -j;
		i += j == 0 ? 1 : 0;*/
//printf("1 * i : %d, j : %d\n", i, j);
	}
	j = realj(piece, j);
	carre->tab = rmv_tab('A' + piece->index, carre->tab);
	piece->put = 0;
	while (i < carre->size - 1)
	{
//printf("2 * i : %d, j : %d\n", i, j);
		i = j == carre->size - 1 ? i + 1 : i;
		j = j == carre->size - 1 ? 0 : j + 1;
		/*j = j < carre->size - 1 ? j + 1 : 0;
		i = j == 0 ? i + 1 : i;*/
//printf("Sent to Checkpiece i : %d, j : %d\n", i, j);
		if (check_piece(piece, carre, i, j) == 1)
		{
			piece->put = 1;
			return (1);
		}
	}
	return (0);
}
