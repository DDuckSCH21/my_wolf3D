/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 11:19:51 by dduck             #+#    #+#             */
/*   Updated: 2020/11/21 16:53:49 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*s;

	i = 0;
	s = (unsigned char*)src;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (s[i] == ch)
			return (s + i);
		i++;
	}
	return (NULL);
}
