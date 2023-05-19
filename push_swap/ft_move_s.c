/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:22:48 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/10 08:27:08 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_push *push, int print)
{
	int	aux;

	aux = push->stack_a->content;
	push->stack_a->content = push->stack_a->next->content;
	push->stack_a->next->content = aux;
	if (print)
		write(1, "sa\n", 3);
}

void	ft_sb(t_push *push, int print)
{
	t_list	*aux;

	aux = push->stack_b->next;
	push->stack_b->next = push->stack_b->next->next;
	push->stack_b->next->next = aux;
	if (print)
		write(1, "sb\n", 3);
}

void	ft_ss(t_push *push)
{
	ft_sa(push, 0);
	ft_sb(push, 0);
	write(1, "ss\n", 3);
}
