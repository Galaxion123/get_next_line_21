#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l] != '\0')
		l++;
	return (l);
}

int	ft_delete(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

char	*ft_line(ssize_t rd, char *line_r)
{
	if (rd == 0)
		return (ft_strdup(line_r));
	else
		return (ft_substr(line_r, 0, (ft_strchr(line_r, '\n') - line_r)));
}

char	*ft_tmp(ssize_t rd, char *line_r, char **line)
{
	if (rd > 0)
		return (ft_strdup(line_r + (ft_strlen(*line) + 1)));
	else
		return (ft_strdup(line_r + ft_strlen(*line)));
}

int	get_next_line(int fd, char **line)
{
	static char	*line_r = NULL;
	char		buf[BUFFER_SIZE + 1];
	ssize_t		rd;
	char		*tmp;

	rd = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (-1);
	if (line_r == NULL)
		line_r = ft_strdup("");
	while (!ft_strchr(line_r, '\n') && rd > 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		buf[rd] = '\0';
		tmp = ft_strjoin(line_r, buf);
		ft_delete((void **)&line_r);
		line_r = tmp;
	}
	if (rd < 0)
		return (-1);
	*line = ft_line(rd, line_r);
	tmp = ft_tmp(rd, line_r, line);
	ft_delete((void **)&line_r);
	return (ft_ret(rd, &line_r, tmp));
}
