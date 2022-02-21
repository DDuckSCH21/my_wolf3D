/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:09:33 by dduck             #+#    #+#             */
/*   Updated: 2021/04/12 13:09:37 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_get_side_wall(t_ray *ray)
{
	if ((ray->rdrx <= 0 && ray->rdry >= 0 && ray->side == 1)
	|| (ray->rdrx >= 0 && ray->rdry >= 0 && ray->side == 1))
		return (2);
	else if ((ray->rdrx <= 0 && ray->rdry >= 0 && ray->side == 0)
	|| (ray->rdrx <= 0 && ray->rdry <= 0 && ray->side == 0))
		return (1);
	else if ((ray->rdrx <= 0 && ray->rdry <= 0 && ray->side == 1)
	|| (ray->rdrx >= 0 && ray->rdry <= 0 && ray->side == 1))
		return (3);
	else
		return (0);
}

void	ft_ray_dda(t_vars *vars, t_ray *ray)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stpx;
			ray->side = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stpy;
			ray->side = 1;
		}
		if (vars->map->map[ray->mapx][ray->mapy] == '1')
			hit = 1;
	}
}

void	ft_ray_get_pos(t_vars *vars, t_ray *ray)
{
	ray->camerax = 2 * ray->x / (double)vars->cnfg->res_w - 1;
	ray->rdrx = ray->dirx + ray->plnx * ray->camerax;
	ray->rdry = ray->diry + ray->planey * ray->camerax;
	ray->mapx = (int)ray->psx;
	ray->mapy = (int)ray->psy;
	ray->deltadistx = fabs(1 / ray->rdrx);
	ray->deltadisty = fabs(1 / ray->rdry);
}

void	ft_ray_get_step(t_ray *ray)
{
	if (ray->rdrx < 0)
	{
		ray->stpx = -1;
		ray->sidedistx = (ray->psx - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stpx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - ray->psx) * ray->deltadistx;
	}
	if (ray->rdry < 0)
	{
		ray->stpy = -1;
		ray->sidedisty = (ray->psy - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stpy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - ray->psy) * ray->deltadisty;
	}
}

int		ft_run_game(t_ray *ray, t_vars *vars)
{
	int i_tex;
	int lineheight;

	ft_ray_get_pos(vars, ray);
	ft_ray_get_step(ray);
	ft_ray_dda(vars, ray);
	i_tex = ft_get_side_wall(vars->ray);
	if (ray->side == 0)
		ray->pwlld = (ray->mapx - ray->psx + (1.0 - ray->stpx) / 2) / ray->rdrx;
	else
		ray->pwlld = (ray->mapy - ray->psy + (1.0 - ray->stpy) / 2) / ray->rdry;
	ray->zbuff[ray->x] = ray->pwlld;
	lineheight = (int)((vars->cnfg->res_h / ray->pwlld) * (vars->ray->kf_res));
	ray->drwstrt = -lineheight / 2 + vars->cnfg->res_h / 2;
	if (ray->drwstrt < 0)
		ray->drwstrt = 0;
	ray->drwnd = lineheight / 2 + vars->cnfg->res_h / 2;
	if (ray->drwnd >= vars->cnfg->res_h)
		ray->drwnd = vars->cnfg->res_h - 1;
	ray->step = 1.0 * vars->artxt[i_tex].img_h / lineheight;
	ft_draw_line(vars, vars->ray, lineheight, i_tex);
	return (0);
}
