/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:31:55 by bviollet          #+#    #+#             */
/*   Updated: 2019/01/12 15:18:25 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int nb)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while ((s[i] != (char)nb) && (s[i] != 0))
		i++;
	if ((s[i] == 0) && (s[i] != (char)nb))
		return (NULL);
	else if (s[i] == (char)nb)
		return ((char *)s + i);
	return ((char *)&s[i]);
}
