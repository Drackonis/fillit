/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkergast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:56:30 by rkergast          #+#    #+#             */
/*   Updated: 2019/01/25 19:26:38 by bviollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		checkaround(char **str, int i, int j, int last)
{
	if (!last && str[i + 1] != NULL && str[i + 1][j] == '#')
		return (1);
	if (!last && j < 3 && str[i][j + 1] == '#')
		return (1);
	if (last && j > 0 && str[i][j - 1] == '#')
		return (1);
	if (last && i > 0 && str[i - 1][j] == '#')
		return (1);
	return (0);

}

int		isconx(char **str, int i, int j)
{
	int	k;
	int	ii;

	ii = 0;
	k = 0;
	while (str[i] && str[i][0])
	{
		if (str[i][j] == '#')
		{
		//printf("'#' found i:%d, j :%d\n", i, j);
			if (++k == 4 && checkaround(str, i, j, 1))
				return (1);
			if (checkaround(str, i, j, 0) == 0)
			{
				if (ii)
					ii = 0;
				else
					return (0);
			}
			if (j < 3 && str[i][j + 1] == '#' && str[i + 1] && str[i + 1][j] == '#')
				ii = 1;
		}
		if (j < 3) 
			j++;
	   	else
		{
			j = 0;
			i++;
		}
	}
	return (1);
}

int		sharpvalid(char **str, int tab[2], int k, char dir)
{
	if (k <= 3 && tab[1] < 3 && dir != 'g' && str[tab[0]][tab[1] + 1] == '#') // 3 nvx avant 4
	{
		tab[1] = tab[1] + 1;
		return (sharpvalid(str, tab, k + 1, 'd'));
	}
	if (k <= 3 && tab[1] > 0 && dir != 'd' && str[tab[0]][tab[1] - 1] == '#')
	{
		tab[1] = tab[1] - 1;
		return (sharpvalid(str, tab, k + 1, 'g'));
	}
	if (k <= 3 && tab[0] > 0 && dir != 'h' && str[tab[0] - 1][tab[1]] == '#')
	{
		tab[0] = tab[0] - 1;
		return (sharpvalid(str, tab, k + 1, 'b'));
	}
	if (k <= 3 && dir != 'b' && tab[0] < ft_numberline(str) && str[tab[0] + 1][tab[1]] == '#')
	{
		tab[0] = tab[0] + 1;
		return (sharpvalid(str, tab, k + 1, 'h'));
	}
	if (k >= 4)
		return (1);
	if (dir == 'd' || dir == 'g')
		return (sharpvalid(str, tab, k - 1, 'a'));
	return (0);
}

int		ft_error2(int *i, int *ii, int *j, char **str)
{
	int	k;
	int	tab[2];

	k = 0;
	while (str[*i + *ii] && str[*i + *ii][0] != '\0')
	{
		*j = 0;
		while (str[*i + *ii][*j] != '\0')
		{
			if (str[*i + *ii][*j] != '.' && str[*i + *ii][*j] != '#')
				return (-1);
			if (str[*i + *ii][*j] == '#')
			{
				tab[0] = *i + *ii;
				tab[1] = *j;
				if (k == 0)
				{	
					if (!isconx(str, tab[0], tab[1]))
					{
						//ft_putstr("ERREUR COnx\n");
						return (-1);
					}
					if (!sharpvalid(str, tab, 1, 'a'))
					{
					//	ft_putstr("ERREUR Sharvl\n");
						return (-1);
					}
				}
				k++;
			}
			*j = *j + 1;
		}
		*ii = *ii + 1;
	}
//	printf("k : %d\n", k);
	return (k);
}

int		ft_err3(int i, char **str, int j, char mode)
{
	int	tab;

	tab = 10;
	while (mode == 'l' && str[i] && str[i][0])
	{
		if (ft_strchr(str[i], '#') && tab == 10)
			tab = 1;
		else if (!ft_strchr(str[i], '#') && tab == 1)
			tab = 0;
		else if (ft_strchr(str[i++], '#') && tab == 0)
			return (0);
		//printf("ERR3 col 'l' // i : %d\n", i);
	}
	while (mode == 'c' && str[i][j] && j++ < 3)
	{
		if (ft_strchrcol(str, i, j, '#') && tab == 10)
			tab = 1;
		else if (!ft_strchrcol(str, i, j, '#') && tab == 1)
			tab = 0;
		else if (ft_strchrcol(str, i, j, '#') && tab == 0)
			return (0);
	}
	return (1);
}

int		error(char **str)
{
	int		i;
	int		j;
	int		k;
	int		ii;

	i = 0;
	j = 0;
	while ((i <= ft_numberline(str)) && (str[i] != NULL))
	{
		k = 0;
		ii = 0;
		if (str[i][0] != '\0' && ((!ft_err3(i, str, -1, 'l')) ||\
					!ft_err3(i, str, -1, 'l')))
		{
			//printf("ERR\n");
			return (0);
		}
		while (str[i + ii] && str[i + ii][0] != '\0')
		{
			j = 0;
			if ((k = ft_error2(&i, &ii, &j, str)) == -1)
				return (0);
		}
		if ((ii != 4 || j != 4 || k != 4) || (ii == 0 && k == 0))
		{	
	//		printf("Last, ii : %d, j : %d, k : %d\n", ii, j, k);
			return (0);
		}
		i = i + ii + 1;
	}
	return (1);
}
