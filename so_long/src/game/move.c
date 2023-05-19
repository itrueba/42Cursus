/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:51:14 by itrueba-          #+#    #+#             */
/*   Updated: 2023/04/06 16:58:44 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_equal(t_game *game, int x, int y, char letter)
{
	if (game->map[x][y] == letter)
		return (1);
	return (0);
}

void	ft_write_moves(t_game *game)
{
	char	*nbr;

	nbr = ft_itoa(game->movements++);
	ft_putendl_fd(nbr, 1);
	ft_put_img(game, 0, 0, game->img->wall);
	ft_put_img(game, 50, 50, game->img->wall);
	mlx_string_put(game->mlx, game->window, 25, 25, ORANGE, nbr);
	mlx_string_put(game->mlx, game->window, 50, 25, ORANGE, "MOVES");
	free(nbr);
}

void	ft_walk(t_game *game, int x, int y)
{
	ft_write_moves(game);
	ft_put_img(game, game->p_x, game->p_y, game->img->floor);
	if (game->c == 0 && ft_equal(game, game->p_x, game->p_y, 'X'))
		ft_put_img(game, game->p_x, game->p_y, game->img->demon2);
	if (game->c == 0)
		ft_put_img(game, x, y, game->img->player3);
	else if ((x + y) % 2 == 0)
		ft_put_img(game, x, y, game->img->player1);
	else
		ft_put_img(game, x, y, game->img->player2);
	if (game->e_x == game->p_x && game->e_y == game->p_y)
		ft_put_img(game, game->e_x, game->e_y, game->img->exit1);
}

void	ft_chage_player(t_game *game, int x, int y)
{
	game->p_x = x;
	game->p_y = y;
	if (game->c == 0 && game->p_x == game->e_x && game->p_y == game->e_y)
		ft_error(game, "You Win", 0);
}

void	ft_move(t_game *game, int x, int y)
{
	x += game->p_x;
	y += game->p_y;
	if (ft_equal(game, x, y, '1'))
		return ;
	else if (ft_equal(game, x, y, '0'))
		ft_walk(game, x, y);
	else if (ft_equal(game, x, y, 'C'))
	{
		ft_put_img(game, x, y, game->img->floor);
		ft_walk(game, x, y);
		game->c--;
		game->map[x][y] = '0';
		if (game->c == 0)
		{
			ft_put_img(game, x, y, game->img->player3);
			ft_put_img(game, game->e_x, game->e_y, game->img->exit2);
		}
	}
	else if (ft_equal(game, x, y, 'X') && game->c == 0)
		ft_walk(game, x, y);
	else if (ft_equal(game, x, y, 'X'))
		ft_error(game, "You have die", 0);
	ft_chage_player(game, x, y);
}
