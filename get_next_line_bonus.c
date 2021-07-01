#include "get_next_line_bonus.h"

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
	static char	*line_r[FIDE_SIZE];
	char		buf[BUFFER_SIZE + 1];
	ssize_t		rd;
	char		*tmp;

	rd = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (-1);
	if (line_r[fd] == NULL)
		line_r[fd] = ft_strdup("");
	while (!ft_strchr(line_r[fd], '\n') && rd > 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		buf[rd] = '\0';
		tmp = ft_strjoin(line_r[fd], buf);
		ft_delete((void **)&line_r[fd]);
		line_r[fd] = tmp;
	}
	if (rd < 0)
		return (-1);
	*line = ft_line(rd, line_r[fd]);
	tmp = ft_tmp(rd, line_r[fd], line);
	ft_delete((void **)&line_r[fd]);
	return (ft_ret(rd, &line_r[fd], tmp));
}
