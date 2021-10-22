#include "ft_malloc_pool.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	void *p;
	int a;
	for (int i = 0; i < 100; i++)
	{
		a = rand()%10+1;
		p = ft_malloc(a);
		printf("for : %p size %d\t", p, a);
		printf("find size %zu\n", get_malloc_size(p));
		if (a%2)
		{
			printf("free : %p %zu\n", p, get_malloc_size(p));
			ft_free(p);
		}
	}
	ft_free_all();
	return (0);
}
