#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libasm.h"

char *strs[] = {
	"",
	"Hello World !",
	"👻👻😍🐳🤡",
};

static int	ft_test(char const *str)
{
	int		err = 0;
	char	*s1, *s2, *s3;
	size_t	len = strlen(str);

	s1 = (char *)malloc(len+1);
	s2 = (char *)malloc(len+2);
	s2[len+1] = '*';
	strcpy(s1, str);
	s3 = ft_strcpy(s2, str);
	if (s3 != s2) {
		printf("\nKO: ft_strcpy didn't return original pointer");
		++err;
	}
	if (s2[len+1] != '*') {
		printf("\nKO: ft_strcpy copies to far");
		++err;
	}
	if (strcmp(s1, s2) != 0) {
		printf("\nKO: \"%s\" != \"%s\"", s1, s2);
		++err;
	}
	free(s1);
	free(s2);
	return err;
}

int			main(void)
{
	int		err = 0;

	printf("TEST: ft_strcpy");
	for (size_t i=0; i<sizeof(strs)/sizeof(*strs); ++i)
		err += ft_test(strs[i]);
	if (err == 0)
		printf(": OK");
	printf("\n");
	return 0;
}
