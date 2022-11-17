/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:55:08 by nel-baz           #+#    #+#             */
/*   Updated: 2022/11/17 13:17:34 by nel-baz          ###   ########.fr       */
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

char	*ft_read(int fd, char *str)
{
	char		*buff;
	int			len;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	len = 1;
	while (!ft_strchr(str, '\n') && len > 0)
	{	
		len = read(fd, buff, BUFFER_SIZE);
		if (len == -1)
		{
			free (buff);
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
	static char	*str;
	char		*line;
	int			i;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	if (str == NULL)
		str = strdup("");
	str = ft_read(fd, str);
	if (str[0] == '\0')
		return (NULL);
	i = ft_mystrlen(str, '\n') + 1;
	line = ft_substr(str, 0, i);
	str = ft_substr(str, i, ft_strlen(str));
	return (line);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	// printf("%s", get_next_line(-1));
	printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
}
