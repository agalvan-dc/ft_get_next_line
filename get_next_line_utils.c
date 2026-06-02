/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 19:02:03 by agalvan-          #+#    #+#             */
/*   Updated: 2026/06/02 19:02:42 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *cad)
{
	size_t	len;

	len = 0;
	while (cad[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)s;
	c = (char)c;
	if (!p || !p[0])
		return (NULL);
	while (p[i])
	{
		if (p[i] == c)
			return (&p[i]);
		i++;
	}
	if (c == '\0')
		return (&p[i]);
	return (NULL);
}

char	*ft_accum(char *c, char *s)
{
	size_t	i;
	size_t	j;
	char	*new;

	j = 0;
	i = 0;
	new = malloc(sizeof(char) * (ft_strlen(c) + ft_strlen(s) + 1));
	if (!new)
		return (free(s), NULL);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	free(s);
	while (c[j])
		new[i++] = c[j++];
	new[i] = '\0';
	return (new);
}
