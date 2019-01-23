/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:31:12 by bviollet          #+#    #+#             */
/*   Updated: 2018/11/22 16:05:31 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int nb)
{
	int		i;

	i = ft_strlen((char *)s);
	while ((i != 0) && (s[i] != (char)nb))
		i--;
	if (s[i] == (char)nb)
		return ((char *)s + i);
	return (NULL);
}
