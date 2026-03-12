

#include "get_next_line.h"

int		ft_cases(char *c, static char **s)
{
	size_t		i;

	i = 0;
	while (c[i] != '\n')
	{
		if (c[i] == '\n')
			return (0);
		i++;
	}
	*s = malloc (sizeof(char) * i);
	if (*s == NULL)
		return (NULL);
	while (i >= 0)
	{
		(*s)[i] = c[i];
		i--;
	}
	return (-1);
}

void	ft_newaux(char	*c, static char **s, size_t k)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = k;
	while (c[k])
		c[k++];
	*s = malloc(sizeof(char) * (k - j + 1));
	if (!*s)
		return (NULL);
	while (c[k - j])
		*s[i++] = c[(k - j)++];
	*s[i] = '\0';
}

char	*ft_fill(char *c, static char **s, char *str)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (*s != NULL)
	{
		while (*s[i])
		{
			str[i] = *s[i];
			i++;
		}
		free(*s);
	}
		while (c[k] != '\0' && c[k])
			str[i++] = c[k++];
	str[i] = '\0';
	if (c[k] != NULL)
		ft_newaux(c, s, k);
	return (str);
}

size_t	ft_strlen(char cad)
{
	size_t		i;

	i = 0;
	while (cad[i] != '\n' && cad[i])
		i++;
	return(i);
}

char	*ft_nextl(char *c, static char **s)
{
	char	*str;
	size_t	len;	

	if (*s != NULL)
	{
		len = ft_strlen(c);
		str = malloc(sizeof(char) * (len + ft_strlen(s)));
		if (!str)
		{
			free(s);
			return (NULL); 
		}
		str = ft_fill(c, s, str);
		return (str);
	}
	str = malloc(sizeof(char) * ft_strlen(c));
		if (!str)
			return (NULL);
	ft_fill(c, s);
	return (str);
}
