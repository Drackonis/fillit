/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:15:10 by bviollet          #+#    #+#             */
/*   Updated: 2018/11/14 17:06:53 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int nb, size_t len)
{
	char	*ptrchar;
	size_t	i;

	ptrchar = ptr;
	i = 0;
	while (i < len)
	{
		*(ptrchar + i) = nb;
		i++;
	}
	return (ptrchar);
}
