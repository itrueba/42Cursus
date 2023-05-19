/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_maps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 10:59:18 by itrueba-          #+#    #+#             */
/*   Updated: 2023/04/06 12:23:37 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_create_maps(char *map_name, t_game *game)
{
	int		fd;
	char	*buffer;
	int		buffer_size;

	fd = ft_open_file(map_name, game);
	buffer_size = game->column * game->line + game->line - 1;
	buffer = malloc(buffer_size);
	read(fd, buffer, buffer_size);
	game->map = ft_split(buffer, '\n');
	game->map_copy = ft_split(buffer, '\n');
	free(buffer);
	close(fd);
}
