/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:51:43 by bviollet          #+#    #+#             */
/*   Updated: 2019/01/10 15:52:53 by bviollet         ###   ########.fr       */
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
		}
		i++;
	}
	return (str);
}

char	**input(int fd)
{
	int		i;
	char	*str;
	char	*tmp;
	char	**line;

	tmp = NULL;
	if (!(line = (char**)malloc(sizeof(char*) * 130)))
		return (NULL);
	i = 0;
	while ((get_next_line(fd, &str)) == 1)
	{
		tmp = str;
		if (tmp)
		{
			line[i] = ft_strdup(tmp);
			free(tmp);
		}
		else
			line[i] = ft_strdup("\0");
		i++;
	}
	if (!line[0])
	{
		free(line);
		return (NULL);
	}
	line[i] = NULL;
	return (input2(line));
}
/*char	**delblank(char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i][0] == '\0')
	{
		tmp = str[i];
		i++;
		str = &str[i];
		free(tmp);
	}
	return (str);
}*/
