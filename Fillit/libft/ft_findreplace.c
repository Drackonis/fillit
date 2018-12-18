/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findreplace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:36:18 by bviollet          #+#    #+#             */
/*   Updated: 2018/12/08 14:46:45 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_findreplace(char *str, char find, char replace)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == find)
			str[i] = replace;
		i++;
	}
}
