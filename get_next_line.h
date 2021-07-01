#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

int		get_next_line(int fd, char **line);
int		ft_ret(ssize_t rd, char **line_r, char *tmp);
char	*ft_line(ssize_t rd, char *line_r);
char	*ft_tmp(ssize_t rd, char *line_r, char **line);
int		ft_delete(void **ptr);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif