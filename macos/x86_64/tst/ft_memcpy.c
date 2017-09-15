#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libasm.h"

const struct {
	size_t	len;
	char	c;
} cases[] = {
	{0, 0},
	{0, '*'},
	{1, '*'},
	{1, 'X'},
	{2, 'z'},
	{42, 'O'},
};

static ssize_t	ft_test(char c, size_t len)
{
	ssize_t	err = 0;
	char	*b1, *b2;

	b1 = malloc(len+1);
	b2 = malloc(len+1);
	b1[len] = '\0';
	b2[len] = '\0';
	memset(b1, c, len);
	if (ft_memcpy(b2, b1, len) != b2 && ++err)
		printf("\nKO: ft_memcpy(b2, b1, len) didn't return b2");
	if (b2[len] != '\0' && ++err)
		printf("\nKO: ft_memcpy(b2, b1, %lu) wrote to far in b2", len);
	if (strcmp(b1, b2) != 0 && ++err)
		printf("\nKO: \"%s\" != \"%s\"", b1, b2);
	free(b1);
	free(b2);
	return err;
}

int				main(void)
{
	ssize_t	err = 0;

	printf("TEST: ft_memcpy");
	for (size_t i=0; i<sizeof(cases)/sizeof(*cases); ++i)
		err += ft_test(cases[i].c, cases[i].len);
	if (err == 0)
		printf(": OK");
	printf("\n");
	return 0;
}
