#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*tmp;

	tmp = s;
	while (*tmp != '\0' && *tmp != c)
	{
		tmp++;
	}
	if (*tmp == c)
		return ((char *)tmp);
	else
		return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buf;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (ft_strdup(""));
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	buf = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (buf == 0)
		return (0);
	while (s1[j] != '\0')
		buf[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		buf[i++] = s2[j++];
	buf[i] = '\0';
	return (buf);
}

char	*ft_strdup(const char *s)
{
	char		*dup;
	const char	*str;
	char		*tmp;

	str = s;
	dup = (char *) malloc(ft_strlen(s) + 1);
	if (dup == 0)
		return (NULL);
	tmp = dup;
	while (*str != '\0')
	{
		*tmp = *str;
		str++;
		tmp++;
	}
	*tmp = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buf;
	size_t	i;
	size_t	j;

	i = 0;
	j = start;
	if (!s || len <= 0 || start >= ft_strlen(s))
		return (ft_strdup(""));
	buf = (char *) malloc(len + 1);
	if (buf == 0)
		return (0);
	while (s[j] != '\0' && i < len)
	{
		buf[i] = s[j];
		i++;
		j++;
	}
	buf[i] = '\0';
	return (buf);
}

int	ft_ret(ssize_t rd, char **line_r, char *tmp)
{
	if (rd == 0)
	{
		*line_r = tmp;
		return (0 * ft_delete((void **)line_r));
	}
	else
	{
		*line_r = tmp;
		return (1);
	}
}
