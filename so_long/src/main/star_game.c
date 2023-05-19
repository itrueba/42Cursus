/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 10:42:14 by itrueba-          #+#    #+#             */
/*   Updated: 2023/04/06 16:55:40 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_star_game(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, (int)game->column * 50,
			(int)game->line * 50, "So Long!");
	ft_get_xpm(game);
	ft_paint_map(game);
	ft_hook(game);
	ft_write_moves(game);
	mlx_loop(game->mlx);
}
