/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:55:08 by nel-baz           #+#    #+#             */
/*   Updated: 2022/11/14 16:16:15 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_mystrlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*str;
	char		*line;
	int			len;
	int			i;

	if (!fd || !BUFFER_SIZE)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    len = read(fd, buff, BUFFER_SIZE);
	if ( len > 0)
	{
		buff[len] = '\0';
		str = ft_strjoin(str, buff);
		//while (len > 0)
	//	{
		i = ft_mystrlen(str, '\n') + 1;
		line = ft_substr(str, 0, i);
		str = ft_substr(str, i, strlen(str));
	//	}
		free (buff);
		return (line);
	}
	free (buff);
	return (NULL);
}
