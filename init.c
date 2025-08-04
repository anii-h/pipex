/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anihamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:57:27 by anihamba          #+#    #+#             */
/*   Updated: 2025/08/04 13:57:29 by anihamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ch_prc1(t_data *data)
{
	int	infile;

	infile = open(data->argv[1], O_RDONLY, 0777);
	if (infile < 0)
	{
		close(data->fd[0]);
		close(data->fd[1]);
		error(2);
	}
	dup2(infile, STDIN_FILENO);
	dup2(data->fd[1], STDOUT_FILENO);
	close(data->fd[0]);
	close(data->fd[1]);
	close(infile);
	cmd_exec(data->argv[2], data->envp);
}

void	ch_prc2(t_data *data)
{
	int	outfile;

	outfile = open(data->argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile < 0)
	{
		close(data->fd[0]);
		close(data->fd[1]);
		error(2);
	}
	dup2(data->fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(data->fd[1]);
	close(data->fd[0]);
	close(outfile);
	cmd_exec(data->argv[3], data->envp);
}

void	init(t_data *data, int fd[2], int *exit_status)
{
	pid_t	pid1;
	pid_t	pid2;

	fork_run(&pid1, ch_prc1, data);
	fork_run(&pid2, ch_prc2, data);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, exit_status, 0);
}
