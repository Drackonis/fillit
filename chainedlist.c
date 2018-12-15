#include "fillit.h"

int		taillepiece(char **ptr, char c)
{
	int	i;
	int	j;
	int	tab[2];

	i = 0;
	j = 0;
	tab[0] = 0;
	tab[1] = 0;
	if (!(ptr && *ptr))
		return (0);
	while (i < 4)
	{
		while (j < 4)
		{
			if (ptr[i][j] == '#')
			{
				if (tab[0] < i)
					tab[0] = i;
				if (tab[1] < j)
					tab[1] = j;
			}
			j++;
		}
		i++;
		j = 0;
	}
	if (c == 'i')
		return (tab[0]);
	else
		return (tab[1]);
}

t_chain	*createlist(char **str)
{
	t_chain	*list;
	t_piece *piece;
	int		index;

	index = 0;
	if (!(list = (t_chain*)malloc(sizeof(*list))))
		return (NULL);
	list->nbpiece = nbpieces(str);
	list->first = createelem(str, index);
	piece = list->first;
	while (index + 1 < list->nbpiece)
	{
		index++;
		piece->next = createelem(str, index);
		piece = piece->next;
	}
	piece->next = NULL;
	return (list);
}

t_piece	*createelem(char **str, int index)
{
	t_piece	*piece;

	if (!(piece = (t_piece*)malloc(sizeof(*piece))))
		return (NULL);
	piece->index = index;
	piece->ptr = createpieces(str, index);
	if (piece)
	{
		piece->ij.x = taillepiece(piece->ptr, 'i');
		piece->ij.y = taillepiece(piece->ptr, 'j');
	}
	return (piece);
}

char	**createpieces(char **str, int index)
{
	char	**ptr;
	int		i;
	int		k;

	k = 0;
	i = 0;
	if (!(ptr = (char**)malloc(sizeof(char*) * 5)))
		return (NULL);
	while (i < 4)
	{
		k = i + (index * 5);
		//printf("index : %d\n", index);
			ft_putstr("\nSTR[k] : \n");
			ft_putstr(str[k]);
			ptr[i] = ft_strdup(str[k]);
		i++;
	}
	ptr[i] = NULL;
	afficher(ptr);
	return (ptr);
}
