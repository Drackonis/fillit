
#include "fillit.h"

int	main(int argc, char **argv)
{
	int i;
	char	**tab;

	i = 0;
	argc++;
	tab = simplify_argv(argv);
	while (i < 3)
	{
		printf("LINE %d : %s", i, tab[i]);
		getchar();
		i++;
	}
	return (1);
}
