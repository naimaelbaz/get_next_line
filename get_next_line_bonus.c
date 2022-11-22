/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:26:20 by nel-baz           #+#    #+#             */
/*   Updated: 2022/11/22 10:41:21 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	if (s && c == '\0')
	{
		while (s[i])
			i++;
	}
	else if (s && c == '\n')
	{
		while (s[i] && s[i] != '\n')
			i++;
	}
	return (i);
}

char	*ft_read(int fd, char *str)
{
	char		*buff;
	int			len;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (free(str), str = NULL, NULL);
	len = 1;
	while (!ft_strchr(str, '\n') && len > 0)
	{	
		len = read(fd, buff, BUFFER_SIZE);
		if (len == -1)
		{
			free (buff);
			free(str);
			return (NULL);
		}
		buff[len] = '\0';
		str = ft_strjoin(str, buff);
	}
	free (buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[4096];
	char		*tmp;
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (str[fd])
			return (free(str[fd]), str[fd] = NULL, NULL);
		return (NULL);
	}
	str[fd] = ft_read(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	i = ft_strlen(str[fd], '\n');
	line = ft_substr(str[fd], 0, i + 1);
	if (!line)
	{
		if (str[fd])
			return (free(str[fd]), str[fd] = NULL, NULL);
		return (NULL);
	}
	tmp = str[fd];
	str[fd] = ft_substr(tmp, i + 1, ft_strlen(tmp, '\0'));
	return (free(tmp), line);
}
