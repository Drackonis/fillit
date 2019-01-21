/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrcol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:03:21 by rkergast          #+#    #+#             */
/*   Updated: 2019/01/21 14:03:24 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_strchrcol(char **str, int i, int j, int find)
{
	while (str[i])
	{
		if (str[i][j] == find)
			return (str[i][j]);
		i++;
	}
	return (0);
}
