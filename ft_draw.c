/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:08:05 by dduck             #+#    #+#             */
/*   Updated: 2021/04/12 13:08:07 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_get_pixel(int width, int hight, t_image img)
{
	unsigned int	color;
	char			*dst;

	dst = img.addr + (hight * img.line_len + width * (img.bpp / 8));
	color = *(unsigned int*)dst;
	return ((int)color);
}

void	ft_get_wall_x(t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_x = ray->psy + ray->pwlld * ray->rdry;
	else
		ray->wall_x = ray->psx + ray->pwlld * ray->rdrx;
	ray->wall_x -= floor(ray->wall_x);
}

double	ft_get_tex_x(t_ray *ray, t_image img)
{
	double	tex_x;

	tex_x = (int)(ray->wall_x * img.img_w);
	if (ray->side == 0 && ray->rdrx > 0)
		tex_x = ((double)img.img_w) - tex_x - 1;
	if (ray->side == 1 && ray->rdry < 0)
		tex_x = ((double)img.img_w) - tex_x - 1;
	return (tex_x);
}

void	ft_draw_line(t_vars *vars, t_ray *ray, int linehght, int i_tex)
{
	int		i;
	double	tex_x;
	int		tex_y;
	int		color;

	i = -1;
	ft_get_wall_x(vars->ray);
	tex_x = ft_get_tex_x(vars->ray, vars->artxt[i_tex]);
	vars->pos = (ray->drwstrt - (double)(vars->cnfg->res_h / 2
			+ linehght / 2)) * ray->step;
	while (++i < ray->drwstrt)
		my_mlx_puxel_put(vars, ray->x, i, vars->cnfg->color_c_rgb);
	while (ray->drwstrt <= ray->drwnd && ray->x < vars->cnfg->res_w)
	{
		tex_y = (int)vars->pos & (vars->artxt[i_tex].img_h - 1);
		color = ft_get_pixel(tex_x, tex_y, vars->artxt[i_tex]);
		my_mlx_puxel_put(vars, ray->x, ray->drwstrt, color);
		vars->pos += ray->step;
		ray->drwstrt++;
	}
	ray->drwstrt--;
	while (++ray->drwstrt < vars->cnfg->res_h)
		my_mlx_puxel_put(vars, ray->x, ray->drwstrt, vars->cnfg->color_f_rgb);
}
