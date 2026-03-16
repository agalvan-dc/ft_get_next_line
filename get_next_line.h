

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
int		ft_cases(char *c);
char	*ft_accum(char *c, char **s);
size_t	ft_strlen(char *cad);
size_t	ft_newln(char *cad);
char	*ft_nextl(char *c, char **s);
char	*ft_fill(char *c, char **s, char *str);
void	ft_newaux(char *c, char **s, size_t k);
char	*ft_staticfill(char *c, char **s, char *str);

#endif
