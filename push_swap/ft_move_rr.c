/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:22:48 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/10 08:27:21 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_push *push, int print)
{
	t_list	*pre_last;

	pre_last = ft_pre_lstlast(push->stack_a);
	ft_lstadd_front(&push->stack_a, pre_last->next);
	pre_last->next = NULL;
	push->head_a = push->stack_a;
	if (print)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_push *push, int print)
{
	t_list	*pre_last;

	pre_last = ft_pre_lstlast(push->stack_b);
	ft_lstadd_front(&push->stack_b, pre_last->next);
	pre_last->next = NULL;
	push->head_b = push->stack_b;
	if (print)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_push *push)
{
	ft_rra(push, 0);
	ft_rrb(push, 0);
	write(1, "rrr\n", 4);
}
