#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libasm.h"

const char *strs[] = {
	"",
	"Hello World !",
	"👻🐳😡😍",
};

static ssize_t	ft_test(const char *str)
{
	ssize_t	err = 0;
	char	*s1, *s2;

	s1 = strdup(str);
	s2 = ft_strdup(str);
	if (strcmp(s1, s2) != 0)
	{
		printf("\nKO: \"%s\" != \"%s\"", s1, s2);
		++err;
	}
	free(s1);
	free(s2);
	return (err);
}

int			main(void)
{
	ssize_t	err = 0;

	printf("TEST: ft_strdup");
	for (size_t i=0;i<sizeof(strs)/sizeof(*strs);++i)
		err += ft_test(strs[i]);
	if (err == 0)
		printf(": OK");
	printf("\n");
	return 0;
}
