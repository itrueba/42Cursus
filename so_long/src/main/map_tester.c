/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tester.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 10:59:18 by itrueba-          #+#    #+#             */
/*   Updated: 2023/04/06 14:01:25 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_map_tester(char *map_name, t_game *game)
{
	int	count;

	count = 0;
	ft_map_cheker(map_name, game);
	ft_info_checker(game);
	ft_create_maps(map_name, game);
	ft_check_wall(game);
	ft_finishable_map(game, game->p_x, game->p_y, &count);
	if (count != game->c + 1)
		ft_error(game, "Impossible to finish", 1);
}
