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

char	*init_left(char *left)
{
	if (!left)
		left = ft_strdup("");
	return (left);
}

char	*read_contact(int fd, char *left)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	b_read;
	char	*temp;

	while (!ft_strchr(left, '\n'))
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(left);
			return (NULL);
		}
		if (b_read == 0)
			break ;
		buffer[b_read] = '\0';
		temp = ft_strjoin(left, buffer);
		if (!temp)
		{
			free(left);
			return (NULL);
		}
		free(left);
		left = temp;
	}
	return (left);
}

char	*fill_line(int fd, char *left)
{
	left = init_left(left);
	if (!left)
		return (NULL);
	return (read_contact(fd, left));
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

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= MAXINT)
		return (NULL);
	stash = fill_line(fd, stash);
	if (!stash)
		return (NULL);
	line = set_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	tmp = stash;
	stash = ft_strdup(stash + ft_strlen(line));
	free(tmp);
	if (!stash)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
