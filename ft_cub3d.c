/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:22:52 by dduck             #+#    #+#             */
/*   Updated: 2021/04/09 14:22:57 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_check_fileconfig(t_vars *vars, char *argv)
{
	char *ptr;

	if (!(ptr = ft_strchr(argv, '.')) || ft_strncmp(ptr, ".cub", 4))
		ft_put_error(vars, "ERROR\n Format not *.cub!\n");
	if ((ft_get_count_sym(ptr, '.') != 1))
		ft_put_error(vars, "ERROR\n Too math format!(*.cub)\n");
	return (1);
}

int		ft_start_process(t_vars *vars)
{
	if (!(vars->mlx = mlx_init()))
		ft_put_error(vars, "ERROR\n Fail mlx_init\n");
	mlx_get_screen_size(&(vars->max_width), &(vars->max_hight));
	ft_get_line(vars);
	ft_check_processor(vars);
	ft_run_mlx(vars);
	return (1);
}

int		main(int argc, char **argv)
{
	t_vars		vars;
	t_config	config;
	t_key		key;
	t_map		map;

	vars.cnfg = &config;
	vars.map = &map;
	vars.key = &key;
	ft_init_all(&vars);
	if (argc == 2 || argc == 3)
	{
		if (argc == 3 && !ft_strncmp(argv[2], "--save", 7))
			vars.mode_save = 1;
		else if (argc == 3)
			ft_put_error(&vars, "ERROR\nIncorrect 2 argument\n");
	}
	else
		ft_put_error(&vars, "ERROR\nIncorrect number of arguments\n");
	ft_check_fileconfig(&vars, argv[1]);
	vars.filename_config = argv[1];
	ft_start_process(&vars);
	return (0);
}
