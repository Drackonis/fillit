/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:30:54 by bviollet          #+#    #+#             */
/*   Updated: 2018/11/15 14:35:27 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	unsigned int		i;
	char				*str;

	if ((s != NULL) && ((int)len >= 0))
	{
		i = 0;
		if ((str = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		while (len > 0)
		{
			str[i] = s[start];
			i++;
			start++;
			len--;
		}
		str[i] = '\0';
		return (str);
	}
	return (0);
}
