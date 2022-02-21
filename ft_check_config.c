/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:13:12 by dduck             #+#    #+#             */
/*   Updated: 2021/04/09 14:13:19 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_check_null_config(int fd, char *line, t_vars *vars)
{
	vars->cnfg->count_lines = ft_count_lines(fd, line, vars);
	if (vars->cnfg->count_lines <= 0)
		ft_put_error(vars, "ERROR\n Config not complect!\n");
}

int		ft_check_config(t_vars *vars)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (i < 5)
	{
		if (!(vars->artxt[i].txt_path))
			break ;
		i++;
	}
	vars->cnfg->res_h ? flag++ : flag + 0;
	vars->cnfg->res_w ? flag++ : flag + 0;
	if (vars->cnfg->color_c_rgb >= 0)
		flag++;
	if (vars->cnfg->color_f_rgb >= 0)
		flag++;
	if (flag + i == 9)
		vars->cnfg->flag_done = 1;
	return (0);
}

void	ft_check_resolution(t_vars *vars)
{
	if (vars->cnfg->res_w > vars->max_width)
		vars->cnfg->res_w = vars->max_width;
	if (vars->cnfg->res_h > vars->max_hight)
		vars->cnfg->res_h = vars->max_hight;
}

void	ft_check_processor(t_vars *vars)
{
	ft_check_resolution(vars);
	ft_check_map(vars, vars->map->map);
	ft_parse_player(vars, vars->map->map);
	ft_check_map_endline(vars, vars->map->map);
}
