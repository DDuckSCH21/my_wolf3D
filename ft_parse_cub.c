/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:10:01 by dduck             #+#    #+#             */
/*   Updated: 2021/04/12 13:10:04 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_get_color(t_vars *vars, char *line, char **colorattach, int flag)
{
	int	rgb;
	int i;

	i = -1;
	if (flag == 2 && vars->cnfg->color_f_rgb != -1)
		ft_put_error(vars, "ERROR\n Too match string Floor RGB\n");
	if (flag == 1 && vars->cnfg->color_c_rgb != -1)
		ft_put_error(vars, "ERROR\n Too match string Ceiling RGB\n");
	if (ft_get_count_sym(line, ',') != 2)
		ft_put_error(vars, "ERROR\n Incorrect RGB!\n");
	while (ft_isspace(*line))
		line++;
	colorattach = ft_split(line, ',');
	ft_check_colorattach(vars, colorattach);
	rgb = ft_get_rgb(vars, colorattach);
	while (colorattach[++i])
		free(colorattach[i]);
	free(colorattach);
	return (rgb);
}

char	*ft_parse_textures(t_vars *vars, char *line, int i)
{
	char	*ptr;
	t_image	*img;

	img = &vars->artxt[i];
	while (ft_isspace(*line))
		line++;
	if (!(ptr = ft_strchr(line + 1, '.')) || ft_strncmp(ptr, ".xpm", 5))
		ft_put_error(vars, "ERROR\nThe file has no format!(*.xpm)\n");
	if (img->txt_path != NULL)
		ft_put_error(vars, "ERROR\nToo match textures!\n");
	while (ft_isspace(*line))
		line++;
	img->txt_path = ft_strdup(line);
	if (!(img->ptr = mlx_xpm_file_to_image(vars->mlx, img->txt_path,
		&img->img_w, &img->img_h)))
		ft_put_error(vars, "ERROR\nFail mlx_xpm_file_to_image!\n");
	if (img->img_w != img->img_h)
		ft_put_error(vars, "ERROR\nTexture not kvadred!\n");
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->line_len,
		&img->end);
	return (img->txt_path);
}

int		ft_get_resolution(t_vars *vars, char *line)
{
	int i;

	while (ft_isspace(*line))
		line++;
	if (!vars->cnfg->res_w)
	{
		i = ft_get_num(&(*line), 0, vars);
		vars->cnfg->res_w = i;
	}
	while (ft_isdigit(*line))
		line++;
	if (!vars->cnfg->res_h && vars->cnfg->res_w)
	{
		i = ft_get_num(&(*line), 1, vars);
		vars->cnfg->res_h = i;
	}
	else if (vars->cnfg->res_h && vars->cnfg->res_w)
		ft_put_error(vars, "ERROR\n Too match R-string\n");
	return (0);
}

int		ft_config_processor(t_vars *vars, char *line)
{
	while (ft_isspace(*line))
		line++;
	if (!(ft_strncmp(line, "R ", 2)))
		ft_get_resolution(vars, line + 1);
	else if (!(ft_strncmp(line, "NO ", 3)))
		vars->artxt[0].txt_path = ft_parse_textures(vars, line + 2, 0);
	else if (!(ft_strncmp(line, "SO ", 3)))
		vars->artxt[1].txt_path = ft_parse_textures(vars, line + 2, 1);
	else if (!(ft_strncmp(line, "WE ", 3)))
		vars->artxt[2].txt_path = ft_parse_textures(vars, line + 2, 2);
	else if (!(ft_strncmp(line, "EA ", 3)))
		vars->artxt[3].txt_path = ft_parse_textures(vars, line + 2, 3);
	else if (!(ft_strncmp(line, "S ", 2)))
		vars->artxt[4].txt_path = ft_parse_textures(vars, line + 2, 4);
	else if (!(ft_strncmp(line, "C ", 2)))
		vars->cnfg->color_c_rgb = ft_get_color(vars, line + 1,
			vars->cnfg->color_c, 1);
	else if (!(ft_strncmp(line, "F ", 2)))
		vars->cnfg->color_f_rgb = ft_get_color(vars, line + 1,
			vars->cnfg->color_f, 2);
	else if (*line == '\n' || *line == '\0')
		vars->spr_d += 0;
	else
		ft_put_error(vars, "ERROR\n Incorrect config O_o!\n");
	return (0);
}

int		ft_get_line(t_vars *vars)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	if ((fd = open(vars->filename_config, O_RDONLY)) < 0)
		ft_put_error(vars, "ERROR\n Fail OPEN FD\n");
	ft_check_null_config(fd, line, vars);
	close(fd);
	fd = open(vars->filename_config, O_RDONLY);
	while ((get_next_line(fd, &line)))
	{
		ft_check_config(vars);
		if (vars->cnfg->flag_done == 1 && (ft_strstrchr(line, MAP_SYM) > 0))
			ft_write_map(vars, line, i++);
		else
			ft_config_processor(vars, line);
		free(line);
	}
	if (!(ft_write_map(vars, line, i)) && vars->cnfg->flag_done != 1)
		ft_put_error(vars, "ERROR\n Not enough parameters!\n");
	free(line);
	close(fd);
	return (0);
}
