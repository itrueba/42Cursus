/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:05:05 by itrueba-          #+#    #+#             */
/*   Updated: 2023/04/26 20:10:53 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_path(t_pipex *pipex)
{
	write(1, "Invalid Command Error.\n", 23);
	ft_free(pipex);
	exit(0);
}

char	*ft_path(t_pipex *pipex, char *command)
{
	const char	*slash;
	char		*path;
	char		*path_command;
	int			count;

	slash = "/";
	count = 0;
	while (pipex->envp[count])
	{
		path = ft_strjoin(pipex->envp[count], slash);
		path_command = ft_strjoin(path, command);
		free(path);
		if (access(path_command, F_OK) == 0)
		{
			free(command);
			return (path_command);
		}
		free(path_command);
		count++;
	}
	free(command);
	ft_error_path(pipex);
	return ("");
}

char	*ft_find_path(char **envp)
{
	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	return (*envp + 5);
}
