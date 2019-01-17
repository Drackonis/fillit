/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:55:57 by bviollet          #+#    #+#             */
/*   Updated: 2018/11/22 16:04:19 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (((int *)dst < (int *)src) && ((int *)src + len > (int *)dst))
		ft_memcpy(dst, src, len);
	else
	{
		i = len;
		while (i > 0)
		{
			i--;
			*((char*)dst + i) = *((char *)src + i);
		}
	}
	return (dst);
}
