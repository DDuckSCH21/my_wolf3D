/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:06:17 by dduck             #+#    #+#             */
/*   Updated: 2020/11/20 20:22:45 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int s, size_t n)
{
	unsigned char	*prt;

	prt = dest;
	if (n == 0)
		return (dest);
	while (n--)
		*prt++ = s;
	return (dest);
}
