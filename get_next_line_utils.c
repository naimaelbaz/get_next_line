/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:54:50 by nel-baz           #+#    #+#             */
/*   Updated: 2022/11/20 21:19:57 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
	{
		s1 = ft_strdup("");
		if (!s1)
			return (free(s1), NULL);
	}
	i = ft_strlen(s1, '\0');
	j = ft_strlen(s2, '\0');
	str = (char *)malloc((i + j + 1) * sizeof(char));
	if (!str)
		return (free(s1), NULL);
	ft_memcpy((void *)str, (void *)s1, i);
	ft_memcpy((void *)str + i, (void *)s2, j + 1);
	return (free(s1), s1 = NULL, str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	l;

	i = 0;
	if (!s)
		return (NULL);
	l = ft_strlen(s, '\0');
	if (start >= l || *s == '\0')
		return (NULL);
	if (len > l || start + len > l)
		len = l - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i] != '\0' && i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	size_t	i;
	size_t	j;

	j = 0;
	if (!s1)
		return (NULL);
	i = ft_strlen(s1, '\0');
	str = malloc(i * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[j] != '\0')
	{
		str[j] = s1[j];
		j++;
	}
	str[j] = '\0';
	if (*str != '\0')
	{
		free (s1);
		s1 = NULL;
	}
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	l;

	i = 0;
	if (!s)
		return (NULL);
	l = ft_strlen(s, '\0');
	while (i < l)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*tmp;
	char	*tmp1;

	tmp = (char *) dest;
	tmp1 = (char *) src;
	while (n > 0)
	{
		*tmp++ = *tmp1++;
		n--;
	}
	return (dest);
}
