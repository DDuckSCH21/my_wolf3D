/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:08:32 by dduck             #+#    #+#             */
/*   Updated: 2021/04/12 13:08:35 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_size_sprite(t_ray *ray, t_sprite *sprt, t_config *config)
{
	sprt->spr_h = abs((int)(config->res_h / sprt->trnsfrmy * ray->kf_res));
	sprt->drwsrty = (-(sprt->spr_h) / 2 + config->res_h / 2);
	if (sprt->drwsrty < 0)
		sprt->drwsrty = 0;
	sprt->drwndy = sprt->spr_h / 2 + config->res_h / 2;
	if (sprt->drwndy > config->res_h)
		sprt->drwndy = config->res_h - 1;
	sprt->spr_w = abs((int)(config->res_h / sprt->trnsfrmy * ray->kf_res));
	sprt->drwsrtx = -sprt->spr_w / 2 + sprt->sprscrnx;
	if (sprt->drwsrtx < 0)
		sprt->drwsrtx = 0;
	sprt->drwndx = sprt->spr_w / 2 + sprt->sprscrnx;
	if (sprt->drwndx > config->res_w)
		sprt->drwndx = config->res_w - 1;
}

void	ft_get_dist_sprites(t_ray *ray, t_vars *vars)
{
	int			i;
	t_sprite	*sprt;

	i = 0;
	while (i <= vars->map->cnt_sprt - 1)
	{
		sprt = vars->arspr[i];
		sprt->dist = ((ray->psx - sprt->smapx) * (ray->psx - sprt->smapx) +
			(ray->psy - sprt->smapy) * (ray->psy - sprt->smapy));
		i++;
	}
}

void	ft_get_params_sprite(int x, int y, int i, t_vars *vars)
{
	t_sprite	*sprt;

	if (i == 0)
		vars->arspr = ft_calloc(vars->map->cnt_sprt + 1, sizeof(t_sprite));
	vars->arspr[i] = ft_calloc(vars->map->cnt_sprt + 1, sizeof(t_sprite));
	sprt = vars->arspr[i];
	*sprt = (t_sprite){.smapx = (double)x, .smapy = (double)y};
}

void	ft_get_sprites(t_vars *vars, char **map)
{
	int x;
	int y;
	int i;

	x = 0;
	i = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == '2')
			{
				ft_get_params_sprite(x, y, i, vars);
				i++;
			}
			y++;
		}
		x++;
	}
}

int		ft_main_draw_sprite(t_vars *vars)
{
	ft_get_dist_sprites(vars->ray, vars);
	ft_sort_sprite(vars);
	ft_draw_sprite(vars->ray, vars);
	return (1);
}
