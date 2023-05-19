/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:39:22 by itrueba-          #+#    #+#             */
/*   Updated: 2023/04/06 16:56:43 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_put_img(t_game *game, int x, int y, void *img)
{
	mlx_put_image_to_window(game->mlx, game->window, img, (y * 50), (x * 50));
}

void	ft_put_image(t_game *game, int x, int y)
{
	ft_put_img(game, x, y, game->img->floor);
	if (ft_equal(game, x, y, '1'))
		ft_put_img(game, x, y, game->img->wall);
	else if (ft_equal(game, x, y, '0'))
		ft_put_img(game, x, y, game->img->floor);
	else if (ft_equal(game, x, y, 'E'))
		ft_put_img(game, x, y, game->img->exit1);
	else if (ft_equal(game, x, y, 'C'))
		ft_put_img(game, x, y, game->img->collects);
	else if (ft_equal(game, x, y, 'P'))
	{
		if ((x + y) % 2 == 0)
			ft_put_img(game, x, y, game->img->player1);
		else
			ft_put_img(game, x, y, game->img->player2);
	}
	else if (ft_equal(game, x, y, 'X'))
		ft_put_img(game, x, y, game->img->demon1);
	ft_put_img(game, 0, 0, game->img->wall);
}

void	ft_paint_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			ft_put_image(game, x, y);
			y++;
		}
		x++;
	}
	game->map[game->p_x][game->p_y] = '0';
	game->map[game->e_x][game->e_y] = '0';
}
