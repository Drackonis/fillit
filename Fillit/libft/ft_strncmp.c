/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:24:17 by bviollet          #+#    #+#             */
/*   Updated: 2018/11/22 16:05:15 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] == s2[i]) && (i < n) && (s1[i] != '\0') && (s2[i] != '\0'))
		i++;
	if (((s1[i] == '\0') || (s2[i] == '\0')) && (i != n))
	{
		return (*(unsigned char *)(s1 + i) - (*(unsigned char *)(s2 + i)));
	}
	if ((s1[i] != s2[i]) && (i < n))
		return (s1[i] - s2[i]);
	if (i >= n)
		i--;
	return (*(unsigned char *)(s1 + i) - (*(unsigned char *)(s2 + i)));
}
