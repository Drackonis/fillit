#include <stdio.h>
#include <stdlib.h>

/*int	solve(t_carre *carre, t_piece *first, int nbpiece)
{
;

}*/
unsigned long long nfact (size_t n)
{   if (n <= 0) return 1;
    unsigned long long s = n;

    while (--n) s *= n;

    return s;
}
unsigned long long pnk (size_t n, size_t k)
{   size_t d = (k < n ) ? n - k : 1;
    return nfact (n) / nfact (d);
}

void prnarray (int *a, size_t sz)
{   size_t i;
    for (i = 0; i < sz; i++) printf (" %2d", a[i]);
    putchar ('\n');
}

void swap (int *x, int *y)
{   int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute (int *tab, unsigned int i, int nbelem)
{   
	unsigned int	j;

    if (i == nbelem)
		prnarray(tab, nbelem);
    else
        for (j = i; j < nbelem; j++) {
            swap ((tab+i), (tab+j));
            permute (tab, i+1, nbelem);
            swap ((tab+i), (tab+j));  // backtrack
        }
}

int	*permuteonce(int *tab, unsigned int i, int nbelem)
{   
	unsigned int	j;

    if (i == nbelem)
	{
		return (tab);
	}
    else
        for (j = i; j < nbelem; j++) {
            swap ((tab+i), (tab+j));
            swap ((tab+i), (tab+j));
			return (tab);
            permute (tab, i+1, nbelem);
            swap ((tab+i), (tab+j));  // backtrack
        }
	return (tab);
}


int allorder (int nbelem) {

    int	*tab;
	int	i;
	int	poss;

	i = 1;
	tab = malloc(sizeof(int) * nbelem);
	while (i < nbelem)
	{
		tab[i] = i;
		i++;
	}
	tab[0] = 1;
	tab[1] = 2;
	tab[2] = 3;
	i = 0;
	poss = pnk(nbelem, nbelem);
	while (i < poss)
	{
printf("Before\n");
		prnarray(tab, nbelem);
printf("\n\n");
getchar();
		tab = permuteonce(tab, 0, 3);
printf("After\n");
printf("\n\n");
		i++;
	}
    return 0;
}

int	main(void)
{
printf("size-t %zu , int %zu\n", sizeof(size_t), sizeof(unsigned int));
	allorder(5);
	return (1);
}
	
