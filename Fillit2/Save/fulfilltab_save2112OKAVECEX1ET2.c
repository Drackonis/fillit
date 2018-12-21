/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:31:42 by rkergast          #+#    #+#             */
/*   Updated: 2018/12/21 16:49:23 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			nbpieceposee(t_piece *first)
{
	int	final;
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

void	place_piece(t_piece *piece, t_carre *carre, t_pos *pos, int c) /* pos.x = i, pos.y = j */
{
	int	i;
	int	j;

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
}

int	check_piece(t_piece *piece, t_carre *carre, int x, int y) /* x = tab[i] | y = tab[x][j] */
{
	int	i;
	int	j;
	
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

t_carre		*fill_it(t_carre *carre, t_piece *first, t_piece *start, int nbpiece)
{
	int		i;
	int		j;
	int		t;
	int		k;
	t_piece		*piece;

	piece = start;
	t = 0;
	k = 0;

	while (k <= nbpiece * 2)
	{
		printf("Nbpieceposee : %d\n", nbpieceposee(first));
		i = 0;
		while (piece->put == 0 && i < carre->size)
		{
			j = 0;
			while (j < carre->size)
			{
				if (piece->put == 0 && check_piece(piece, carre, i, j) == 1)
				{
					printf("Piece place : %c et k : %d\n", 'A' + piece->index, k);
					afficher(carre->tab);
					//getchar();
					piece->put = 1;
					j = -1;
					i = 0;
					if (nbpiece == nbpieceposee(first))
						return (carre);
				}
				j++;
			}
			i++;
		}
		if (piece->next)
			piece = piece->next;
		else
			piece = first;
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

	piece = first;
	
	if (nbrm < nbpiece)
		nbrm++;
	else
	{
		nbrm = 0;
		start++;
	}
	if (start < nbpiece)
		start++;
	else
	{
		start = 0;
		try++;
	}
	cpt = nbrm < nbpieceposee(first) ? nbrm : nbpieceposee(first);
printf("ENTREE CPT\n");
	while (cpt-- >= 0)
	{
		printf("Cpt : %d\n", cpt);
		while (piece->next)
			piece = piece->next;
		while (piece->previous && piece->put == 0)
			piece = piece->previous;
		if (piece->put == 1 /*&& cpt == 0*/)
		{
			deplacerpiece(piece, carre);
			printf("Piece deplace : %c\n", 'A' + piece->index);
		}
		/*else if (piece->put == 1)
		{
			rmv_tab('A' + piece->index, carre->tab);
			piece->put = 0;
			printf("Piece removed : %c\n", 'A' + piece->index);
		}*/
	}
printf("SORTIE CPT\n");
		/* si rm piece A au lieu de rm on deplace */
printf("Try : %d\n", try);
	if (try == nbpiece)
	{
		carre->tab = fill_tab(create_tab(carre), carre->size);
		try = 0;
		while (piece->next)
		{
			/*carre->tab = rmv_tab('A' + piece->index, carre->tab);*/
			piece->put = 0;
			piece = piece->next;
		}
		piece->put = 0;
	}

	cpt = start;
	piece = first;
	while (piece->next && piece->put == 1)
		piece = piece->next;
	carre = fill_it(carre, first, piece->next, nbpiece);
}

void		deplacerpiece(t_piece *piece, t_carre *carre)
{
	int	i;
	int	j;

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
	if (i > 0 && j > 0 && carre->tab[i - 1][j - 1] == 'A' + piece->index)
		j--;
	else if (i > 1 && j > 0 && carre->tab[i - 2][j - 1] == 'A' + piece->index)
		j--;
	else if (i > 0 && j > 1 && carre->tab[i - 1][j - 2] == 'A' + piece->index)
		j = j - 2;
	carre->tab = rmv_tab('A' + piece->index, carre->tab);
	piece->put = 0;
	while (i < carre->size)
	{
		j  = j < carre->size ? j + 1 : 0;
		i = j == 0 ? i + 1 : i;
		if (check_piece(piece, carre, i, j) == 1)
		{
			piece->put = 1;
	printf("APRES DEPLACEMENT\n");
	afficher(carre->tab);
			return ;
		}
	}
}

void		movepiece(t_carre *carre, t_piece *piece)
{
	int	i;
	int	j;

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
