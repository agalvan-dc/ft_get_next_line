/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 19:01:48 by agalvan-          #+#    #+#             */
/*   Updated: 2026/06/02 15:43:05 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		return (free(str), NULL);
	++i;
	c = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!c)
		return (free(str), NULL);
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
	if (str[i] == '\n')
		i++;
	c = malloc(sizeof(char) * (i + 1));
	if (!c)
		return (NULL);
	while (j < i)
	{
		c[j] = str[j];
		j++;
	}
	c[j] = '\0';
	return (c);
}

char	*ft_read(int fd, char *str)
{
	ssize_t		boo;
	char		*cad;

	while (!str || !ft_strchr(str, '\n'))
	{
		cad = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!cad)
			return (free(str), NULL);
		boo = read(fd, cad, BUFFER_SIZE);
		if (boo <= -1)
			return (free(str), free(cad), NULL);
		if (boo == 0)
			return (free(cad), str);
		cad[boo] = '\0';
		if (!str)
			str = cad;
		else
		{
			str = ft_accum(cad, str);
			free(cad);
		}
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*s[1024];
	char		*c;

	if ((fd < 0 || fd >= 1024) || BUFFER_SIZE <= 0)
		return (NULL);
	s[fd] = ft_read(fd, s[fd]);
	if (!s[fd])
		return (NULL);
	c = ft_nextln(s[fd]);
	if (!c)
		return (free(s[fd]), s[fd] = NULL, NULL);
	s[fd] = ft_newaux(s[fd]);
	return (c);
}
