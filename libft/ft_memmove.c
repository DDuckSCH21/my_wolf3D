/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:50:27 by dduck             #+#    #+#             */
/*   Updated: 2020/11/22 15:46:12 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	size_t			end;

	i = 0;
	end = n;
	if (dest < src)
	{
		while (i != end)
		{
			(((unsigned char*)dest)[i]) = (((unsigned char*)src)[i]);
			i++;
		}
	}
	else if (dest > src)
	{
		end = -1;
		i = n - 1;
		while (i != end)
		{
			(((unsigned char*)dest)[i]) = (((unsigned char*)src)[i]);
			i--;
		}
	}
	return (dest);
}
