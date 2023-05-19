/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cheker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 10:59:18 by itrueba-          #+#    #+#             */
/*   Updated: 2023/04/06 14:01:25 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_gap_checker(t_game *game, char gap)
{
	if (gap == 'C')
		game->c++;
	else if (gap == 'E')
		game->e++;
	else if (gap == 'P')
		game->p++;
	else if (gap == 'X')
		return ;
	else if (gap != '0' && gap != '1')
		ft_error(game, "Element not allowed", 1);
}

void	ft_check_column(t_game *game, int column, char *buffer, int *fd)
{
	if (game->column == 0)
		game->column = column;
	if (game->column != column)
	{
		free(buffer);
		close(*fd);
		ft_error(game, "Uneven columns", 1);
	}
}

void	ft_first(t_game *game, char *buffer, int *fd)
{
	free(buffer);
	close(*fd);
	ft_error(game, "Element not allowed", 1);
}

void	ft_map_cheker(char *map_name, t_game *game)
{
	int		fd;
	char	*buffer;
	int		column;

	fd = ft_open_file(map_name, game);
	buffer = malloc(1);
	column = 0;
	while (read(fd, buffer, 1))
	{
		if (*buffer == '\n')
		{
			if (column == 0)
				ft_first(game, buffer, &fd);
			ft_check_column(game, column, buffer, &fd);
			game->line++;
			column = 0;
			read(fd, buffer, 1);
		}
		column++;
		ft_gap_checker(game, *buffer);
	}
	free(buffer);
	close(fd);
}
