/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 13:22:07 by dduck             #+#    #+#             */
/*   Updated: 2020/11/21 16:52:27 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	s = (unsigned char*)src;
	d = (unsigned char*)dest;
	if (dest || src)
	{
		while (n--)
		{
			d[i] = s[i];
			if (s[i] == (unsigned char)c)
				return (&(d[i + 1]));
			i++;
		}
		return (NULL);
	}
	return (NULL);
}
