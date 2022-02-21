/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:07:53 by dduck             #+#    #+#             */
/*   Updated: 2021/04/12 13:07:57 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_go(t_vars *vars)
{
	ft_turning(vars->key, vars->ray);
	ft_side(vars->ray, vars->map, vars);
	ft_move(vars->ray, vars);
}

int		ft_play_game(t_vars *vars)
{
	ft_go(vars);
	if (vars->img)
		mlx_destroy_image(vars->mlx, vars->img);
	vars->img = mlx_new_image(vars->mlx, vars->cnfg->res_w, vars->cnfg->res_h);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bpp, &vars->line_len,
								&vars->end);
	while (vars->ray->x < vars->cnfg->res_w)
	{
		ft_run_game(vars->ray, vars);
		vars->ray->x++;
	}
	vars->ray->x = 0;
	ft_main_draw_sprite(vars);
	if (vars->flag_frst == 0)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	}
	return (1);
}

int		ft_run_mlx(t_vars *vars)
{
	t_ray ray;

	vars->ray = &ray;
	ft_init_ray(&ray, vars);
	ft_get_dirplayer(vars, vars->map);
	ft_get_sprites(vars, vars->map->map);
	if (vars->mode_save == 1)
		ft_screen(vars);
	if (!(vars->win = mlx_new_window(vars->mlx, vars->cnfg->res_w,
		vars->cnfg->res_h, "cub3d")))
		ft_put_error(vars, "ERROR\n mlx_new_window fail\n");
	vars->flag_frst = 0;
	mlx_hook(vars->win, 2, 1, ft_key_press, vars);
	mlx_key_hook(vars->win, ft_key_release, (void *)vars);
	mlx_hook(vars->win, 17, 1, ft_game_over, vars);
	mlx_loop_hook(vars->mlx, ft_play_game, vars);
	mlx_loop(vars->mlx);
	return (1);
}
