/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xpm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:39:22 by itrueba-          #+#    #+#             */
/*   Updated: 2023/04/06 16:23:40 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_xpm_checker(t_game *game)
{
	if (!game->img->player1 || !game->img->player2 || !game->img->player3
		|| !game->img->wall || !game->img->floor || !game->img->exit1
		|| !game->img->exit2 || !game->img->collects || !game->img->demon1
		|| !game->img->demon2)
		ft_error(game, "Textures not found", 1);
}

void	ft_get_xpm(t_game *game)
{
	int	x;
	int	y;

	game->img->player1 = mlx_xpm_file_to_image(game->mlx, AVATAR1, &(x), &(y));
	game->img->player2 = mlx_xpm_file_to_image(game->mlx, AVATAR2, &(x), &(y));
	game->img->player3 = mlx_xpm_file_to_image(game->mlx, AVATAR3, &(x), &(y));
	game->img->demon1 = mlx_xpm_file_to_image(game->mlx, DEMON1, &(x), &(y));
	game->img->demon2 = mlx_xpm_file_to_image(game->mlx, DEMON2, &(x), &(y));
	game->img->wall = mlx_xpm_file_to_image(game->mlx, WALLS, &(x), &(y));
	game->img->floor = mlx_xpm_file_to_image(game->mlx, FLOORS, &(x), &(y));
	game->img->exit1 = mlx_xpm_file_to_image(game->mlx, EXIT1, &(x), &(y));
	game->img->exit2 = mlx_xpm_file_to_image(game->mlx, EXIT2, &(x), &(y));
	game->img->collects = mlx_xpm_file_to_image(game->mlx, COLLECT, &(x), &(y));
	ft_xpm_checker(game);
}
