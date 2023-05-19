/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:21:42 by itrueba-          #+#    #+#             */
/*   Updated: 2023/04/06 12:24:19 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	ft_open_file(char *map_name, t_game *game)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		ft_error(game, "File can not be open", 1);
		close(fd);
	}
	return (fd);
}
