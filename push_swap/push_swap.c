/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:30:53 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/28 13:39:50 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		*index;
	int		*input;
	t_push	*push;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		argc = ft_count_size(argv[1], ' ') + 1;
		if (argc == 1)
			return (0);
		argv = ft_split(argv[1], ' ');
		input = ft_check_argv(argc - 1, &argv[0]);
		ft_free_split(argv);
	}
	else
		input = ft_check_argv(argc - 1, &argv[1]);
	index = ft_index(argc - 1, input);
	push = ft_init_push(argc - 1);
	ft_init(index, push);
	ft_correct_a(push);
	if (push->total_size > 7)
		ft_radix(push, 0);
	ft_small_radix(push);
	return (0);
}
