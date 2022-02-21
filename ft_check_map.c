/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:08:16 by dduck             #+#    #+#             */
/*   Updated: 2021/04/12 13:08:17 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_get_count_sym(char *line, char c)
{
	int i;

	i = 0;
	while (*line != '\0')
	{
		if (*line == c)
			i++;
		line++;
	}
	return (i);
}

int		ft_check_map_endline(t_vars *vars, char **map)
{
	int	x;
	int	y;

	y = 0;
	x = vars->end_x_map;
	if (!map[x])
		return (0);
	while (map[x][y])
	{
		if (ft_strchr(MAP_SYM_NW, map[x][y]))
			ft_put_error(vars, "ERROR\n Invalid Map endline\n");
		if (!(ft_strchr(MAP_SYM, map[x][y])))
			ft_put_error(vars, "ERROR\n Invalid Map endline\n");
		y++;
	}
	return (1);
}

int		ft_check_pos(char **map, int x, int y)
{
	if ((x == 0 && ft_strchr(MAP_SYM_NW, map[x][y]))
		|| (y == 0 && ft_strchr(MAP_SYM_NW, map[x][y])))
		return (0);
	if (!(ft_strchr(MAP_SYM, map[x][y])))
		return (0);
	if ((ft_strchr(MAP_SYM_NW, map[x][y]))
		&& ((((int)ft_strlen(map[x + 1]) < y)
		|| (int)ft_strlen(map[x - 1]) < y)
		|| (((int)ft_strlen(map[x + 1])
		>= y && map[x + 1][y] == ' ') || ((int)ft_strlen(map[x - 1])
		>= y && map[x - 1][y] == ' '))))
		return (0);
	if (ft_strchr(MAP_SYM_NW, map[x][y]) && (!map[x - 1][y] ||
		!map[x - 1][y + 1] || !map[x][y + 1] || !map[x + 1][y + 1] ||
		!map[x + 1][y] || !map[x + 1][y - 1] || !map[x][y - 1] ||
		!map[x - 1][y - 1]))
		return (0);
	if (ft_strchr(MAP_SYM_NW, map[x][y]) && (ft_strchr(MP_SPC, map[x][y - 1])
	|| ft_strchr(MP_SPC, map[x][y + 1])))
		return (0);
	if (map[x][y] == '1' || map[x][y] == ' ')
		return (1);
	return (1);
}

void	ft_check_map(t_vars *vars, char **map)
{
	int x;
	int y;

	x = 0;
	while (map[x] && map[x + 1])
	{
		y = 0;
		while (map[x][y] && (int)ft_strlen(map[x]) > y)
		{
			if (ft_check_pos(vars->map->map, x, y))
			{
				if (map[x][y] == '2')
					vars->map->cnt_sprt++;
				y++;
			}
			else
				ft_put_error(vars, "ERROR\n Invalid Map 2\n");
		}
		x++;
	}
	vars->end_x_map = x;
}
