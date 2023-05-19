/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:22:48 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/10 08:35:47 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_push *push)
{
	t_list	*new;

	new = push->stack_b;
	push->stack_b = push->stack_b->next;
	new->next = NULL;
	ft_lstadd_front(&push->stack_a, new);
	push->size_b--;
	push->size_a++;
	push->head_a = new;
	push->head_b = push->stack_b;
	write(1, "pa\n", 3);
}

void	ft_pb(t_push *push)
{
	t_list	*new;

	new = push->stack_a;
	push->stack_a = push->stack_a->next;
	new->next = NULL;
	ft_lstadd_front(&push->stack_b, new);
	push->size_a--;
	push->size_b++;
	push->head_a = push->stack_a;
	push->head_b = new;
	write(1, "pb\n", 3);
}
