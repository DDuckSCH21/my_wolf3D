/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:29:50 by dduck             #+#    #+#             */
/*   Updated: 2020/11/20 20:19:38 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *dest, size_t n)
{
	size_t			i;
	unsigned char	*prt;

	prt = dest;
	i = 0;
	if (n == 0)
		return (0);
	while (n--)
		prt[i++] = 0;
	return (dest);
}
