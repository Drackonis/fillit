/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:31:42 by rkergast          #+#    #+#             */
/*   Updated: 2019/02/05 16:55:53 by bviollet         ###   ########.fr       */
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
printf("Piece : %c, i : %d, j : %d\n", piece->index + 65, p->x, p->y);
				if (check_piece(piece, carre, p->x, p->y) == 1)
				{
					piece->put = 1;
					p->y = -1;
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
			//while (piece && piece->put)
			//	piece = piece->next;
printf("\n-----------------\nFillLoop : Try : %d\n\n", try);
			carre = fill_loop(carre, first, p, nbpiece);
afficher(carre->tab);
	getchar();
printf("\n-----------------\nDEPLACEMENT : Try : %d\n\n", try);
			again(nbpiece, first, carre);
afficher(carre->tab);
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

//piece = lastpieceput(carre, first, '\0');
//printf("LAST PIECE PUT: %c\n", piece->index + 65);


	while (piece && nbpieceposee(first) && deplacerpiece(piece, carre, 0, 0) != 1)
	{
afficher(carre->tab);
//		if (!(piece = lastpieceput(carre, first, piece->index + 65)))
//			break ;
		while (piece && piece->previous && !piece->put)
			piece = piece->previous;
printf("NEW PIECE DEPLACEMENT INTERIEUR WHILE: %c\n", piece->index + 65);
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
	}
//	piece = lastpieceput(carre, first);
//printf("Before retsart fillit\n");
	return ;
	//carre = fill_it(carre, first, piece, nbpiece);       /* !!!!!!!!!!!!  CHANGEMENT ICI AVAT RECURSIVE */
}

int		deplacerpiece(t_piece *piece, t_carre *carre, int i, int j)
{
	while (i < carre->size && carre->tab[i][j] != ('A' + piece->index))
	{
		i = j == carre->size - 1 ? i + 1 : i;
		j = j == carre->size - 1 ? 0 : j + 1;
printf("IJIJIJ  i : %d, j : %d\n", i, j);
	}
printf("AVANT REALJ Piece a depacer trouve : %c, i %d, j %d\n", piece->index + 65, i, j);
	j = realj(piece, j);
printf("APRES REALJ Piece a depacer trouve : %c, i %d, j %d\n", piece->index + 65, i, j);
	carre->tab = rmv_tab('A' + piece->index, carre->tab);
	piece->put = 0;
	while (i < carre->size)
	{
		i = j == carre->size - 1 ? i + 1 : i;
		j = j == carre->size - 1 ? 0 : j + 1;
//printf("2 * i : %d, j : %d\n", i, j);
		/*j = j < carre->size - 1 ? j + 1 : 0;
		i = j == 0 ? i + 1 : i;*/
//printf("Sent to Checkpiece i : %d, j : %d\n", i, j);
printf("Piece en cours de deplacement : %c, position i : %d, j : %d\n", piece->index + 65, i, j);
		if (i < carre->size && check_piece(piece, carre, i, j) == 1)
		{
	printf("Piece deplacer succes : %c\n", piece->index + 65);
			piece->put = 1;
			return (1);
		}
	}
	printf("Piece supprime : %c\n", piece->index + 65);
	return (0);
}

t_piece	*lastpieceput(t_carre *carre, t_piece *first, char c)
{
	int	i;
	int	j;
	int	b;

write(1, "Aa\n", 3);
	b = c == '\0' ? 1 : 0;	// mettre a 1 lorsqu'on a depasse la piece recherche
	i = carre->size - 1;
	j = carre->size - 1;
	while (i > -1 && j > -1)
	{
printf("Last piece envoye : %c, i : %d, j: %d\n", c, i, j);
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
printf("Last piece trouve : %c, i : %d, j: %d\n", c, i, j);
	while (first && first->index != c - 65)
		first = first->next;
write(1, "Bb\n", 3);
	return (first);
}
