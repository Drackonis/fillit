/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:31:55 by bviollet          #+#    #+#             */
/*   Updated: 2018/11/15 12:56:02 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int nb)
{
	int	i;

	i = 0;
	while ((s[i] != (char)nb) && (s[i] != 0))
		i++;
	if ((s[i] == 0) && (s[i] != (char)nb))
		return (NULL);
	else if (s[i] == (char)nb)
		return ((char *)s + i);
	return ((char *)&s[i]);
}
