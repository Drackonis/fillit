#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_carre
{
	int	size;
	char	**tab;	
}		t_carre;

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct s_piece
{
	int 	index;
	char	**tab;
	t_pos	ij;
	struct s_piece	*next;
}		t_piece;

typedef struct s_chain
{
	int nbpiece;
	struct s_piece	*first;
}		t_chain;

char	**simplify_argv(char **argv, int *nb);

#endif
