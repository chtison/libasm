#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libasm.h"

const char	*strings[] = {
	" World !",
	"",
	" 👻😍",
};

static int	ft_test(const char *s1, const char *s2)
{
	int		err = 0;
	char	*s3, *s4, *s5;

	s3 = (char *)malloc(strlen(s1)+strlen(s2)+1);
	s4 = (char *)malloc(strlen(s1)+strlen(s2)+1);
	strcpy(s3, s1);
	strcpy(s4, s1);
	strcat(s3, s2);
	s5 = ft_strcat(s4, s2);
	if (s5 != s4)
	{
		printf("\nKO: ft_strcat didn't return the original pointer");
		++err;
	}
	if (strcmp(s3, s4) != 0)
	{
		printf("\nKO: \"%s\" != \"%s\"", s3, s4);
		++err;
	}
	free(s3);
	free(s4);
	return err;
}

int			main(void)
{
	int		err = 0;

	printf("TEST: ft_strcat");
	for (size_t i=0; i<sizeof(strings)/sizeof(*strings); ++i)
		err += ft_test("Hello", strings[i]);
	for (size_t i=0; i<sizeof(strings)/sizeof(*strings); ++i)
		err += ft_test("\0**", strings[i]);
	if (err == 0)
		printf(": OK");
	printf("\n");
	return 0;
}
