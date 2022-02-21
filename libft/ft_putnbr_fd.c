/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 12:30:02 by dduck             #+#    #+#             */
/*   Updated: 2020/11/21 12:58:44 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int i;

	if (fd < 0)
		return ;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		i = (unsigned int)(nb * (-1));
	}
	else
		i = (unsigned int)nb;
	if (i > 9)
		ft_putnbr_fd(i / 10, fd);
	ft_putchar_fd((char)(i % 10 + '0'), fd);
}
