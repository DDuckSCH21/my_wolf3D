/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:09:11 by dduck             #+#    #+#             */
/*   Updated: 2021/04/12 13:09:12 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void	ft_get_dirplayer_part2(t_vars *vars, t_map *map)
{
	if (map->vector_eye == 'W')
	{
		vars->ray->dirx = 0;
		vars->ray->diry = -1;
		vars->ray->plnx = -0.66;
		vars->ray->planey = 0;
	}
	else if (map->vector_eye == 'E')
	{
		vars->ray->dirx = 0;
		vars->ray->diry = 1;
		vars->ray->plnx = 0.66;
		vars->ray->planey = 0;
	}
}

void		ft_get_dirplayer(t_vars *vars, t_map *map)
{
	if (map->vector_eye == 'N')
	{
		vars->ray->dirx = -1;
		vars->ray->diry = 0;
		vars->ray->plnx = 0;
		vars->ray->planey = 0.66;
	}
	else if (map->vector_eye == 'S')
	{
		vars->ray->dirx = 1;
		vars->ray->diry = 0;
		vars->ray->plnx = 0;
		vars->ray->planey = -0.66;
	}
	ft_get_dirplayer_part2(vars, map);
}

int			ft_parse_player(t_vars *vars, char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (ft_strchr("NSWE", map[x][y]))
			{
				vars->map->vector_eye = map[x][y];
				vars->map->count_spawn_player++;
				vars->map->pl_x = x + 1;
				vars->map->pl_y = y + 1;
			}
			y++;
		}
		x++;
	}
	if (vars->map->count_spawn_player != 1)
		ft_put_error(vars, "ERROR!\n Incorrect count spawn-point!\n");
	return (0);
}

int			ft_write_map(t_vars *vars, char *line, int i)
{
	if (i == 0)
		vars->map->map = ft_calloc(vars->cnfg->count_lines
				+ 1, sizeof(char *));
	if (line)
		vars->map->map[i] = ft_strdup(line);
	return (1);
}
