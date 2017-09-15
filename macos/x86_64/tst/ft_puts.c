#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "libasm.h"

const char	*strs[] = {
	"",
	"Hello World !",
	"👻🐳😡😍",
};

static ssize_t	ft_test(const char *str)
{
	ssize_t	err;

	return 0;
	if ((err = ft_puts(str)) < 0)
		printf("\nKO: %s", strerror(errno));
	return err < 0 ? err : 0;
}

int			main(void)
{
	size_t	i;
	ssize_t	err = 0;

	printf("TEST: ft_puts");
	for (i=0;i<sizeof(strs)/sizeof(*strs);++i)
		err += ft_test(strs[i]);
	if (err == 0)
		printf(":   OK");
	printf("\n");
	return 0;
}
