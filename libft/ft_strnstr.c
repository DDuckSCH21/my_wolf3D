/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:29:24 by dduck             #+#    #+#             */
/*   Updated: 2020/11/20 14:28:31 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *hstck, char *ndl, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!*ndl)
		return ((char *)hstck);
	while (hstck[i] != '\0' && i < len)
	{
		if (hstck[i] == ndl[0])
		{
			while (ndl[j] != '\0' && hstck[i + j] == ndl[j] \
				&& i + j < len)
			{
				if (ndl[j + 1] == '\0')
					return ((char *)&hstck[i]);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
