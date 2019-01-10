/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:31:42 by rkergast          #+#    #+#             */
/*   Updated: 2018/12/19 21:30:36 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**create_tab(t_carre *carre)
{
	int			i;
	char	**tmp;
	
	tmp = carre->tab;
	i = 0;
		if (!(carre->tab = (char**)malloc(sizeof(char*) * (carre->size + 1))))
		return (NULL);
	while (i <= carre->size)
	{
		if (!(carre->tab[i] = (char*)malloc(sizeof(char*) * (carre->size + 1))))
			return (NULL);
		carre->tab[i][carre->size] = '\0';
		i++;
	}
	carre->tab[carre->size] = NULL;
	i = 0;
	if (tmp)
	{
		while (tmp[i])
		{
			free(tmp[i]);
			i++;
		}
		free(tmp);
	}

	return (carre->tab);
}

char		**fill_tab(char **tab, int size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;

	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			tab[i][j] = '.';
			j++;
		}
		i++;
	}
	return (tab);
}

char	**rmv_tab(char c, char **tab)
{
	int		i;
	int		j;

	j = 0;
	if (c < 65 || c > 90)
		return (NULL);
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (tab[j][i] == c)
				tab[j][i] = '.';
			i++;
		}
		j++;
	}
	return (tab);
}

t_pos	*new_pos(int x, int y)
{
	t_pos	*pos;

	pos = ft_memalloc(sizeof(t_pos));
	pos->x = x;
	pos->y = y;
	return (pos);
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

/* a priori, changer le scope pour que piece soit teste sur tous les cases du tab avant de next */
t_carre		*fill_it(t_carre *carre, t_piece *first, t_piece *start, int nbpiece)
{
	int		i;
	int		j;
	int		t;
	int		k;
	t_piece		*piece;

	i = 0;
	t = 0;
	while (i < carre->size)
	{
		j = 0;
	piece = start;
		while (j < carre->size)
		{
			if (carre->tab[i][j]/* == '.'*/)
			{
	afficher(carre->tab);
		//sleep(1);
		//getchar();
				//k = 0;
				/*while (k <= nbpiece)
				{*/
					while (piece->put == 1 /*&& k != nbpiece*/)
					{
						if (!piece->next)
							piece = first;
						else
							piece = piece->next;
						if (nbpieceposee(first) == nbpiece)
							break ;
						//k++;
					}
					printf("Current case : tab[%d][%d]\n", i, j);
					printf("Current pieces : %c with put : %d\n", 'A' + piece->index, piece->put);
					if (piece->put == 0 && (check_piece(piece, carre, i, j)) == 1)
					{
						piece->put = 1;
						printf("Piece posee\n");
						k = 6;
						i = 0;
						j = 0;
						if (piece->next)
						piece = piece->next;
						else
							piece = first;
					}
					/*if (piece->next)
						piece = piece->next;
					else
						piece = first;*/
			/*	}*/
			}
			j++;
		}
		i++;
	}
	/*if (nbpieceposee(first) != nbpiece && first->put == 1)
	{
		printf("OK\n");
		movepiecea(carre, first);
		carre = fill_it(carre, first, piece, nbpiece);
	}*/
	again(nbpiece, first, carre);
	return (carre);
}

/* restart a first si first->put == 0*/

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
	printf("FINAL : %d\n\n", final);
	/*if (final == nbpiece)
		printf("^-> REUSSI :  %d piece sur %d | %d size | %de try\n", final, nbpiece, carre->size);
	else
		printf("^-> ECHEC : %d piece sur %d | %d size | %de try | %de nbrm | %de start\n", final, nbpiece, carre->size, try, nbrm, start);*/
	return (final);
}

char		**fin(t_carre *carre, t_piece *piece, int i, int j)
{
	char	c;
	int		k;

	(void)piece;
	k = 0;
	c = carre->tab[i][j];
	while (j < carre->size && carre->tab[i][j] == c)
	{
		k++;
		j++;
	}
	printf("k : %d", k);
	if (k == 4)
	{
	printf("\n1\n");
		while (i < carre->size)
		{
			while (j < carre->size)
			{
				if (i != 0)
					carre->tab[i - 1][j] = carre->tab[i][j];
				if (i + 1 == carre->size)
					carre->tab[i][j] = c;
				j++;
			}
			j = 0;
			i++;
		}
		i = 0;
		printf("c : %c\n", c);
	}
	return (carre->tab);
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

void		again(int nbpiece, t_piece *first, t_carre *carre)
{
	static int	try = 0;
	t_piece		*piece;
	static int			nbrm = 0;
	static int	start = 0;
	int		cpt;

	cpt = 0;
	piece = first;

	printf("OKKK k :  \n");
	if ((nbpieceposee(first) == nbpiece))
		return ;

	if (try < nbpiece)		/* inversement nbrm et start, pas de chgt..  a rechanger eventuellement */
	{
		if (nbrm < nbpiece)
			nbrm++;
		if (nbrm == nbpiece)
		{
			nbrm = 0;
			start++;
		}
		if (start == nbpiece)
		{
			start = 0;
			try++;
		}
		cpt = nbrm;
		while (cpt-- > 0)
		{
			while (piece->next != NULL)
				piece = piece->next;
			while (piece->previous && piece->put == 0)
					piece = piece->previous;
			printf("\nRM index : %c, avec un put : %d\n", 'A' + piece->index, piece->put);
			printf("CHAR RM :  %c\n", 'A' + piece->index);
			rmv_tab('A' + piece->index, carre->tab);
			piece->put = 0;
			piece = piece->next;
		}
		/*cpt = start;
		piece = first;
		while (cpt-- > 0)	 define start pieces
		{
			if (piece->next)
				piece = piece->next;
			else
				piece = first;
		}*/
		
	}
	else
	{
		try = 0;
		carre->size++;
		carre->tab = fill_tab(create_tab(carre), carre->size);
		piece = first;
		while (piece->next)
		{	
			piece->put = 0;
			piece = piece->next;
		}
		piece->put = 0;
		piece = first;
	}
	carre = fill_it(carre, first, piece, nbpiece);
}

int		main_create_tab(t_piece *first, int nbpiece)
{
	t_carre *carre;
	int		i;

	carre = (t_carre*)malloc(sizeof(carre));
	i = 0;
	carre->size = ft_sqrt_up(nbpiece * 4);
printf("size : %d\n", ft_sqrt_up(nbpiece * 4));
printf("size : %d\n", carre->size);
carre->tab = NULL;
	carre->tab = fill_tab(create_tab(carre), carre->size);
	/*
	carre->tab = create_tab(carre);
	carre->tab = fill_tab(carre->tab);
	*/
	carre = fill_it(carre, first, first,  nbpiece);

	carre->tab = fin(carre, first, 0, 0);
	afficher(carre->tab);
	free(carre);
	return 0;
}

