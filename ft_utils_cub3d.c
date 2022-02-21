/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_cub3d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:10:15 by dduck             #+#    #+#             */
/*   Updated: 2021/04/12 13:10:17 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int			ft_put_error(t_vars *vars, char *error)
{
	write(2, error, ft_strlen(error));
	ft_game_over(vars);
	return (1);
}

int			ft_get_num(char *line, int endflag, t_vars *vars)
{
	long long	res;
	long long	max;

	max = 2147483648;
	while (ft_isspace(*line))
		line++;
	if (*line == '-')
		ft_put_error(vars, "ERROR\n Negative resolutions\n");
	res = 0;
	while (ft_isdigit(*line))
	{
		if (res < max - (*line - '0') / 10)
			res = 10 * res + (*line - '0');
		line++;
	}
	if (endflag > 0 && (*line))
		ft_put_error(vars, "ERROR!Too match count resoluton!\n");
	if (res >= max || res < 0)
		res = max - 1;
	return ((int)res);
}

int			ft_count_lines(int fd, char *line, t_vars *vars)
{
	int res;
	int i;
	int flag;
	int j;

	res = 1;
	i = 0;
	flag = 0;
	j = 0;
	while (res == 1)
	{
		res = get_next_line(fd, &line);
		if (res == -1)
			ft_put_error(vars, "ERROR\n Incorrect file-config!\n");
		if (line[j] == '1' || line[j] == ' ')
			flag = 1;
		if (flag == 1)
			i++;
		if (res == 1 || res == 0)
			free(line);
	}
	return (i);
}

int			ft_strstrchr(const char *dst, const char *srcs)
{
	int flag;
	int i;
	int j;

	flag = 0;
	j = 0;
	while (srcs[j])
	{
		i = 0;
		while (dst[i])
		{
			if (dst[i] == srcs[j])
				flag++;
			i++;
		}
		j++;
	}
	return (flag);
}

void		my_mlx_puxel_put(t_vars *vars, int x, int y, int color)
{
	char *dst;

	dst = vars->addr + (y * vars->line_len + x * (vars->bpp / 8));
	*(unsigned int*)dst = color;
}
