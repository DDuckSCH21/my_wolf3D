/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 12:32:54 by dduck             #+#    #+#             */
/*   Updated: 2020/11/22 13:12:22 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char c, char const *set)
{
	size_t i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *str, char const *set)
{
	size_t		i;
	size_t		curs;
	size_t		end;
	char		*s;

	if (!str || !set)
		return (NULL);
	curs = 0;
	while (str[curs] && ft_inset(str[curs], set))
		curs++;
	end = ft_strlen((char *)str);
	while (curs < end && ft_inset(str[end - 1], set))
		end--;
	s = (char *)malloc(sizeof(*str) * (end - curs + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (curs < end)
	{
		s[i] = str[curs];
		i++;
		curs++;
	}
	s[i] = 0;
	return (s);
}
