/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anihamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:57:41 by anihamba          #+#    #+#             */
/*   Updated: 2025/08/04 13:57:42 by anihamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(int i)
{
	close(1);
	close(0);
	if (i == 5 || i == 2 || i == 1)
	{
		if (i == 5)
			perror("Usage: ./pipex infile cmd1 cmd2 outfile");
		if (i == 2)
			perror("file open error!");
		if (i == 1)
			perror("pipe/fork failed :(   ");
		close(2);
		exit(EXIT_FAILURE);
	}
	else if (i == 0)
	{
		perror("command error!");
		close(2);
		exit(127);
	}
}

void	fork_run(pid_t *pid, void (*func)(t_data *data), t_data *data)
{
	*pid = fork();
	if (*pid < 0)
		error(1);
	if (*pid == 0)
	{
		func(data);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		exit_status;
	t_data	data;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
		{
			close(fd[0]);
			close(fd[1]);
			error(1);
		}
		data.argv = argv;
		data.envp = envp;
		data.fd = fd;
		init(&data, fd, &exit_status);
		return (WEXITSTATUS(exit_status));
	}
	else
		error(5);
	return (0);
}
