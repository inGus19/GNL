/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaes <acaes@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:19:25 by acaes             #+#    #+#             */
/*   Updated: 2024/11/12 21:19:30 by acaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#define BUFFER_SIZE 10

char	*set_line(char *stash)
{
	char	*line;
	char	*left;
	ssize_t	l;

	if (!stash || *stash == '\0')
		return (NULL);
	l = 0;
	while (stash[l] && stash[l] != '\n')
		l++;
	if (stash[l] == '\n')
		l++;
	line = ft_substr(stash, 0, l);
	if (!line)
		return (NULL);
	left = stash;
	stash = ft_strdup(stash + l);
	free(left);
	return (line);
}

char	*fill_line(int fd, char *stash)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	byte_read;
	char	*left;

	while (!ft_strchr(stash, '\n'))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (NULL);
		if (byte_read == 0)
			break ;
		buffer[byte_read] = '\0';
		left = stash;
		stash = ft_strjoin(stash, buffer);
		free(left);
		if (!stash)
			return (NULL);
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*left;

	stash = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0) 
		return (NULL);
	stash = fill_line(fd, stash);
	if (!stash)
		return (NULL);
	line = set_line(stash);
	if (!line)
		return (NULL);
	left = stash;
	stash = ft_strdup(stash + ft_strlen(line));
	free(left);
	return (line);
}

int	main()
{
	int		fd = open("test.txt", O_RDONLY);
	char	*line;

	if (fd == -1)
	{
		perror("opening file failed");
		return (-1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close (fd);
	return (0);
}
