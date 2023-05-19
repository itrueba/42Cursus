/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:14:20 by itrueba-          #+#    #+#             */
/*   Updated: 2023/05/06 13:47:25 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipe(t_command *command, t_pipex *pipex, int final)
{
	pid_t	pid;

	pipe(pipex->fd);
	pid = fork();
	if (pid == 0)
	{
		close(pipex->fd[READ]);
		if (final)
			dup2(pipex->out_fd, STDOUT_FILENO);
		else
			dup2(pipex->fd[WRITE], STDOUT_FILENO);
		execve(command->command_path, command->content, pipex->envp);
	}
	else
	{
		if (final)
			exit(0);
		close(pipex->fd[WRITE]);
		dup2(pipex->fd[READ], STDIN_FILENO);
	}
	waitpid(pid, NULL, 0);
}

void	ft_pipex(t_pipex *pipex)
{
	t_command	*command;

	command = *(pipex->command);
	dup2(pipex->in_fd, STDIN_FILENO);
	ft_pipe(command, pipex, 0);
	command = command->next;
	ft_pipe(command, pipex, 1);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc == 5)
	{
		pipex = malloc(sizeof(t_pipex));
		ft_check_files(pipex, argv[1], argv[argc - 1]);
		pipex->argc = argc - 3;
		pipex->envp = ft_split(ft_find_path(envp), ':');
		ft_command_list(pipex, &argv[2]);
		ft_pipex(pipex);
		ft_free(pipex);
	}
	return (0);
}
