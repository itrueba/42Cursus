/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finishable_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 10:59:18 by itrueba-          #+#    #+#             */
/*   Updated: 2023/04/06 15:45:03 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_finishable_map(t_game *game, int x, int y, int *count)
{
	if (game->map_copy[x][y] == 'C' || game->map_copy[x][y] == 'E')
		(*count)++;
	if (game->map_copy[x][y] != '1' && game->map_copy[x][y] != 'X'
		&& game->map_copy[x][y])
	{
		game->map_copy[x][y] = '1';
		ft_finishable_map(game, x + 1, y, count);
		ft_finishable_map(game, x - 1, y, count);
		ft_finishable_map(game, x, y + 1, count);
		ft_finishable_map(game, x, y - 1, count);
	}
}
