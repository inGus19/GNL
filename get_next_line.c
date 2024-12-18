/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaes <acaes@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:19:25 by acaes             #+#    #+#             */
/*   Updated: 2024/11/16 18:38:38 by acaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
}

char	*fill_line(int fd, char *left)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	b_read;
	char	*temp;

	if (!left)
		left = ft_strdup("");
	if (!left)
		return (NULL);
	while (!ft_strchr(left, '\n'))
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
			return (ft_free(&left));
		if (b_read == 0)
			break ;
		buffer[b_read] = '\0';
		temp = ft_strjoin(left, buffer);
		if (!temp)
			return (ft_free(&left));
		free(left);
		left = temp;
	}
	return (left);
}

char	*set_line(char *line)
{
	char	*extracted_line;
	ssize_t	l;

	if (!line || *line == '\0')
		return (NULL);
	l = 0;
	while (line[l] && line[l] != '\n')
		l++;
	if (line[l] == '\n')
		l++;
	extracted_line = ft_substr(line, 0, l);
	return (extracted_line);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;
	char		*tmp;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE >= MAXINT)
		return (NULL);
	stash = fill_line(fd, stash);
	if (!stash)
		return (NULL);
	line = set_line(stash);
	if (!line)
		return (ft_free(&stash));
	tmp = stash;
	stash = ft_strdup(stash + ft_strlen(line));
	if (!stash)
		return (ft_free(&line));
	free(tmp);
	return (line);
}
/*
#include <stdio.h>

int main()
{
    //int fd = open("file1.txt", O_RDONLY);  // Ouvrir un fichier en lecture
    char *line;

    while ((line = get_next_line(0)) != NULL)
	{
        printf("%s", line);
        free(line);
    }
    //close(fd);
    return 0;
}
*/
