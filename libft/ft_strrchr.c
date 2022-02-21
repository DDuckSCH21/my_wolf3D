/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:05:19 by dduck             #+#    #+#             */
/*   Updated: 2020/11/21 16:59:22 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	char	*s;
	int		len;

	len = ft_strlen(src);
	s = (char *)src + len;
	while (len >= 0)
	{
		if (*s == c)
			return (s);
		len--;
		s--;
	}
	return (NULL);
}
