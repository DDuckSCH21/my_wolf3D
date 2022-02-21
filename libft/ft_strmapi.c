/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:55:27 by dduck             #+#    #+#             */
/*   Updated: 2020/11/22 13:13:55 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	int		i;
	char	*c;

	if (!str)
		return (NULL);
	c = (char *)malloc(ft_strlen((char *)str) + 1);
	if (!c)
		return (NULL);
	i = 0;
	while (str[i])
	{
		c[i] = f(i, str[i]);
		i++;
	}
	c[i] = '\0';
	return (c);
}
