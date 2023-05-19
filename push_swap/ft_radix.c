/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:09:34 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/09 11:46:19 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_radix_a(t_push *push, int bit)
{
	int	size;
	int	sa;

	sa = push->size_a;
	size = 0;
	while (size++ < sa)
	{
		if (((push->stack_a->content) >> bit & 1) == 0)
		{
			ft_correct_a(push);
			ft_pb(push);
		}			
		else
			ft_ra(push, 1);
	}
}

void	ft_radix_b(t_push *push, int bit)
{
	int	size;
	int	sb;

	sb = push->size_b;
	size = 0;
	while (size++ < sb)
	{
		if (((push->stack_b->content) >> bit & 1) == 0 && bit < push->bit_size)
			ft_rb(push, 1);
		else
			ft_pa(push);
	}
}

void	ft_radix(t_push *push, int bit)
{
	ft_radix_a(push, bit);
	ft_correct_a(push);
	ft_radix_b(push, bit + 1);
	if (bit < push->bit_size)
	{
		bit++;
		ft_radix(push, bit);
	}
}
