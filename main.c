
#include "fillit.h"

int	main(int argc, char **argv)
{
	int i;
	int nb;
	char	**tab;

	i = 0;
	argc++;
	tab = simplify_argv(argv, &nb);
	while (i < 3)
	{
		printf("LINE %d : %s", i, tab[i]);
		getchar();
		i++;
	}
	printf ("NB = %d\n", nb);
	printf ("END\n");
	return (1);
}
