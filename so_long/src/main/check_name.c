/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 10:52:01 by itrueba-          #+#    #+#             */
/*   Updated: 2023/04/06 14:01:25 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_name_check(char *map_name)
{
	char	*ber1;
	char	*ber2;

	ber1 = ".ber";
	ber2 = ft_strrchr(map_name, '.');
	if (ft_strlen(map_name) <= 4 || !ber2 || ft_strncmp(ber1, ber2, 4))
		ft_error(NULL, "Incorrect name", 1);
}
