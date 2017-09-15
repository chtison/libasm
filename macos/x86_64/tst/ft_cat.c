#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "libasm.h"

#define BUF_SIZE 4096

const char *cases[] = {
	"",
	"Hello World !",
	"👻😍😱",
};

static ssize_t	ft_test(const char *str)
{
	ssize_t	err = 0;
	int		p[3];
	char	buf[BUF_SIZE];

	pipe(p);
	write(p[1], str, strlen(str));
	p[2] = dup(1);
	dup2(1, p[1]);
	ft_cat(p[0]);
	dup2(p[2], 1);
	read(p[0], buf, BUF_SIZE);
	buf[strlen(str)] = '\0';
	if (strcmp(str, buf) != 0 && ++err)
		printf("\nKO: \"%s\" != \"%s\"", str, buf);
	close(p[0]);
	close(p[1]);
	return err;
}

int		main(void)
{
	ssize_t	err = 0;

	printf("TEST: ft_cat");
	for (size_t i=0; i<sizeof(cases)/sizeof(*cases); ++i)
		err += ft_test(cases[i]);
	if (err == 0)
		printf(":    OK");
	printf("\n");
	return 0;
}
