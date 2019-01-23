/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chainedlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:43:07 by rkergast          #+#    #+#             */
/*   Updated: 2019/01/10 13:53:31 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		taillepiece(char **ptr, char c)
{
	t_pos	*tab0;
	t_pos	*tab1;
	int		i;

	if (!(ptr && *ptr))
		return (0);
	tab0 = new_pos(0, 0);
	tab1 = new_pos(0, 0);
	while (tab0->x < 4)
	{
		while (tab0->y < 4)
		{
			taille(tab0, tab1, ptr);
			tab0->y++;
		}
		tab0->x++;
		tab0->y = 0;
	}
	free(tab0);
	i = c == 'i' ? tab1->x : tab1->y;
	free(tab1);
	return (i);
}

t_chain	*createlist(char **str)
{
	t_chain	*list;
	t_piece *piece;
	int		index;

	index = 0;
	if (!(list = (t_chain*)malloc(sizeof(*list))))
		return (NULL);
	list->nbpiece = nbpieces(str);
	list->first = createelem(str, index);
	piece = list->first;
	while (index + 1 < list->nbpiece)
	{
		index++;
		piece->next = createelem(str, index);
		piece = piece->next;
	}
	piece->next = NULL;
	fillprevious(list);
	return (list);
}

t_piece	*createelem(char **str, int index)
{
	t_piece	*piece;

	if (!(piece = (t_piece*)malloc(sizeof(*piece))))
		return (NULL);
	piece->index = index;
	piece->ptr = createpieces(str, index);
	if (piece)
	{
		piece->ij.x = taillepiece(piece->ptr, 'i');
		piece->ij.y = taillepiece(piece->ptr, 'j');
	}
	return (piece);
}

char	**createpieces(char **str, int index)
{
	char	**ptr;
	int		i;
	int		k;

	k = 0;
	i = 0;
	if (!(ptr = (char**)malloc(sizeof(char*) * 5)))
		return (NULL);
	while (i < 4)
	{
		k = i + (index * 5);
		ptr[i] = ft_strdup(str[k]);
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

void	fillprevious(t_chain *list)
{
	t_piece	*piece;
	t_piece	*previouspiece;

	previouspiece = list->first;
	piece = list->first;
	previouspiece->previous = NULL;
	while (piece->next)
	{
		piece->put = 0;
		piece = piece->next;
		piece->previous = previouspiece;
		if (piece->next)
			previouspiece = piece;
	}
	piece->put = 0;
	piece->previous = previouspiece;
}
