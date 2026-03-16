
#include "get_next_line.h"

size_t	ft_newln(char *cad)
{
	size_t	len;

	len = 0;
	while (cad[len] != '\n' && cad[len])
		len++;
	return (len);
}

char    *ft_accum(char *c, char **s)
{
    size_t  i;
    size_t  j;
    char    *new;

	j = 0;
	i = 0;
	new = malloc(sizeof(char) * (ft_strlen(c) + ft_strlen(*s) + 1));
	if (!new)
		return (NULL);
	if(*s)
	{
		while ((*s)[i])
		{
			new[i] = (*s)[i];
			i++;
		}
	free(*s);
	}
	while (c[j])
	{
		new[i + j] = c[j];
		j++;
	}
	new[i + j] = '\0';	
	return (new);
}
char	*ft_staticfill(char *c, char **s, char *str)
{
	size_t	i;

	i = 0;
	while (i < ft_newln(*s))
	{
		str[i] = (*s)[i];
		i++;
	}
	(*s) = ft_accum(c, s);
	str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char			*c;
	static char		*s;
	int		boo;

	c = malloc(BUFFER_SIZE + 1);
	if (c == NULL)
		return (NULL);
	boo = read(fd, c, BUFFER_SIZE);
	if (boo <= 0)
	{
		free(c);
		if (s)
		{
			c = s;
			s = NULL;
			return (c);
		}
		return (NULL);
	}
	c[boo] = '\0';
	boo = ft_cases(c);
	if (boo == -1)
	{
		s = ft_accum(c, &s);
		free(c);
		c = get_next_line(fd);
	}
	else if (boo == 0)
		c = ft_nextl(c, &s);
	return (c);
}
/*
#include <fcntl.h>
#include <stdio.h>
int		main(void)
{
	int		fd;

	fd = open("archivo.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while (fd != 0)
		printf("%s\n", get_next_line(fd));
	close(fd);
	return (0);
}*/
