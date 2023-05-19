/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_radix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:28:17 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/10 12:18:49 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_counter(t_push *push)
{
	int	count;

	count = 0;
	while (push->stack_a)
	{
		if (push->total_size - push->size_a == push->stack_a->content)
			break ;
		push->stack_a = push->stack_a->next;
		count++;
	}
	push->stack_a = push->head_a;
	return (count);
}

void	ft_small_radix_pb(t_push *push, int counter)
{
	int	count;

	count = ft_counter(push);
	if (count != 0)
	{
		while (count != 0 && count != counter)
		{
			if (count <= counter / 2)
			{
				count--;
				ft_ra(push, 1);
			}
			if (count > counter / 2)
			{
				count++;
				ft_rra(push, 1);
			}
		}
	}
	ft_pb(push);
}

void	ft_radix_3(t_push *push)
{
	int	count;

	count = ft_counter(push);
	if (count == 1)
		ft_sa(push, 1);
	if (count == 2)
		ft_rra(push, 1);
	ft_correct_a(push);
	ft_pb(push);
	ft_sa(push, 1);
	ft_correct_a(push);
}

void	ft_small_radix(t_push *push)
{
	static int	counter;

	counter = push->total_size;
	if (push->total_size > 3)
	{
		while (counter > 3)
		{
			ft_small_radix_pb(push, counter);
			counter--;
		}
		ft_radix_3(push);
	}
	if (push->total_size == 3)
		ft_radix_3(push);
	if (push->total_size == 2)
		ft_sa(push, 1);
	ft_correct_a(push);
}
