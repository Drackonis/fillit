#ifndef FILLIT_H

#define FILLIT_H

#include "libft/libft.h"
#include <stdio.h> /* A SUPPRE */
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_carre
{
	int		size;
	char	**tab;
}				t_carre;

typedef struct	s_pos
{
	int		x;
	int		y;
}				t_pos;

typedef struct	s_piece
{
	int			index;
	int			put;
	char		**ptr;
	t_pos		ij;
	struct s_piece	*next;
	struct s_piece		*previous;
}				t_piece;

typedef struct	s_chain
{
	int			nbpiece;
	struct s_piece		*first;
}				t_chain;

char			findlastpiece(t_carre *carre);
int			deplacerpiece(t_piece *piece, t_carre *carre);
char			**fin(t_carre *carre, t_piece *piece, int i, int j);
int				nbpieceposee(t_piece *first);
void			movepiecea(t_carre *carre, t_piece *piece);
void			again(int nbpiece, t_piece *first, t_carre *carre);
void			fillprevious(t_chain *list);
t_carre			*fill_it(t_carre *carre, t_piece *first, t_piece *start, int nbpiece);
void			movep(char **str, int i, int j, int *tab);
int				*movediff(char **str, int i, int j, int nbpiece);
void			movepieces(char **str, int i, int j, int nbpiece);
int				movepieces2(int *nbpiece);
int				nbpieces(char **str);
int				afficherlinkedlist(t_chain *list);
void			afficher(char **str);
char			**input(int fd);
char			**input2(char **str);
int				error(char **str);
int				ft_error2(int *i, int *ii, int *j, char **str);
int				sharpvalid(char **str, int tab[2], int k, char dir);
int				ft_numberline(char **str);
char			**createpieces(char **str, int index);
t_piece			*createelem(char **str, int index);
t_chain			*createlist(char **str);
int				taillepiece(char **ptr, char c);
int				main_create_tab(t_piece *first, int nbpiece);
int				ft_sqrt_up(int nb);
int				get_next_line(const int fd, char **line);
int				ft_sqrt_up(int nb);
int				main_create_tab(t_piece *first, int nbpiece);
int			check_piece(t_piece *piece, t_carre *carre, int x, int y);
void		place_piece(t_piece *piece, t_carre *carre, t_pos *pos, int c);
t_pos		*new_pos(int x, int y);
char		**rmv_tab(char c, char **tab);
char		**fill_tab(char **tab, int size);
char		**create_tab(t_carre *carre);
int				main_create_tab(t_piece *first, int nbpiece);

#endif
