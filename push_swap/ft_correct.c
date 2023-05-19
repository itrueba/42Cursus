/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_correct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:29:11 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/10 12:14:14 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_finish(t_push *push)
{
	t_list	*temp;

	while (push->stack_a)
	{
		temp = push->stack_a->next;
		free(push->stack_a);
		push->stack_a = temp;
	}
	free(push);
	exit(0);
}

void	ft_correct_b(t_push *push)
{
	int	counter;

	counter = push->stack_b->content;
	while (push->stack_b)
	{
		if (counter != push->stack_b->content)
		{
			push->stack_b = push->head_b;
			return ;
		}
		counter--;
		push->stack_b = push->stack_b->next;
	}
	push->stack_b = push->head_b;
	while (push->stack_b)
		ft_pa(push);
	ft_finish(push);
}

void	ft_correct_a(t_push *push)
{
	int	counter;

	counter = push->stack_a->content;
	while (push->stack_a)
	{
		if (counter != push->stack_a->content)
		{
			push->stack_a = push->head_a;
			return ;
		}
		counter++;
		push->stack_a = push->stack_a->next;
	}
	push->stack_a = push->head_a;
	if (push->size_a != push->total_size)
		ft_correct_b(push);
	else
		ft_finish(push);
}
