/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:08:53 by dduck             #+#    #+#             */
/*   Updated: 2021/04/12 13:08:55 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_putpixel_utils(t_sprite *sprt, t_vars *vars)
{
	int color;

	vars->spr_d = sprt->dry * 256 - vars->cnfg->res_h * 128 + sprt->spr_h * 128;
	sprt->stex_y = ((vars->spr_d * vars->artxt[4].img_h) / sprt->spr_h) / 256;
	color = ft_get_pixel(sprt->stex_x, sprt->stex_y, vars->artxt[4]);
	if (color)
		my_mlx_puxel_put(vars, sprt->drx, sprt->dry, color);
	sprt->dry++;
}

void	ft_putpixel_sprite(t_vars *vars, t_ray *ray, t_sprite *sprt)
{
	sprt->drx = sprt->drwsrtx;
	while (sprt->drx < sprt->drwndx)
	{
		sprt->stex_x = (int)(((sprt->drx - (-sprt->spr_w / 2 + sprt->sprscrnx))
				* vars->artxt[4].img_w / sprt->spr_w));
		sprt->dry = sprt->drwsrty;
		if (sprt->trnsfrmy > 0 && sprt->drx > 0 && sprt->drx < vars->cnfg->res_w
			&& sprt->trnsfrmy < ray->zbuff[sprt->drx])
		{
			while (sprt->dry < sprt->drwndy)
				ft_putpixel_utils(sprt, vars);
		}
		sprt->drx++;
	}
}

void	ft_sort_sprite(t_vars *vars)
{
	int			i;
	t_sprite	*temp;

	i = 0;
	if (vars->map->cnt_sprt > 1)
	{
		while (i < vars->map->cnt_sprt - 1)
		{
			if (vars->arspr[i]->dist < vars->arspr[i + 1]->dist)
			{
				temp = vars->arspr[i];
				vars->arspr[i] = vars->arspr[i + 1];
				vars->arspr[i + 1] = temp;
				i = 0;
			}
			i++;
		}
	}
}

void	ft_draw_sprite(t_ray *ray, t_vars *vars)
{
	int			i;
	t_sprite	*sprt;

	i = 0;
	while (i < vars->map->cnt_sprt)
	{
		sprt = vars->arspr[i];
		sprt->sposx = sprt->smapx - ray->psx + 0.5;
		sprt->sposy = sprt->smapy - ray->psy + 0.5;
		sprt->invdet = 1.0 / (ray->plnx * ray->diry - ray->planey * ray->dirx);
		sprt->trnsfrmx = sprt->invdet * (ray->diry * sprt->sposx
				- ray->dirx * sprt->sposy);
		sprt->trnsfrmy = sprt->invdet * (-ray->planey * sprt->sposx
				+ ray->plnx * sprt->sposy);
		sprt->sprscrnx = (int)((vars->cnfg->res_w / 2)
				* (1 + sprt->trnsfrmx / sprt->trnsfrmy));
		ft_size_sprite(vars->ray, sprt, vars->cnfg);
		ft_putpixel_sprite(vars, vars->ray, sprt);
		i++;
	}
}
