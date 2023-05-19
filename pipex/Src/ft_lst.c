/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:03:26 by itrueba-          #+#    #+#             */
/*   Updated: 2023/05/06 13:00:42 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_command(char *ptr)
{
	int		len;
	int		count;
	char	*str;

	len = 0;
	count = 0;
	while (ptr[len] && ptr[len] != ' ')
		len++;
	str = malloc(len + 1);
	while (count < len)
	{
		str[count] = ptr[count];
		count++;
	}
	str[count] = 0;
	return (str);
}

t_command	*ft_pipex_lstlast(t_command *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

void	ft_pipex_lstadd_back(t_command **lst, t_command *new)
{
	t_command	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_pipex_lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}

t_command	*ft_pipex_lstnew(char *content, t_pipex *pipex)
{
	t_command	*s_command;
	char		*path;

	path = ft_path(pipex, ft_command(content));
	s_command = (t_command *)malloc(sizeof(*s_command));
	if (!s_command)
		return (NULL);
	s_command->command_path = path;
	s_command->content = ft_split(content, ' ');
	s_command->next = NULL;
	return (s_command);
}
