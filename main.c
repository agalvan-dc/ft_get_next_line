/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 14:01:45 by agalvan-          #+#    #+#             */
/*   Updated: 2026/06/02 14:49:21 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*str;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	str = ft_get_next_line(fd);
	if (!str)
		return (close(fd), 1);
	while (str)
	{
		printf("%s\n", str);
		free(str);
		str = ft_get_next_line(fd);
	}
	return (free(str), close(fd), 0);
}
