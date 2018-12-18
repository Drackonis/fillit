/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:33:08 by bviollet          #+#    #+#             */
/*   Updated: 2018/11/14 17:47:51 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, int nb)
{
	int i;

	i = 0;
	while ((src[i] != '\0') && (i < nb))
	{
		dest[i] = src[i];
		i++;
	}
	while (i < nb)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
