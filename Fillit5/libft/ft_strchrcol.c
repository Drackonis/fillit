/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrcol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:03:21 by rkergast          #+#    #+#             */
/*   Updated: 2019/01/25 15:44:36 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
char	ft_strchrcol(char **str, int i, int j, char find)
{
	while (str[i])
	{
		//printf("Strchrcol = i : %dm j : %d\n", i, j);
		if (str[i][j] && str[i][j] == find)
		{
			printf("Return1, Str[%d][%d] : %c\n", i, j, str[i][j]);
			return (1);
		}
		i++;
	}
	printf("return0\n");
	return (0);
}
