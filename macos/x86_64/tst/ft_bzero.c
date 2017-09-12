#include <stdio.h>
#include <string.h>
#include "libasm.h"

static int	ft_test(char *s, size_t len, size_t n)
{
	memset(s, '*', len);
	ft_bzero(s, n);
	for (size_t i=0; i<len; ++i)
		if (i<n && s[i]!='\0')
		{
			printf("\nKO: n=%lu: s[%lu]='%c' (%x)", n, i, s[i], s[i]);
			return 1;
		}
	return 0;
}

int			main(void)
{
	char	a[8];
	int		err = 0;

	printf("TEST: ft_bzero");
	for (size_t i=0; i<sizeof(a); ++i)
		err += ft_test(a, sizeof(a), i);
	if (err == 0)
		printf(": OK\n");
	else
		printf("\n");
	return 0;
}
