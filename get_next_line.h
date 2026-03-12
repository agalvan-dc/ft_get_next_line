

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
int		ft_cases(char *c, static char **s);
size_t	ft_strlen(char cad);
char	*ft_nextl(char *c, static char **s);
void	ft_newaux(char *c, static char **s, size_t k);

#endif
