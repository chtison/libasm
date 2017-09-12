#include <stdio.h>
#include <string.h>
#include "libasm.h"

const char	*strings[] = {
	"Hello World !",
	"",
	"👻🤡🐳",
};

static int	ft_test(const char *s)
{
	size_t	len1, len2;

	len1 = strlen(s);
	len2 = ft_strlen(s);
	if (len1 != len2) {
		printf("\nKO: \"%s\": strlen=%lu but ft_strlen=%lu", s, len1, len2);
		return 1;
	}
	return 0;
}

int			main(void)
{
	int		err = 0;

	printf("TEST: ft_strlen");
	for (size_t i=0; i<sizeof(strings)/sizeof(*strings); ++i)
		err += ft_test(strings[i]);
	if (err == 0)
		printf(": OK\n");
	else
		printf("\n");
	return 0;
}
