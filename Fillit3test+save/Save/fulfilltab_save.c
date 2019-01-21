/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:31:42 by rkergast          #+#    #+#             */
/*   Updated: 2018/12/20 16:39:02 by bviollet         ###   ########.fr       */
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

	k = 0;
	t = 0;

while (nbpiece != nbpieceposee(first))
{
	piece = start;
	k = 0;
	if (k < nbpiece + 1)
	{
		printf("Nbpieceposee : %d\n", nbpieceposee(first));
		printf("Current piece : %c put%d, J : %d & I : %d\n", 'A' + piece->index, piece->put, j, i);
		i = 0;
		while (piece->put == 0 && i < carre->size)
		{
			j = 0;
			while (piece->put == 0 && j < carre->size)
			{
				if (check_piece(piece, carre, i, j) == 1)
				{
					afficher(carre->tab);
					getchar();
					piece->put = 1;
					printf("Piece place : %c et k : %d\n", 'A' + piece->index, k);
					if (piece->next)
						piece = piece->next;
					else
						piece = first;
					j = -1;
					i = 0;
					if (nbpiece == nbpieceposee(first))
						return (carre);
				}
				j++;
			}
			i++;
		}
		k++;
		if (piece->next)
			piece = piece->next;
		else
			piece = first;
	}
printf("BUG\n");
printf("Current piece : %c put%d, J : %d & I : %d\n", 'A' + piece->index, piece->put, j, i);

	afficher(carre->tab);

	/* RM derniere piece*/
	while (piece->next)
		piece = piece->next;
	while (piece->previous && piece->put == 0)
		piece = piece->previous;
	if (piece->put == 1)
	{
		printf("Piece removed : %c\n", 'A' + piece->index);
		carre->tab = rmv_tab('A' + piece->index, carre->tab);
		piece->put = 0;
	}

	while (piece->previous && piece->put == 0)
		piece = piece->previous;
	if (piece->put == 1)
	{
		printf("Piece deplace : %c\n", 'A' + piece->index);
		deplacerpiece(piece, carre);
	}

	start = piece->next;

/*	if (k++ > 50)
	{
		piece = first;
		while (piece->next)
		{
			carre->tab = rmv_tab('A' + piece->index, carre->tab);
			piece->put = 0;
			piece = piece->next;
		}
		carre->tab = fill_tab(create_tab(carre), carre->size);
		printf("Augment size tab : %d\n", carre->size);
		k = 0;
	}*/
	//piece = first;	
}

	return (carre);
}

void		deplacerpiece(t_piece *piece, t_carre *carre)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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
