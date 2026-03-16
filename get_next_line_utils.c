

#include "get_next_line.h"

size_t  ft_strlen(char *cad)
{
    size_t		i;

	i = 0;
	while (cad[i] != '\n' && cad[i])
		i++;
	return(i);
}

int		ft_cases(char *c)
{
	size_t		i;

	i = 0;
	while (c[i])
	{
		if (c[i] == '\n')
			return (0);
		i++;
	}
	return (-1);
}

void	ft_newaux(char	*c, char **s, size_t k)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	k++;
	while (c[k + len])
		len++;
	if (len == 0)
	{
		free(*s);
		(*s) = NULL;
		return ;
	}
	(*s) = malloc(sizeof(char) * (len + 1));
	if (!*s)
		return ;
	while (i < len)
	{
		(*s)[i] = c[(k + i)];
		i++;
	}
	(*s)[i] = '\0';
}

char	*ft_fill(char *c, char **s, char *str)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (*s)
	{
		while ((*s[i]))
		{
			str[i] = *s[i];
			i++;
		}
		free(*s);
	}
		while (c[k] != '\n' && c[k])
			str[i++] = c[k++];
	str[i++] = '\n';
	str[i] = '\0';
	if (c[k] != '\0')
		ft_newaux(c, s, k);
	return (str);
}

char	*ft_nextl(char *c, char **s)
{
	char	*str;

	if (*s && ft_newln(*s) == ft_strlen(*s))
	{
		str = malloc(sizeof(char) * (ft_newln(c) + ft_newln(*s) + 1));
		if (!str)
			return (NULL);
		str = ft_fill(c, s, str);
		return (str);
	}
	else if (*s)
	{
		str = malloc(sizeof(char) * (ft_newln(*s) + 1));
		if (!str)
			return (NULL);
		str = ft_staticfill(c, s, str);
		return (str);
	}
	str = malloc(sizeof(char) * (ft_newln(c) + 1));
	if (!str)
		return (NULL);
	str = ft_fill(c, s, str);
	return (str);
}
