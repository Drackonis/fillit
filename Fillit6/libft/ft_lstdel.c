/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:40:35 by bviollet          #+#    #+#             */
/*   Updated: 2018/11/21 21:04:54 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*elem;
	t_list	*next;

	elem = *alst;
	while (elem != NULL)
	{
		next = elem->next;
		del(elem->content, elem->content_size);
		free(elem);
		elem = next;
	}
	*alst = NULL;
}
