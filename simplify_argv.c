
#include "fillit.h"
#define MAX_LINE 26 

char	**simplify_argv(char **argv)
{
	int	x;
	int	y;
	int	z;
	char	**tab;

	x = 0;
	printf ("BEGIN\n");
	if(!(tab = (char**)malloc(sizeof(char*) * MAX_LINE + 1)))
		return (NULL);
	while (x < MAX_LINE)
	{
		if(!(tab[x] = (char*)malloc(sizeof(char*) * 21)))
			return (NULL);
		tab[x][21] = '\0';
		x++;
	}
	tab[x] = NULL;
	x = 0;
	y = 0;
	z = 0;
	printf ("MALLOC OK\n");
	while (argv[1][z])
	{
		printf ("| X : %d | y : %d | z : %d |\n", x, y, z);
		//printf ("argv |%c|\n", argv[1][z]);
		//printf ("tab|%c|\n", tab[y][x]);
		tab[y][x] = argv[1][z];
		printf ("argv |%c| in tab|%c|\n", argv[1][z], tab[y][x]);
		x++;
		z++;
		if (z % 5 == 0)
		{
			tab[y][x] = ' ';
		}
		if (z % 21 == 0)
		{
			printf ("\n TAB : |%s|\n", tab[y]);
			printf ("-----change line-----\n");
			tab[y][x] = '\0';
			x = 0;
			y++;
		}

	}
	return (tab);
}
