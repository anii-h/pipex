/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anihamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:57:51 by anihamba          #+#    #+#             */
/*   Updated: 2025/08/04 13:57:54 by anihamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	clear_path(char **path)
{
	int	i;

	i = 0;
	if (!path)
		return ;
	while (path[i])
		free(path[i++]);
	free(path);
}

char	*check_paths(char **paths, char *cmd)
{
	char	*path;
	char	*potential;
	int		i;

	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		potential = ft_strjoin(path, cmd);
		free(path);
		if (access(potential, F_OK | X_OK) == 0)
		{
			clear_path(paths);
			return (potential);
		}
		free(potential);
		i++;
	}
	return (NULL);
}

char	*get_the_path(char *cmd, char **envp)
{
	char	**paths;
	char	*final;
	int		i;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	if (!envp[i])
		error(0);
	paths = ft_split(envp[i] + 5, ':');
	final = check_paths(paths, cmd);
	if (!final)
		clear_path(paths);
	return (final);
}

void	exec_path_cmd(char **cmd, char **envp)
{
	char	*cmd_path;

	cmd_path = get_the_path(cmd[0], envp);
	if (!cmd_path)
	{
		clear_path(cmd);
		error(0);
	}
	if (execve(cmd_path, cmd, envp) == -1)
	{
		clear_path(cmd);
		free(cmd_path);
		error(0);
	}
}

void	cmd_exec(char *argv, char **envp)
{
	char	**cmd;

	if (!argv || argv[0] == '\0')
		error(0);
	cmd = ft_split(argv, ' ');
	if (!cmd || !cmd[0])
		error(0);
	if (ft_strchr(cmd[0], '/') || ft_strchr(cmd[0], '.'))
	{
		if (access(cmd[0], X_OK) == 0)
			execve(cmd[0], cmd, envp);
		clear_path(cmd);
		error(0);
	}
	exec_path_cmd(cmd, envp);
}
