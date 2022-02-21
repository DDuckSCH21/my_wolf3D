/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:23:01 by dduck             #+#    #+#             */
/*   Updated: 2021/01/24 14:23:05 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_strchr(const char *src, int c)
{
	char	*s;

	s = (char *)src;
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == c)
		return (s);
	return (NULL);
}

char	*ft_gnl_strcpy(char *dst, const char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_gnl_strdup(const char *str)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)malloc(sizeof(char) * (ft_gnl_strlen((char *)str) + 1));
	if (NULL == s)
		return (NULL);
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	int		i;
	char	*dest;

	i = 0;
	if (NULL == s1 && NULL == s2)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * ((ft_gnl_strlen(s1)
		+ ft_gnl_strlen(s2) + 1)));
	if (!dest)
		return (NULL);
	if (s1 != NULL)
	{
		while (*s1 != '\0')
		{
			dest[i] = *s1++;
			i++;
		}
	}
	while (*s2 != '\0')
	{
		dest[i] = *s2++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_gnl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (i);
	while (str[i])
		i++;
	return (i);
}
