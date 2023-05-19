/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 10:52:01 by itrueba-          #+#    #+#             */
/*   Updated: 2023/04/06 11:51:12 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_game	*ft_init_game(t_game *game)
{
	game->img = malloc(sizeof(t_image));
	game->map = NULL;
	game->map_copy = NULL;
	game->mlx = NULL;
	game->line = 1;
	game->column = 0;
	game->p_x = 0;
	game->p_y = 0;
	game->e_x = 0;
	game->e_y = 0;
	game->c = 0;
	game->e = 0;
	game->p = 0;
	game->movements = 0;
	return (game);
}
