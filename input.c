/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 18:51:43 by bviollet          #+#    #+#             */
/*   Updated: 2018/12/14 16:52:05 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

char	**input2(char **str)
{
	int		i;

	i = 0;
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
	if (!(line = malloc(sizeof(char) * 600)))
		return (NULL);
	i = 0;
	while (get_next_line(fd, &str) == 1)
	{
		tmp = str;
		if (tmp)
		{
			line[i] = ft_strdup(tmp);
			free(tmp);
		}
		i++;
	}
	line[i] = NULL;
	return (input2(line));
	//return (delblank(input2(line)));
}
