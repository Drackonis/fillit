/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:51:43 by bviollet          #+#    #+#             */
/*   Updated: 2019/01/11 15:06:29 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**input2(char **str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != NULL)
	{
		if (*str[i] == '\0')
		{
			free(str[i]);
			str[i] = malloc(sizeof(char) * 5);
			ft_bzero(str[i], 5);
			if (!str[i + 1]) // ICI MODIF POUR SORTIE SI LAST LINE /0
			{
				ft_putstr("error\n");
				exit(-1);
			}
		}
		i++;
	}
	return (str);
}

int		get_line(int fd, char *tmp, char **line)
{
	int		i;
	char	*str;

	i = 0;
	while ((get_next_line(fd, &str)) == 1)
	{
		tmp = str;
		if (ft_strlen(tmp) != 0 && ft_strlen(tmp) != 4) // ICI SI LINE LEN < 4
		{
			ft_putstr("error\n");
			exit(-1);
		}
		if (tmp)
		{
			line[i++] = ft_strdup(tmp);
			free(tmp);
		}
		else
			line[i++] = ft_strdup("\0");
	}
	return (i);
}

char	**input(int fd)
{
	int		i;
	char	*tmp;
	char	**line;

	tmp = NULL;
	if (!(line = (char**)malloc(sizeof(char*) * 130)))
		return (NULL);
	i = get_line(fd, tmp, line);
	if (!line[0])
	{
		free(line);
		return (NULL);
	}
	line[i] = NULL;
	return (input2(line));
}
/*
**char	**delblank(char **str)
**{
**	int		i;
**	char	*tmp;
**
**	i = 0;
**	while (str[i][0] == '\0')
**	{
**		tmp = str[i];
**		i++;
**		str = &str[i];
**		free(tmp);
**	}
**	return (str);
**}
*/
