/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:31:42 by rkergast          #+#    #+#             */
/*   Updated: 2019/01/26 18:29:58 by bviollet         ###   ########.fr       */
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
		while (piece->put != 1 && p->x++ < carre->size)
		{
			p->y = -1;
			while (piece->put != 1 && p->y++ < carre->size)
			{
				if (check_piece(piece, carre, p->x, p->y) == 1)
				{
ft_putstr("\n______FILL LOOP\n");
printf("Piece current : %c, x : %d, y : %d\n", (piece->index) + '0', p->x, p->y);
afficher(carre->tab);
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
ft_putstr("\n______END LOOP\n");
afficher(carre->tab);
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

t_piece	*lastpieceput(char **tab, t_piece *piece, int size)
{
	int	i;
	int	j;

	i = size - 1;
	j = size - 1;
	while (i > -1 && j > -1 && tab[i][j] == '.')
	{
		i = j == 0 ? i - 1 : i;
		j = j == 0 ? size : j - 1;
	}
	if (i < 0 || j < 0)
		return (NULL);
	i = tab[i][j];
printf("i : %d\n", i);
	while (piece && piece->index != i - 65)
		piece = piece->next;
	return (piece);
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
//piece = lastpieceput(carre->tab, first, carre->size - 1);
	try++;
	piece = piece && piece->next ? piece->next : first;
	//if (try == nbpiece * nbpiece * nbpiece * nbpiece * nbpiece * nbpiece)
	if (lastpieceput(carre->tab, first, carre->size) == first)
	{
		try = 0;
		again_loop(first);
		carre->size++;
printf("Increase size tab to %d\n", carre->size);
		carre->tab = fill_tab(create_tab(carre, 0), carre->size);
		carre = fill_it(carre, first, first, nbpiece);
		return ;
	}
printf("Piece envoye a fill_it : %c\n", (char)piece->index + 65);
//getchar();
	carre = fill_it(carre, first, piece, nbpiece);
}

int		deplacerpiece(t_piece *piece, t_carre *carre, int i, int j)
{
printf("\n______DEBUT DEPLACER : %c\n", (char)(piece->index + 65));
//getchar();
afficher(carre->tab);
	while (i < carre->size && carre->tab[i][j] != ('A' + piece->index))
	{
		j += j < carre->size ? 1 : -j;
		i += j == 0 ? 1 : 0;
	}
printf("Test debut deplacer, i : %d, j : %d\n", i, j);
/*
	if (i < 3 && j > 1 && carre->tab[i + 1][j - 2] == 'A' + piece->index)
		j = j - 2;
	else if (i < 3 && j > 0 && carre->tab[i + 1][j - 1] == 'A' + piece->index)
		j--;
	else if (carre->size > 3 && i < 2 && j > 0 &&\
			carre->tab[i + 2][j - 1] == 'A' + piece->index)
		j--;*/
	j = realj(piece, j);
	carre->tab = rmv_tab('A' + piece->index, carre->tab);
	piece->put = 0;
	while (i < carre->size)
	{
		j = j < carre->size ? j + 1 : 0;
		i = j == 0 ? i + 1 : i;
printf("\nI envoye a checkpiece : %d\n", i);
printf("J envoye a checkpiece : %d\n", j);
printf("Jreal envoye a checkpiece : %d\n", realj(piece, j));

/* ICI IL FAUT SI LA PIECE EST PARTICULIERE (GENRE i -1 et j -2 == '#') envoyer non pas j mais j - 2 dans le cas d'erreur ici */
/* !! Probablement checker avec i aussi */

		//if (check_piece(piece, carre, i, realj(piece, j)) == 1)
		if (check_piece(piece, carre, i, j) == 1)
		{
			piece->put = 1;
ft_putstr("\n______FIN DEPLACER AVEC SUCCES\n");
afficher(carre->tab);
			return (1);
		}
	}
ft_putstr("\n______FIN DEPLACER\n");
afficher(carre->tab);
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
