/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaes <acaes@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:39:41 by acaes             #+#    #+#             */
/*   Updated: 2024/11/09 17:13:21 by acaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *s)
{
	int	i;

	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int a)
{
	char	c;
	int		i;

	c = (char)a;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		return (NULL);
	}
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	l;
	char	*dst;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	dst = (char *)malloc(sizeof(char) * l + 1);
	if (!dst)
		return (NULL);
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[l] = '\0';
	return (dst);
}

char	*ft_substr(const char *s, unsigned int start, size_t l)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (l > ft_strlen(s + start))
		l = ft_strlen(s + start);
	str = (char *)malloc(sizeof(char) * (l + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < l)
	{
		str[i] = s[start + 1];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}
