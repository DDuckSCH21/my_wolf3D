/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 17:54:25 by dduck             #+#    #+#             */
/*   Updated: 2020/11/23 19:23:37 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countarg(char const *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != c) && (0 == count))
			count++;
		if ((str[i] == c) && (str[i + 1] != c) && (str[i + 1] != '\0'))
			count++;
		i++;
	}
	return (count);
}

static void	ft_free(char **matr, size_t n)
{
	if (0 == n)
		free(matr);
	else
	{
		while ((n - 1) > 0)
		{
			free(matr[n - 1]);
			n--;
		}
		free(matr);
	}
}

static void	ft_newworld(const char *st, char c, int i, char **matr)
{
	int		curs;
	int		start;
	int		len;

	curs = 0;
	start = 0;
	while (curs < ft_countarg(st, c))
	{
		while (st[i] && st[i] == c)
			i++;
		if (0 == i || ((st[i] != c) && (st[i - 1] == c || st[i - 1] == '\0')))
			start = i;
		if (st[i + 1] == c || st[i + 1] == '\0')
		{
			len = i + 1 - start;
			matr[curs++] = ft_substr(st, i + 1 - len, len);
			if (!matr[curs - 1])
			{
				ft_free(matr, curs - 1);
				return ;
			}
		}
		i++;
	}
	matr[curs] = NULL;
}

char		**ft_split(char const *str, char c)
{
	char	**newmatr;
	int		count;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	count = ft_countarg(str, c);
	newmatr = (char **)malloc((count + 1) * sizeof(char *));
	if (!newmatr)
		return (NULL);
	ft_newworld(str, c, i, newmatr);
	return (newmatr);
}
