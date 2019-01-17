/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:34:59 by rkergast          #+#    #+#             */
/*   Updated: 2019/01/11 14:01:09 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			afficherlinkedlist(t_chain *list)
{
	t_piece	*piece;
	int		i;

	piece = list->first;
	while (piece)
	{
		i = 0;
		while (i < 4)
		{
			ft_putstr(piece->ptr[i]);
			ft_putchar('\n');
			i++;
		}
		piece = piece->next;
	}
	return (0);
}

void		afficher(char **str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str != NULL)
	{
		while (str[i] != NULL)
		{
			while (str[i][j] != '\0')
			{
				ft_putchar(str[i][j]);
				j++;
			}
			ft_putchar('\n');
			i++;
			j = 0;
		}
	}
}
