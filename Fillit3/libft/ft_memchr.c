/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:34:33 by bviollet          #+#    #+#             */
/*   Updated: 2018/11/15 19:00:27 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	cc;
	int				i;

	i = 0;
	cc = (unsigned char)c;
	ptr = (unsigned char *)s;
	while (n > 0)
	{
		if (ptr[i] == cc)
			return (ptr + i);
		i++;
		n--;
	}
	return (NULL);
}
