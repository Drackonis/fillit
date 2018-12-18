/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bviollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:53:30 by bviollet          #+#    #+#             */
/*   Updated: 2018/11/21 20:20:11 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*positive(int n, char *nb, char *nb2)
{
	int		i;
	int		j;

	i = 0;
	while (n > 0)
	{
		nb[i] = (n % 10) + 48;
		n = n / 10;
		i++;
	}
	nb[i] = '\0';
	i = 0;
	j = ft_strlen(nb) - 1;
	while (j >= 0)
	{
		nb2[i] = nb[j];
		i++;
		j--;
	}
	nb2[i] = '\0';
	return (nb2);
}

static char		*negative(int n, char *nb, char *nb2)
{
	int		i;
	int		j;

	i = 0;
	n = n * -1;
	while (n)
	{
		nb[i] = n % 10 + 48;
		n = n / 10;
		i++;
	}
	nb[i++] = '-';
	nb[i++] = 0;
	i = 0;
	j = ft_strlen(nb);
	while (j >= 0)
	{
		nb2[i] = nb[--j];
		i++;
	}
	nb2[i] = '\0';
	return (nb2);
}

static int		nbdigits(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*nb;
	char	*nb2;

	if ((nb = (char *)malloc(sizeof(char) * (nbdigits(n) + 1))) == NULL)
		return (NULL);
	if ((nb2 = (char *)malloc(sizeof(char) * (nbdigits(n) + 1))) == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n >= 0 && n < 10)
	{
		nb[0] = n + '0';
		nb[1] = '\0';
		return (nb);
	}
	if (n > 9)
		return (positive(n, nb, nb2));
	if (n < 0)
		return (negative(n, nb, nb2));
	return (NULL);
}
