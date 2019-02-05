/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:10:17 by rkergast          #+#    #+#             */
/*   Updated: 2019/01/21 14:50:54 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (j > 26)
	{
		ft_putstr("error");
		exit(-1);
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

	file = argv[1];
	if (!(*fd = open(file, O_RDONLY)))
		return (NULL);
	str = input(*fd);
	if (!str || error(str) == 0 || argc != 2)
	{
		ft_putstr("error\n");
		free_str(str);
		return (NULL);
	}
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

	if (argc != 2)
	{
		ft_putstr("usage: fillit source_file\n");
		return (0);
	}
	file = NULL;
	if ((str = check_error(argc, argv, &fd, file)) == NULL)
	{
		free_str(str);
		close(fd);
		return (0);
	}
	movepieces(str, -1, -1, 0);
	chain = createlist(str);
	main_create_tab(chain->first, nbpieces(str));
	free_linked_list(chain);
	free_str(str);
	close(fd);
	return (0);
}
