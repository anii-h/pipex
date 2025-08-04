/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anihamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:57:33 by anihamba          #+#    #+#             */
/*   Updated: 2025/08/04 13:57:35 by anihamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_data
{
	char	**argv;
	char	**envp;
	int		*fd;
}			t_data;

char	*get_the_path(char *cmd, char **envp);
char	*check_paths(char **paths, char *cmd);
void	cmd_exec(char *argv, char **envp);
void	error(int i);
void	par_prc(int *fd, char **argv, char **envp);
void	ch_prc(int *fd, char **argv, char **envp);
void	exec_path_cmd(char **cmd, char **envp);
void	clear_path(char **path);
void	init(t_data *data, int fd[2], int *exit_status);
void	fork_run(pid_t *pid, void (*func)(t_data *data), t_data *data);

#endif
