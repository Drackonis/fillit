#include <stdio.h>
#include "fillit.h"

int	nbpieces(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (str[i] != NULL)
	{
		if (str[i][0] == '\0' && str[i + 1] != NULL)
			j++;
		i++;
	}
	return (j);
}

int	main(int argc, char **argv)
{
	char	**str;
	int		fd;
	int		i;
	char	*file;
	t_chain	*chain;
	t_piece	*piece;
	t_piece	*tmp;

	if ((argc != 2) && ((argc != 3) || (ft_strcmp(argv[1], "-v") != 0)))
	{
		ft_putstr("usage: fillit [-v : show pieces] file\n");
		return (0);
	}
	if ((argc == 3) && (ft_strcmp(argv[2], "-v")))
		file = argv[2];
	else
		file = argv[1];
	if (!(fd = open(file, O_RDONLY)))
		return (0);
	str = input(fd);

	if (error(str) == 0)
	{
		printf("error\n");
		return (0);
	}
	else
		printf("Valid\n");

	if ((argc == 3) && (ft_strcmp(argv[1], "-v") == 0))
		afficher(str);
	printf("Nb pieces : %d\n", i = nbpieces(str));
	
	movepieces(str, 0, 0, 0);
	afficher(str);

	chain = createlist(str);

	if ((argc == 3) && (ft_strcmp(argv[1], "-v") == 0))
		afficherlinkedlist(chain);

	main_create_tab(chain->first, nbpieces(str));

/*	 FREE LINKED LIST */
	piece = chain->first;
	free(chain);
	while (piece != NULL)
	{
		i = 0;
		tmp = piece;
		piece = piece->next;
		while (i < 4)
		{
			free(tmp->ptr[i]);
			i++;
		}
		free(tmp->ptr);
		free(tmp);
	}

/*	 FREE STR */
	i = 0;
	while (str[i] != NULL)
		free(str[i++]);
	free(str);

	close(fd);
	return (0);
}
