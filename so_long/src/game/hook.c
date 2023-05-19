/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:51:14 by itrueba-          #+#    #+#             */
/*   Updated: 2023/04/11 18:04:57 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_destroy(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_image(game->mlx, game->img->collects);
	mlx_destroy_image(game->mlx, game->img->demon1);
	mlx_destroy_image(game->mlx, game->img->demon2);
	mlx_destroy_image(game->mlx, game->img->exit1);
	mlx_destroy_image(game->mlx, game->img->exit2);
	mlx_destroy_image(game->mlx, game->img->floor);
	mlx_destroy_image(game->mlx, game->img->player1);
	mlx_destroy_image(game->mlx, game->img->player2);
	mlx_destroy_image(game->mlx, game->img->player3);
	mlx_destroy_image(game->mlx, game->img->wall);
}

int	close_window(t_game *game)
{
	ft_error(game, "You close the window", 0);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == Q || keycode == ESC)
		ft_error(game, "You close the window", 0);
	else if (keycode == W)
		ft_move(game, -1, 0);
	else if (keycode == D)
		ft_move(game, 0, 1);
	else if (keycode == A)
		ft_move(game, 0, -1);
	else if (keycode == S)
		ft_move(game, 1, 0);
	return (0);
}

void	ft_hook(t_game *game)
{
	mlx_hook(game->window, 17, 1, close_window, game);
	mlx_hook(game->window, 2, 1, key_press, game);
}
