/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:41:34 by bviollet          #+#    #+#             */
/*   Updated: 2019/01/23 14:33:45 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nextline(char **str, char **line, int fd, int nbbytes)
{
	char	*tmp;
	int		len;

	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
	{
		*line = ft_strsub(str[fd], 0, len);
		tmp = ft_strdup(str[fd] + len + 1);
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][len] == '\0')
	{
		if (nbbytes == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[200];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			nbbytes;

	if ((fd < 0) || (!line))
		return (-1);
	while ((nbbytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[nbbytes] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(1);
		tmp = str[fd];
		str[fd] = ft_strjoin(tmp, buf);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (nbbytes < 0)
		return (-1);
	else if ((nbbytes == 0) && ((str[fd] == NULL) || (str[fd][0] == '\0')))
		return (0);
	return (ft_nextline(str, line, fd, nbbytes));
}
