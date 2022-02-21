/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 09:08:07 by dduck             #+#    #+#             */
/*   Updated: 2021/04/14 09:08:20 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_check_value_rgb(char *colorattach, t_vars *vars)
{
	while (ft_isspace(*colorattach))
		colorattach++;
	while (ft_isdigit(*colorattach))
		colorattach++;
	while (ft_isspace(*colorattach))
		colorattach++;
	if (*colorattach)
		ft_put_error(vars, "ERROR\n Incorrect value RGB\n");
}

void	ft_check_colorattach(t_vars *vars, char **colorattach)
{
	int i;
	int j;
	int r;

	i = 0;
	while (i < 3)
	{
		if (!colorattach[i])
			ft_put_error(vars, "ERROR\n Incorrect RGB(none)\n");
		ft_check_value_rgb(colorattach[i], vars);
		r = 0;
		j = 0;
		while (colorattach[i][j])
		{
			if (ft_isdigit(colorattach[i][j]))
				r++;
			j++;
		}
		if (r == 0)
			ft_put_error(vars, "ERROR\n Incorrect RGB\n");
		i++;
	}
}

int		ft_get_rgb(t_vars *vars, char **colorattach)
{
	int rgb;
	int r;
	int g;
	int b;

	r = ft_get_num(colorattach[0], 0, vars);
	g = ft_get_num(colorattach[1], 0, vars);
	b = ft_get_num(colorattach[2], 0, vars);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		ft_put_error(vars, "ERROR\n Invalid RGB(min 0, max 255)\n");
	rgb = r << 16 | g << 8 | b;
	return (rgb);
}
