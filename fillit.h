#ifndef FILLIT_H

#define FILLIT_H

#include "libft/libft.h"
#include <stdio.h> /* A SUPPRE */ 
typedef struct s_carre
{
	int		size;
	char	*tab;
}				t_carre;

typedef struct	s_pos
{
	int		x;
	int		y;
}				t_pos;

typedef struct	s_piece
{
	int			index;
	char		**ptr;
	t_pos		ij;
	struct s_piece	*next;
	//struct s_piece		*previous;
}				t_piece;

typedef struct	s_chain
{
	int			nbpiece;
	struct s_piece		*first;
}				t_chain;

void	movep(char **str, int i, int j, int *tab);
int		*movediff(char **str, int i, int j, int nbpiece);
void	movepieces(char **str, int i, int j, int nbpiece);
int		movepieces2(int *nbpiece);
int		nbpieces(char **str);
int		afficherlinkedlist(t_chain *list);
int		afficher(char **str);
char	**input(int fd);
char	**input2(char **str);
int		error(char **str);
int		ft_error2(int *i, int *ii, int *j, char **str);
int		sharpvalid(char **str, int tab[2], int k, char dir);
int		ft_numberline(char **str);
char	**createpieces(char **str, int index);
t_piece	*createelem(char **str, int index);
t_chain	*createlist(char **str);
int		taillepiece(char **ptr, char c);


#endif
