/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 14:22:01 by dduck             #+#    #+#             */
/*   Updated: 2021/01/24 14:22:06 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include "get_next_line.h"

void	check_byte(char *remainder, int byte_was, char *buf)
{
	free(buf);
	buf = NULL;
	if (byte_was == 0)
	{
		if (remainder && *remainder != 0)
		{
			free(remainder);
			remainder = NULL;
		}
	}
}

int		ft_check_start(char **line, char **buf, int fd)
{
	if (NULL == line || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!(*buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (0);
	return (1);
}

void	ft_check_nl(char *p_n, char **remainder, char **line)
{
	char		*tmp;

	if ((p_n = ft_gnl_strchr(*line, '\n')))
	{
		*p_n = '\0';
		*remainder = ft_gnl_strdup(++p_n);
		tmp = *line;
		*line = ft_gnl_strdup(tmp);
		free(tmp);
		tmp = NULL;
	}
}

char	*ft_check_remainder(char **remainder, char **line)
{
	char		*p_n;

	p_n = NULL;
	if (*remainder)
	{
		if ((p_n = ft_gnl_strchr(*remainder, '\n')))
		{
			*p_n = '\0';
			*line = ft_gnl_strdup(*remainder);
			ft_gnl_strcpy(*remainder, ++p_n);
		}
		else
		{
			*line = ft_gnl_strdup(*remainder);
			free(*remainder);
			*remainder = NULL;
		}
	}
	else
	{
		*line = NULL;
	}
	return (p_n);
}

int		get_next_line(int fd, char **line)
{
	static char	*remainder;
	char		*buf;
	int			byte_was;
	char		*p_n;
	char		*tmp;

	byte_was = 1;
	tmp = NULL;
	if (!(ft_check_start(line, &buf, fd)))
		return (-1);
	p_n = ft_check_remainder(&remainder, line);
	while (!p_n && byte_was != 0)
	{
		byte_was = read(fd, buf, BUFFER_SIZE);
		buf[byte_was] = '\0';
		tmp = *line;
		*line = ft_gnl_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_gnl_strchr(*line, '\n'))
			break ;
	}
	ft_check_nl(p_n, &remainder, line);
	check_byte(remainder, byte_was, buf);
	return (byte_was == 0) ? 0 : 1;
}
