/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:09:23 by dduck             #+#    #+#             */
/*   Updated: 2021/04/12 13:09:25 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_get_char(unsigned char *c, int i)
{
	c[0] = (unsigned char)(i);
	c[1] = (unsigned char)(i >> 8);
	c[2] = (unsigned char)(i >> 16);
	c[3] = (unsigned char)(i >> 24);
}

void	ft_header_bmp(int fd, int hight, int width, int size)
{
	unsigned char	header[54];
	int				filesize;

	filesize = 54 + (width * 3 * hight) + (size * hight);
	ft_bzero(header, 54);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	ft_get_char(header + 2, filesize);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	ft_get_char(header + 18, width);
	ft_get_char(header + 22, hight);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(24);
	write(fd, header, 54);
}

int		ft_create_bmp(int fd, t_vars *vars, int size)
{
	unsigned char	data[3];
	int				x;
	int				y;
	int				pixel;
	char			*dst;

	y = vars->cnfg->res_h - 1;
	ft_bzero(data, 3);
	while (y >= 0)
	{
		x = 0;
		while (x < vars->cnfg->res_w)
		{
			dst = vars->addr + (y * vars->line_len + x * (vars->bpp / 8));
			pixel = *(int*)dst;
			if (write(fd, &pixel, 3) < 0)
				return (0);
			x++;
		}
		if (size > 0 && write(fd, &data, size) < 0)
			return (0);
		y--;
	}
	return (1);
}

int		ft_screen(t_vars *vars)
{
	int	size;
	int	fd;

	ft_play_game(vars);
	size = (4 - ((int)vars->cnfg->res_w * 3) % 4) % 4;
	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT, 0777 | O_TRUNC
		| O_APPEND)) < 0)
		return (0);
	ft_header_bmp(fd, vars->cnfg->res_h, vars->cnfg->res_w, size);
	ft_create_bmp(fd, vars, size);
	close(fd);
	ft_game_over(vars);
	return (1);
}
