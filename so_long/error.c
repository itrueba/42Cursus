/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 09:27:42 by itrueba-          #+#    #+#             */
/*   Updated: 2023/04/06 17:01:23 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	ft_free_split(t_game *game)
{
	int	x;

	x = 0;
	while (game->map[x])
	{
		free(game->map[x]);
		free(game->map_copy[x]);
		x++;
	}
	free(game->map);
	free(game->map_copy);
}

void	ft_free(t_game *game)
{
	if (game)
	{
		if (game->map)
			ft_free_split(game);
		if (game->mlx)
			free(game->mlx);
		free(game->img);
		free(game);
	}
}

void	ft_error(t_game *game, char *text, int error)
{
	if (error)
		ft_putendl_fd("Error", 1);
	else
		ft_destroy(game);
	ft_free(game);
	ft_putendl_fd(text, 1);
	exit(0);
}
