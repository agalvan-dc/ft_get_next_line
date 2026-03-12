
#include "get_next_line.h"

char	*get_next_line(int fd);
{
	char			*c;
	static char		*s;
	int		boo;

	c = malloc(BUFFER_SIZE);
	if (c == NULL)
		return (NULL);
	read(fd, &c, BUFFER_SIZE);
	boo = ft_cases(c, &s);
	if (boo == -1)
	{
		free(c);
		c = get_next_line(fd);
	}
	else if (boo == 0)
		c = ft_nextl(c, &s);
	return (c);
}
