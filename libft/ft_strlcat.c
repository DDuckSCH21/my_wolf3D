/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:53:44 by dduck             #+#    #+#             */
/*   Updated: 2020/11/21 16:58:10 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char	*i;
	char	*curs;
	size_t	len;

	i = (char *)ft_memchr(dest, '\0', size);
	if (i == NULL)
		return (size + ft_strlen(src));
	curs = (char *)src;
	len = (size_t)(i - dest) + ft_strlen(curs);
	while ((size_t)(i - dest) < size - 1 && *curs != '\0')
	{
		*i = *curs;
		i++;
		curs++;
	}
	*i = '\0';
	return (len);
}
