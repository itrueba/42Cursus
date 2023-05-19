/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 10:59:18 by itrueba-          #+#    #+#             */
/*   Updated: 2023/04/06 14:01:25 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_info_checker(t_game *game)
{
	if (game->c == 0)
		ft_error(game, "Zero collectibles", 1);
	if (game->e != 1)
		ft_error(game, "Only one exit allowed", 1);
	if (game->p != 1)
		ft_error(game, "Only one starting position allowed", 1);
}
