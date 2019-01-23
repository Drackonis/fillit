/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:24:38 by bviollet          #+#    #+#             */
/*   Updated: 2018/11/21 20:49:19 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((s1[i] != '\0') && (i < (int)size))
	{
		while ((s1[i] != '\0') && (s2[j] != '\0') && (s1[i] == s2[j])
	&& (i < (int)size))
		{
			i++;
			j++;
		}
		if (j == ((int)ft_strlen(s2)))
			return ((char *)s1 + i - j);
		else
			i = (i - j) + 1;
		j = 0;
	}
	return (NULL);
}
