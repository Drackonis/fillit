/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:58:37 by bviollet          #+#    #+#             */
/*   Updated: 2018/11/21 19:00:20 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbword(char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (*s != '\0')
	{
		if ((word == 0) && (*s != c))
		{
			word = 1;
			i++;
		}
		else if ((word == 1) && (*s == c))
			word = 0;
		s++;
	}
	return (i);
}

static int		ft_strlim(char *s, char c)
{
	int	len;

	len = 0;
	while ((*s != c) && (*s != '\0'))
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	int		nbwords;
	char	**tab;
	int		i;

	if (s == NULL)
		return (NULL);
	nbwords = ft_nbword((char *)s, c);
	if ((tab = (char **)malloc((nbwords + 1) * sizeof(char*))) == NULL)
		return (NULL);
	i = 0;
	while (nbwords > 0)
	{
		while ((*s == c) && (*s != '\0'))
			s++;
		tab[i] = ft_strsub((char *)s, 0, ft_strlim((char *)s, c));
		if (tab[i] == '\0')
			return (NULL);
		s = s + ft_strlim((char *)s, c);
		i++;
		nbwords--;
	}
	tab[i] = NULL;
	return (tab);
}
