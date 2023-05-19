/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:14:20 by itrueba-          #+#    #+#             */
/*   Updated: 2023/04/23 12:02:58 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_file(t_pipex *pipex, int n)
{
	if (n == 0)
		write(1, "Input File Error\n", 17);
	else
		write(1, "Output File Error\n", 18);
	free(pipex);
	exit(0);
}

void	ft_free_env(t_pipex *pipex)
{
	char		**envp;
	char		*temp_envp;

	envp = pipex->envp;
	while (*envp)
	{
		temp_envp = *envp;
		free(temp_envp);
		envp++;
	}
	free(pipex->envp);
}

void	ft_free_command_content(char **content)
{
	char		*temp_content;

	while (*content)
	{
		temp_content = *content;
		free(temp_content);
		content++;
	}
}

void	ft_free_command(t_pipex *pipex)
{
	t_command	*temp_comman;

	while (*pipex->command)
	{
		temp_comman = *pipex->command;
		*pipex->command = (*pipex->command)->next;
		ft_free_command_content(temp_comman->content);
		free(temp_comman->content);
		free(temp_comman->command_path);
		free(temp_comman);
	}
	free(pipex->command);
}

void	ft_free(t_pipex *pipex)
{
	ft_free_env(pipex);
	ft_free_command(pipex);
	free(pipex);
	exit(0);
}
