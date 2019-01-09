/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:10:17 by rkergast          #+#    #+#             */
/*   Updated: 2019/01/09 16:38:57 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int			nbpieces(char **str)
{
	int		i;
	int		j;

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

void		free_str(char **str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i])
			free(str[i++]);
		free(str);
	}
}

char		**check_error(int argc, char **argv, int *fd, char *file)
{
	char	**str;

	if ((argc != 2) && ((argc != 3) || (ft_strcmp(argv[1], "-v") != 0)))
	{
		ft_putstr("usage: fillit [-v : show pieces] file\n");
		return (NULL);
	}
	if ((argc == 3) && (ft_strcmp(argv[2], "-v")))
		file = argv[2];
	else
		file = argv[1];
	if (!(*fd = open(file, O_RDONLY)))
		return (NULL);
	str = input(*fd);
	if (!str || error(str) == 0)
	{
		printf("error\n");
		free_str(str);
		return (NULL);
	}
	else
		printf("Valid\n");
	if ((argc == 3) && (ft_strcmp(argv[1], "-v") == 0))
		afficher(str);
	return (str);
}

void		free_linked_list(t_chain *chain)
{
	t_piece		*piece;
	t_piece		*tmp;
	int			i;

	i = 0;
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
}

int			main(int argc, char **argv)
{
	char	**str;
	int		fd;
	char	*file;
	t_chain	*chain;

	file = NULL;
	if ((str = check_error(argc, argv, &fd, file)) == NULL)
	{
		printf("coucou\n");
		free_str(str);
		close(fd);
		return (0);
	}
	printf("Nb pieces : %d\n", nbpieces(str));
	afficher(str);
	movepieces(str, 0, -1, 0);
	afficher(str);
	chain = createlist(str);
	if ((argc == 3) && (ft_strcmp(argv[1], "-v") == 0))
		afficherlinkedlist(chain);
	main_create_tab(chain->first, nbpieces(str));
	free_linked_list(chain);
	free_str(str);
	close(fd);
	return (0);
}
