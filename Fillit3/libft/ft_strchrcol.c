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
