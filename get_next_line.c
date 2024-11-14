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

// Fonction pour extraire une ligne de `stash` jusqu'au premier '\n' inclus
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

// Fonction pour remplir `stash` en lisant le fichier jusqu'à rencontrer un '\n'
char	*fill_line(int fd, char *stash)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	byte_read;
	char	*left;

	if (!stash)
	{
		stash = ft_strdup("");
		if (!stash)
			return (NULL);
	}
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
		if (!stash)
		{
			free(left);
			return (NULL);
		}
		free(left);
	}
	return (stash);
}

// Fonction principale `get_next_line`
char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = fill_line(fd, stash);
	if (!stash || *stash == '\0')
		return (NULL);
	line = set_line(stash);
	if (!line)
		return (NULL);
	return (line);
}

/*int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Erreur d'ouverture de fichier");
		return (-1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
