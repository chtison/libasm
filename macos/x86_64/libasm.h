#ifndef LIBASM_H
# define LIBASM_H

# include <stddef.h>

void	ft_bzero(char *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
ssize_t	ft_puts(const char *s);
char	*ft_strcat(char *dst, const char *str);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *s);

#endif
