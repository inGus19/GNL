#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <stdlib.h>

size_t		ft_strlen(const char *s);
char		*ft_substr(const char *s, unsigned int start, size_t l);
char		*ft_strdup(const char *s);
char		*ft_strchr(const char *s, int a);
char		*ft_strjoin(const char *s1, const char *s2);
char		*get_next_line(int fd);
char		*fill_line(int fd, char *stash);
char		*set_line(char *stash);

#endif
