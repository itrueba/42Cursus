/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:41:47 by itrueba-          #+#    #+#             */
/*   Updated: 2023/01/17 11:59:28 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_order_input(int argc, int *input, int *order)
{
	int	count;

	count = 0;
	while (count < argc)
	{
		order[count] = input[count];
		count++;
	}
}

int	*ft_order(int argc, int *input)
{
	int	aux;
	int	x;
	int	y;
	int	*order;

	order = ft_calloc(sizeof(int), argc);
	ft_order_input(argc, input, order);
	x = 0;
	while (x < argc)
	{
		y = x;
		while (y < argc)
		{
			if (order[y] < order[x])
			{
				aux = order[y];
				order[y] = order[x];
				order[x] = aux;
			}
			y++;
		}
		x++;
	}
	return (order);
}

int	*ft_index(int argc, int *input)
{
	int	x;
	int	y;
	int	*order;
	int	*index;

	order = ft_order(argc, input);
	index = ft_calloc(sizeof(int), argc);
	x = 0;
	while (x < argc)
	{
		y = 0;
		while (y < argc)
		{
			if (input[x] == order[y])
				index[x] = y;
			y++;
		}
		x++;
	}
	free(input);
	free(order);
	return (index);
}
