/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:11:54 by itrueba-          #+#    #+#             */
/*   Updated: 2023/02/10 08:35:37 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push	*ft_init_push(int argc)
{
	t_push	*push;

	push = malloc(sizeof(t_push));
	push->stack_a = NULL;
	push->stack_b = NULL;
	push->size_a = argc;
	push->size_b = 0;
	push->total_size = argc;
	push->bit_size = argc >> 1;
	push->head_b = NULL;
	return (push);
}

void	ft_init(int *index, t_push *push)
{
	t_list	*new;
	int		count;

	count = 0;
	while (count < push->size_a)
	{
		new = ft_lstnew(index[count]);
		ft_lstadd_back(&push->stack_a, new);
		count++;
	}
	push->head_a = push->stack_a;
	free(index);
}
