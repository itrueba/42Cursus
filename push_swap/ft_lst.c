/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:03:26 by itrueba-          #+#    #+#             */
/*   Updated: 2023/01/20 09:14:17 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_pre_lstlast(t_list *lst)
{
	if (lst)
		while (lst->next->next)
			lst = lst->next;
	return (lst);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst)
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
		{
			new->next = *lst;
		}
		*lst = new;
	}
}

t_list	*ft_lstnew(int content)
{
	t_list	*s_list;

	s_list = (t_list *)malloc(sizeof(*s_list));
	if (!s_list)
		return (NULL);
	s_list->content = content;
	s_list->next = NULL;
	return (s_list);
}
