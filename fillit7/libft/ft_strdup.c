/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:35:50 by bviollet          #+#    #+#             */
/*   Updated: 2018/12/14 16:47:22 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	int		size;

	size = 0;
	while (s && s[size])
		size++;
	if ((res = (char*)malloc(sizeof(char) * size + 1)) == NULL)
		return (0);
	size = 0;
	while (s && *(s + size) != '\0')
	{
		*(res + size) = *(s + size);
		size++;
	}
	*(res + size) = '\0';
	return (res);
}
