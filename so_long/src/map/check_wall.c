/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 10:59:18 by itrueba-          #+#    #+#             */
/*   Updated: 2023/04/06 14:01:25 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_position(t_game *game, int x, int y)
{
	if (ft_equal(game, x, y, 'P'))
	{
		game->p_x = x;
		game->p_y = y;
	}
	if (ft_equal(game, x, y, 'E'))
	{
		game->e_x = x;
		game->e_y = y;
	}
}

void	ft_check_wall(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			ft_position(game, x, y);
			if (game->map[0][y] != '1' || game->map[game->line - 1][y] != '1')
				ft_error(game, "No walls around the edges", 1);
			if (game->map[x][0] != '1' || game->map[x][game->column - 1] != '1')
				ft_error(game, "No walls around the edges", 1);
			y++;
		}
		x++;
	}
}
