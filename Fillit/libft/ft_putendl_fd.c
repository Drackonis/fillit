/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:34:56 by bviollet          #+#    #+#             */
/*   Updated: 2018/11/21 19:58:02 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(const char *str, int fd)
{
	int		i;
	char	c;

	c = '\n';
	i = 0;
	if (str != NULL)
	{
		while (str[i] != '\0')
			i++;
		write(fd, str, i);
		write(fd, &c, 1);
	}
}
