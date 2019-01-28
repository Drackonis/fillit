/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:31:20 by bviollet          #+#    #+#             */
/*   Updated: 2018/11/21 20:28:52 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if ((s1 != NULL) && (s2 != NULL))
	{
		while (s1[i] != '\0')
			i++;
		while (s2[j] != '\0')
			j++;
		if ((str = malloc(sizeof(char) * (i + j + 1))) == NULL)
			return (NULL);
		i = 0;
		j = 0;
		while (s1[j] != '\0')
			str[i++] = s1[j++];
		j = 0;
		while (s2[j] != '\0')
			str[i++] = s2[j++];
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
