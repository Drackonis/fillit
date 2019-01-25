#include "libft.h"

int	ft_numberline(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	i--;
	return (i);
}
