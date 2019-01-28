/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onepiece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:55:18 by rkergast          #+#    #+#             */
/*   Updated: 2019/01/21 13:56:13 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		realj(t_piece *piece, int j)
{
	char	**str;
	int		i;
	int		decalej;
	int		j2;

	i = 0;
	j2 = 0;
	decalej = 0;
	str = piece->ptr;
	while (str[i][j2++] == '.')
		decalej++;
	if (j - decalej >= 0)
		return (j - decalej);
	return (j);
}
