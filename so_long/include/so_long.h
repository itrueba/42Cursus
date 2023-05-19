/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:47:45 by itrueba-          #+#    #+#             */
/*   Updated: 2023/04/06 16:54:39 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>

# define Q 12
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 0x35

# define AVATAR1 "textures/avatar1.xpm"
# define AVATAR2 "textures/avatar2.xpm"
# define AVATAR3 "textures/avatar3.xpm"
# define DEMON1 "textures/demon1.xpm"
# define DEMON2 "textures/demon2.xpm"
# define WALLS "textures/wall.xpm"
# define FLOORS "textures/floor.xpm"
# define EXIT1 "textures/exit1.xpm"
# define EXIT2 "textures/exit2.xpm"
# define COLLECT "textures/collect.xpm"
# define KILL 1
# define ORANGE 0xFE6500

typedef struct s_image
{
	void	*collects;
	void	*player1;
	void	*player2;
	void	*player3;
	void	*demon1;
	void	*demon2;
	void	*wall;
	void	*floor;
	void	*exit1;
	void	*exit2;
}			t_image;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	int		movements;
	t_image	*img;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		line;
	int		column;
	int		c;
	int		e;
	int		p;
	char	**map;
	char	**map_copy;
}			t_game;

void		ft_error(t_game *game, char *text, int error);
int			ft_open_file(char *map_name, t_game *game);

void		ft_name_check(char *map_name);
t_game		*ft_init_game(t_game *game);
void		ft_map_tester(char *map_name, t_game *game);
void		ft_star_game(t_game *game);

void		ft_check_wall(t_game *game);
void		ft_create_maps(char *map_name, t_game *game);
void		ft_finishable_map(t_game *game, int x, int y, int *count);
void		ft_info_checker(t_game *game);
void		ft_map_cheker(char *map_name, t_game *game);

void		ft_paint_map(t_game *game);
void		ft_get_xpm(t_game *game);
void		ft_hook(t_game *game);
void		ft_move(t_game *game, int x, int y);
void		ft_put_img(t_game *game, int x, int y, void *img);
int			ft_equal(t_game *game, int x, int y, char letter);
void		ft_destroy(t_game *game);
void		ft_write_moves(t_game *game);

#endif