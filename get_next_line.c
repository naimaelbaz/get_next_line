/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:55:08 by nel-baz           #+#    #+#             */
/*   Updated: 2022/11/16 13:41:37 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


#define BUFFER_SIZE 5

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

	if (!fd || !BUFFER_SIZE)
		return (NULL);
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

	if (str == NULL)
		str = strdup("");
	str = ft_read(fd, str);
	i = ft_mystrlen(str, '\n') + 1;
	line = ft_substr(str, 0, i);
	str = ft_substr(str, i, ft_strlen(str));
	return (line);
}

int	main(void)
{
	int fd;
    char *tab;

    fd = open("test.txt", O_RDONLY);
    tab = get_next_line(fd);
    printf("%s", tab);
    free(tab);
    tab = get_next_line(fd);
    printf("%s", tab);
    tab = get_next_line(fd);
    printf("%s", tab);
    tab = get_next_line(fd);
    printf("%s", tab);
    close(fd);
	return (0);
}
