/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:07:06 by dduck             #+#    #+#             */
/*   Updated: 2021/04/12 13:07:15 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int	ft_game_over(t_vars *vars)
{
	vars->spr_d += 0;
	write(1, "GAME OVER!\n", 11);
	exit(EXIT_SUCCESS);
}
