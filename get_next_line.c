
#include "get_next_line.h"

char	*ft_newaux(char *str)
{
	size_t		i;
	size_t		j;
	char		*c;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || (ft_strlen(str) == i + 1))
		return(free(str), NULL);
	i += 1;
	c = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!c)
		return (NULL);
	while (str[i])
		c[j++] = str[i++];
	c[j] = '\0';
	free(str);
	return (c);
}

char	*ft_nextln(char *str)
{
	char	*c;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	c = malloc(sizeof(char) * (i + 2));
	if (!c)
		return (NULL);
	while (j < i)
	{
		c[j] = str[j];
		j++;
	}
	c[j++] = '\n';
	c[j] = '\0';
	return (c);
}

char	*ft_read(int fd, char *str)
{
	int		boo;
	char	*cad;
	while (!ft_strchr(str, '\n'))
	{
		cad = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!cad)
			return (NULL);
		boo = read(fd, cad, BUFFER_SIZE);
		if (boo <= -1)
			return (free(str), free(cad), NULL);
		if (boo == 0)
		{
			if (str)
				return (free(cad), str);
			else
				return (free(cad), NULL);
		}
		cad[boo] = '\0';
		if (!str)
			str = cad;
		else
			str = accum(cad, str);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char *s;
	char		*c;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	s = ft_read(fd, s);
	if (!s)
		return (NULL);
	c = ft_nextln(s);
	s = ft_newaux(s);
	return (c);
}
