/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:09:46 by dduck             #+#    #+#             */
/*   Updated: 2021/04/12 13:09:48 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_key_press(int key, t_vars *vars)
{
	if (key == 13)
		vars->key->up = 1;
	if (key == 1)
		vars->key->down = 1;
	if (key == 2)
		vars->key->right = 1;
	if (key == 0)
		vars->key->left = 1;
	if (key == 124 && vars->key->rotat_left != 1)
		vars->key->rotat_right = 1;
	else if (key == 123 && vars->key->rotat_right != 1)
		vars->key->rotat_left = 1;
	if (key == 53)
		ft_game_over(vars);
	return (1);
}

int		ft_key_release(int key, t_vars *vars)
{
	if (key == 13)
		vars->key->up = 0;
	if (key == 1)
		vars->key->down = 0;
	if (key == 2)
		vars->key->right = 0;
	if (key == 0)
		vars->key->left = 0;
	if (key == 124)
		vars->key->rotat_right = 0;
	if (key == 123)
		vars->key->rotat_left = 0;
	if (key == 53)
		vars->key->esc = 0;
	return (1);
}

void	ft_turning(t_key *key, t_ray *ray)
{
	double old_dirx;
	double old_planex;

	old_dirx = ray->dirx;
	old_planex = ray->plnx;
	if (key->rotat_right)
	{
		ray->dirx = (ray->dirx * cos(-SPD_TR) - ray->diry * sin(-SPD_TR));
		ray->diry = (old_dirx * sin(-SPD_TR) + ray->diry * cos(-SPD_TR));
		ray->plnx = (ray->plnx * cos(-SPD_TR) - ray->planey * sin(-SPD_TR));
		ray->planey = (old_planex * sin(-SPD_TR) + ray->planey * cos(SPD_TR));
	}
	if (key->rotat_left)
	{
		ray->dirx = (ray->dirx * cos(SPD_TR) - ray->diry * sin(SPD_TR));
		ray->diry = (old_dirx * sin(SPD_TR) + ray->diry * cos(SPD_TR));
		ray->plnx = (ray->plnx * cos(SPD_TR) - ray->planey * sin(SPD_TR));
		ray->planey = (old_planex * sin(SPD_TR) + ray->planey * cos(SPD_TR));
	}
}

void	ft_move(t_ray *ray, t_vars *vars)
{
	if (vars->key->up)
	{
		if (vars->map->map[(int)(ray->psx + ray->dirx * SPMV)][(int)ray->psy]
			!= '1' && vars->map->map[(int)(ray->psx + ray->dirx * SPMV)]
			[(int)ray->psy] != '2')
			ray->psx += ray->dirx * SPMV;
		if (vars->map->map[(int)ray->psx][(int)(ray->psy + ray->diry * SPMV)]
			!= '1' && vars->map->map[(int)ray->psx]
			[(int)(ray->psy + ray->diry * SPMV)] != '2')
			ray->psy += ray->diry * SPMV;
	}
	if (vars->key->down)
	{
		if (vars->map->map[(int)(ray->psx - ray->dirx * SPMV)][(int)ray->psy]
			!= '1')
			ray->psx -= ray->dirx * SPMV;
		if (vars->map->map[(int)ray->psx][(int)(ray->psy - ray->diry * SPMV)]
			!= '1')
			ray->psy -= ray->diry * SPMV;
	}
}

void	ft_side(t_ray *ray, t_map *map, t_vars *vars)
{
	if (vars->key->left)
	{
		if (map->map[(int)(ray->psx)][(int)(ray->psy + ray->dirx * SPMV)]
			!= '1' && map->map[(int)(ray->psx)][(int)(ray->psy
			+ ray->dirx * SPMV)] != '2')
			ray->psy += ray->dirx * SPMV;
		if (map->map[(int)(ray->psx - ray->diry * SPMV)][(int)(ray->psy)]
			!= '1' && map->map[(int)(ray->psx - ray->diry * SPMV)]
			[(int)(ray->psy)] != '2')
			ray->psx -= ray->diry * SPMV;
	}
	if (vars->key->right)
	{
		if (map->map[(int)(ray->psx)][(int)(ray->psy - ray->dirx * SPMV)]
			!= '1' && map->map[(int)(ray->psx)][(int)(ray->psy
			- ray->dirx * SPMV)] != '2')
			ray->psy -= ray->dirx * SPMV;
		if (map->map[(int)(ray->psx + ray->diry * SPMV)][(int)(ray->psy)]
			!= '1' && map->map[(int)(ray->psx + ray->diry * SPMV)]
			[(int)(ray->psy)] != '2')
			ray->psx += ray->diry * SPMV;
	}
}
