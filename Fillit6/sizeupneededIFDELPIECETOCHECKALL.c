#include "fillit.h"

#include <stdio.h>
int		sizeupneeded(t_carre *carre, t_piece *piece)	//piece ici == first
{
printf("Entered\n");
	while (piece)
	{
printf("OK\n");
afficher(carre->tab);
		if (forsizedeplacerpiece(piece, carre))
			return (0);
afficher(carre->tab);
		piece = piece->next;
	}
	return (1);
}

int		forsizedeplacerpiece(t_piece *piece, t_carre *carre)
{
	int	i;
	int	j;
	int	ii;
	int	jj;

	i = 0;
	j = 0;
	while (i < carre->size && carre->tab[i][j] != ('A' + piece->index))
	{
		j += j < carre->size ? 1 : -j;
		i += j == 0 ? 1 : 0;
	}
	jj = realj(piece, j);
	ii = i;
	i = 0;
	j = 0;
printf("Piece : %c, i : %d, j : %d\n", (char)piece->index + 65, ii, jj);
	//carre->tab = rmv_tab('A' + piece->index, carre->tab);
	//piece->put = 0;
	while (i < carre->size)
	{
		j = j < carre->size ? j + 1 : 0;
		i = j == 0 ? i + 1 : i;
printf("Piece : %c, i : %d, j : %d\n", (char)piece->index + 65, ii, jj);
	carre->tab = rmv_tab('A' + piece->index, carre->tab);
		if ((i != ii || j != jj) && forsizecheck_piece(piece, carre, i, j))
		{
			//piece->put = 1;
			check_piece(piece, carre, ii, jj);
			return (1);
		}
	}
	check_piece(piece, carre, ii, jj);
	return (0); // la piece ne peut pas etre deplace
}

int			forsizecheck_piece(t_piece *piece, t_carre *carre, int x, int y)
{
	int		i;
	int		j;

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
	//place_piece(piece, carre, new_pos(x, y), piece->index);
	return (1); // la piece peut etre posee a l'endroit envoye
}
