/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:47:45 by itrueba-          #+#    #+#             */
/*   Updated: 2023/05/06 14:33:09 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft.h"
# include <fcntl.h>

# define READ 0
# define WRITE 1

typedef struct s_command
{
	char				**content;
	char				*command_path;
	struct s_command	*next;

}						t_command;

typedef struct s_pipex
{
	int					argc;
	char				**envp;
	int					in_fd;
	int					out_fd;
	int					here_doc;
	int					fd[2];
	struct s_command	**command;
}						t_pipex;

void					ft_free(t_pipex *pipex);
void					ft_error_file(t_pipex *pipex, int n);
void					ft_split_free(char **split);
void					ft_command_list(t_pipex *pipex, char **argv);
int						ft_check_files(t_pipex *pipex, char *file1,
							char *file2);
char					*ft_path(t_pipex *pipex, char *command);
char					*ft_find_path(char **envp);
void					ft_pipex_lstadd_back(t_command **lst, t_command *new);
t_command				*ft_pipex_lstnew(char *content, t_pipex *pipex);

#endif