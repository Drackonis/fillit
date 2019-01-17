#include "fillit.h"

t_carre		*onepiece(t_carre *carre, t_piece *piece)
{
	if (piece->ij.x == 1 && piece->ij.y == 1)
	{	
		check_piece(piece, carre, 0, 0);
		piece->put = 1;
		return (carre);
	}
	else if (piece->ij.x < 3 && piece->ij.y < 3)
		carre->size++;
	else
		carre->size += 2;
	carre->tab = fill_tab(create_tab(carre, 0), carre->size);
	check_piece(piece, carre, 0, 0);
	piece->put = 1;
	return (carre);
}
