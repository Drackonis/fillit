/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:31:42 by rkergast          #+#    #+#             */
/*   Updated: 2019/01/08 16:04:44 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_carre	*fill_it(t_carre *carre, t_piece *first, t_piece *start, int nbpiece)
{
	int		i;
	int		j;
	int		t;
	int		k;
	t_piece	*piece;

	piece = start;
	if (piece->previous && piece->previous->index == 0)
		piece = first;
	t = 0;
	k = 0;
	while (piece)
	{
		printf("Nbpieceposee : %d, piece->put : %d\n",\
				nbpieceposee(first), piece->put);
		i = 0;
		while (piece->put != 1 && i < carre->size)
		{
			j = 0;
			while (piece->put != 1 && j < carre->size)
			{
				if (piece->put != 1 && check_piece(piece, carre, i, j) == 1)
				{
					afficher(carre->tab);
					//getchar();
					piece->put = 1;
					j = -1;
					i = 0;
					piece = first;
					printf("{ %d }\n", nbpieceposee(first));
					if (nbpiece == nbpieceposee(first))
						return (carre);
				}
				j++;
			}
			i++;
		}
		piece = piece->next;
		//else
		//	piece = first;
		k++;
	}
	afficher(carre->tab);
	if (nbpiece != nbpieceposee(first))
		again(nbpiece, first, carre);
	return (carre);
}

void	again(int nbpiece, t_piece *first, t_carre *carre)
{
	static int	nbrm = 0;
	static int	try = 0;
	static int	start = 0;
	int			cpt;
	t_piece		*piece;

	(void)cpt;
	(void)nbrm;
	(void)start;
	piece = first;
	while (piece->next)
		piece = piece->next;
	while (piece->previous && piece->put == 0)
		piece = piece->previous;
	while (piece && deplacerpiece(piece, carre) != 1)
		while (piece && piece->put == 0)
			piece = piece->previous;
	try++;
	if (piece && piece->next)
		piece = piece->next;
	else
		piece = first;
	/**********************************************
	while (piece->previous)
	{
			if (deplacerpiece(piece, carre) == 1)
			{
				try++;
				break ;
			}
			while (piece->previous && piece->put == 0)
				piece = piece->previous;
	}
	*******************************************************/
	if (try == nbpiece * nbpiece * nbpiece)
	{
		printf("\n------\nTRY : %d\n-------\n", try);
		try = 0;
		piece = first;
		while (piece->next)
		{
			/*carre->tab = rmv_tab('A' + piece->index, carre->tab);*/
			piece->put = 0;
			piece = piece->next;
		}
		piece->put = 0;
		carre->size++;
		carre->tab = fill_tab(create_tab(carre), carre->size);
		carre = fill_it(carre, first, first, nbpiece);
		return ;
	}
	carre = fill_it(carre, first, piece, nbpiece);
}

int		deplacerpiece(t_piece *piece, t_carre *carre)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	printf("______\n");
	printf("AVANT DEPLACEMENT\n");
	afficher(carre->tab);
	while (i < carre->size && carre->tab[i][j] != ('A' + piece->index))
	{
		if (j < carre->size)
			j++;
		else
		{
			j = 0;
			i++;
		}
	}
	printf("Carre->size : %d, i : %d, j : %d\n", carre->size, i, j);
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
		printf("Carre->size : %d, i : %d, j : %d\n", carre->size, i, j);
		j = j < carre->size ? j + 1 : 0;
		i = j == 0 ? i + 1 : i;
		printf("Carre->size : %d, i : %d, j : %d\n\n\n", carre->size, i, j);
		if (check_piece(piece, carre, i, j) == 1)
		{
			piece->put = 1;
			printf("Piece moved : %c avec index [%d][%d]\n", piece->index + 'A', i, j);
			afficher(carre->tab);
			return (1);
		}
	}
	return (0);
}

void	movepiece(t_carre *carre, t_piece *piece)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < carre->size)
	{
		while (j < carre->size)
		{
			if (carre->tab[i][j] == 'A' + piece->index)
				break ;
			j++;
		}
		j = 0;
		i++;
	}
	carre->tab = rmv_tab('A', carre->tab);
	if (j < carre->size)
		j++;
	else
	{
		i++;
		j = 0;
	}
	while (i < carre->size)
	{
		while (j < carre->size)
		{
			if (check_piece(piece, carre, j, i) == 1)
				break ;
			j++;
		}
		j = 0;
		i++;
	}
}
