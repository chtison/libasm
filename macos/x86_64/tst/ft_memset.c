#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libasm.h"

const struct {
	size_t	len;
	int	c;
} cases[] = {
	{0, 0},
	{1, '*'},
	{10, 'B'},
	{42, 297},
};

static ssize_t	ft_test(int c, size_t len)
{
	ssize_t	err = 0;
	char	*s1, *s2;

	s1 = (char *)malloc(len+1);
	s2 = (char *)malloc(len+1);
	s1[len] = '\0';
	s2[len] = '\0';
	memset(s1, c, len);
	if (ft_memset(s2, c, len) != s2 && ++err)
		printf("\nKO: ft_memset(s2, c, len) didn't return s2");
	if (s2[len] != '\0' && ++err)
		printf("\nKO: s1[len] == '%c' != '\\0'", s2[len]);
	if (strcmp(s1, s2) != 0 && ++err)
		printf("\nKO: \"%s\" != \"%s\"", s1, s2);
	for (size_t i=0; i<len; ++i)
		if (s2[i] != (unsigned char)c && ++err)
			printf("\nKO: s1[%lu] == '%c' != '%c'", i, s2[i], (unsigned char)c);
	free(s1);
	free(s2);
	return err;
}

int			main(void)
{
	ssize_t	err = 0;

	printf("TEST: ft_memset");
	for (size_t i=0; i<sizeof(cases)/sizeof(*cases); ++i)
		err += ft_test(cases[i].c, cases[i].len);
	if (err == 0)
		printf(": OK");
	printf("\n");
	return 0;
}
