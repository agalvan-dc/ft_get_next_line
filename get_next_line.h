

#ifndef "GET_NEXT_LINE_H"
#define "GET_NEXT_LINE_H"

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, char *str);
char	*ft_nextln(char *str);
char	*ft_newaux(char *str);
size_t	ft_strlen(char *cad);
char	*ft_accum(char *c, char *s);
char	*ft_strchr(const char *s, int c);

#endif
