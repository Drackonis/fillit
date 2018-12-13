#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
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
	char	**tab;
	int	width;
	int	height;
	char	skin;
}		t_piece;

char	**simplify_argv(char **argv, int *nb);

#endif
