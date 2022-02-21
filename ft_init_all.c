/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:07:40 by dduck             #+#    #+#             */
/*   Updated: 2021/04/12 13:07:44 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_init_config_map_key(t_config *config, t_map *map, t_key *key)
{
	config->res_w = 0;
	config->res_h = 0;
	config->flag_done = 0;
	config->count_lines = 0;
	config->color_c = NULL;
	config->color_f = NULL;
	config->color_c_rgb = -1;
	config->color_f_rgb = -1;
	map->vector_eye = 0;
	map->cnt_sprt = 0;
	map->count_spawn_player = 0;
	map->pl_x = 0;
	map->pl_y = 0;
	key->up = 0;
	key->down = 0;
	key->right = 0;
	key->left = 0;
	key->rotat_left = 0;
	key->rotat_right = 0;
	key->esc = 0;
}

void	ft_init_all(t_vars *vars)
{
	int i;

	i = 0;
	while (i < 5)
	{
		vars->artxt[i].txt_path = NULL;
		i++;
	}
	vars->mode_save = 0;
	vars->img = NULL;
	vars->flag_frst = 1;
	ft_init_config_map_key(vars->cnfg, vars->map, vars->key);
}

void	ft_init_ray(t_ray *ray, t_vars *vars)
{
	ray->x = 0;
	ray->dirx = 0;
	ray->diry = 0;
	ray->mapx = 0;
	ray->mapy = 0;
	ray->stpx = 0;
	ray->stpy = 0;
	ray->side = 0;
	ray->camerax = 0.0;
	ray->rdrx = 0.0;
	ray->rdry = 0.0;
	ray->sidedistx = 0.0;
	ray->sidedisty = 0.0;
	ray->deltadistx = 0.0;
	ray->deltadisty = 0.0;
	ray->pwlld = 0.0;
	ray->psx = (double)vars->map->pl_x - 0.5;
	ray->psy = (double)vars->map->pl_y - 0.5;
	vars->ray->kf_res = ((double)vars->cnfg->res_w / (double)vars->cnfg->res_h
		* 0.75);
}
