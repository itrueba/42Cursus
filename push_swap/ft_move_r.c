/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:22:48 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/10 08:27:36 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_push *push, int print)
{
	t_list	*first;

	first = push->stack_a;
	push->stack_a = push->stack_a->next;
	first->next = NULL;
	ft_lstadd_back(&push->stack_a, first);
	push->head_a = push->stack_a;
	if (print)
		write(1, "ra\n", 3);
}

void	ft_rb(t_push *push, int print)
{
	t_list	*first;

	first = push->stack_b;
	push->stack_b = push->stack_b->next;
	first->next = NULL;
	ft_lstadd_back(&push->stack_b, first);
	push->head_b = push->stack_b;
	if (print)
		write(1, "rb\n", 3);
}

void	ft_rr(t_push *push)
{
	ft_ra(push, 0);
	ft_rb(push, 0);
	write(1, "rr\n", 3);
}
