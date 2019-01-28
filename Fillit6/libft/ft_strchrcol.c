/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrcol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:03:21 by rkergast          #+#    #+#             */
/*   Updated: 2019/01/26 14:25:29 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_strchrcol(char **str, int i, int j, char find)
{
	while (str[i])
	{
		if (str[i][j] && str[i][j] == find)
			return (1);
		i++;
	}
	return (0);
}
