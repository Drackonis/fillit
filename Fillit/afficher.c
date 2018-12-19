/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:54:07 by rkergast          #+#    #+#             */
/*   Updated: 2018/12/19 15:54:41 by rkergast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		afficherlinkedlist(t_chain *list)
{
	t_piece	*piece;
	int		i;

	piece = list->first;
	while (piece)
	{
		printf("\n___________\n");
		i = 0;
		printf("Index : %d\n", piece->index);
		while (i < 4)
		{
			ft_putstr(piece->ptr[i]);
			printf("\n");
			i++;
		}
		printf("IJ j : %d, i : %d\n", piece->ij.y, piece->ij.x);
		piece = piece->next;
	}
	return (0);
}

void	afficher(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_putstr("________\n");
	if (str != NULL)
	{
		while (str[i] != NULL)
		{
			while (str[i][j] != '\0')
			{
				ft_putchar(str[i][j]);
				ft_putchar(' ');
				j++;
			}
			ft_putchar('\n');
			i++;
			j = 0;
		}
	}
	ft_putstr("________\n");
}
