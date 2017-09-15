#ifndef LIBASM_H
# define LIBASM_H

# include <stddef.h>

void	ft_bzero(char *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);

char	*ft_strcat(char *dst, const char *str);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *s);

ssize_t	ft_puts(const char *s);

#endif
