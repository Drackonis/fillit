#include "fillit.h"
char	**g_tab = NULL;

void	createtable()
{
	char	**newtab;
	int		i;
	int		j;
/* cree une tab plus grande, copie l'ancienne dans la nvlle et free l'ancienne */
	if (g_tab == NULL)
		size == 2;
	else
		size = ft_strlen(*g_tab
	newtab = ft_memalloc(size + 1);
	newtab[size] = NULL;
	while (newtab[k] != NULL)
	{
		newtab[k] = ft_memalloc(size + 1);
		ft_bzero(newtab[k], 		size == 2;
				else
				size = ft_strlen(*g_ta		size == 2;
					else
					size = ft_strlen(*g_ta		size == 2;
						else
						size = ft_strlen(*g_ta		size == 2;
							else
							size = ft_strlen(*g_ta		size == 2;
								else
								size = ft_strlen(*g_tabbbbbsize);
		k++;
	}
	i = 0;
	j = 0;
	while (g_tab[i] != NULL)
	{
		ft_strcpy(newtab[i], g_tab[i]);
		i++;
		if (g_tab[i] != NULL)
			free(tab[i]);
	}
	if (g_tab != NULL)
		free(g_tab);
	return (newtab);
}

int		isthereroom(char **str, int i, int j, int mode) // mode check ou write
{
	int	k;
	int	itab;
	int	jtab;

	k = 0;
	itab = 0;
	jtab = 0;
	if (g_tab == NULL)
		createtable();
	while ((ft_isalpha(g_tab[i][j]) == 0) && (str[i][j] == '#')) //??
	{
		j++;
		if ((g_tab[i][j] == '\0') || (str[i][j] == '\0'))
		{	
			i++;
			j = 0;
		}
		if ((ft_isalpha(g_tab[i][j]) == 0) && (str[i][j] == '#'))
		{	
			k++;
			if (mode == 1)
				g_tab[i][j] == 
		}
		if (k > 3)


		if ((g_tab null || str[i][0] == '\0'))
	}


	while (str[i] != NULL)
	{
		while (str[i][j] != '\0')
			j++;
		if (str[i][j] == '#')
			k++;
		i++;
		j = 0;
	}

}

int		print(char **str, int i, int j)
{
	static char	**tab;
	static int 	nbpiece;
	static int	size;
	int			k;

	nbpiece = 65;
	k = 0;
	size = 2;
	if (!tab)
		tab = createtable(size, NULL);

}

int		resolution(char **str, int totalpiece)
{
	int		i;
	int		j;
	int		nbpiece; // ou juste i car si i > 4 et <8 = 2e piece etc...
	char	*ptr;

	i = 0;
	j = 0;
	while (str[i] != NULL)
	{
		while (str[i][j] != '\0')
		{
			if (str[i][j] == '#')
			{
				if (str[i + 1][j - 2] == '#')
					ptr = &str[i][j - 2];
				else if (str[i + 1][j - 1] == '#')
					ptr = &str[i][j - 1];
				else
					ptr = &str[i][j];
				if (isthereroom(ptr, i, j) == 1); // need meme algo
				{
					print(ptr, i, j); //need meme algo pour retrouver same position
					i = (i - (i % 5)) + 4; // i positionne sur la prochaine piece (5, 10, 15
				}
				else
					i = (i - (i % 5)) - 6; // reset la piece d'avant en decrementant i
				j = 3; // pour que la prochaine str[i][j] == '\0'
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

/*void	sharpvalid(char **str, int tab[2], int k, char dir) // 25 l 
{
	if (!(print(str, tab[0], tab[1], nbpieces(str))))
		return (0);
	if (k <= 3 && tab[1] < 4 && dir != 'g' && str[tab[0]][tab[1] + 1] == '#')
	{
		tab[1] = tab[1] + 1;
		return (sharpvalid(str, tab, k + 1, 'd'));
	}
	if (k <= 3 && tab[1] > 0 && dir != 'd' && str[tab[0]][tab[1] - 1] == '#')
	{
		tab[1] = tab[1] - 1;
		return (sharpvalid(str, tab, k + 1, 'g'));
	}
	if (k <= 3 && tab[0] > 0 && dir != 'h' && str[tab[0] - 1][tab[1]] == '#')
	{
		tab[0] = tab[0] - 1;
		return (sharpvalid(str, tab, k + 1, 'b'));
	}
	if (k <= 3 && dir != 'b' && str[tab[0] + 1][tab[1]] == '#')
	{
		tab[0] = tab[0] + 1;
		return (sharpvalid(str, tab, k + 1, 'h'));
	}
	if (dir == 'd')
		return (sharpvalid(str, tab, k, 'g'));
	return (1); // si on return 1, tous les emplacement sont valide
}*/

