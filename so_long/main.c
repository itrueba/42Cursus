/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:55:57 by itrueba-          #+#    #+#             */
/*   Updated: 2023/04/06 14:01:03 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		game = malloc(sizeof(t_game));
		if (!game)
			ft_error(game, "Malloc failed", 1);
		ft_name_check(argv[1]);
		ft_init_game(game);
		ft_map_tester(argv[1], game);
		ft_star_game(game);
	}
	return (0);
}
