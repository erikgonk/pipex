/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:54:07 by erigonza          #+#    #+#             */
/*   Updated: 2024/05/23 17:28:52 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_cmd(char **paths, char *argv)
{
	char		*tmp;
	char		*cmd;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		cmd = ft_strjoin(tmp, argv);
		free(tmp);
		if (access(cmd, 0) == 0)
			return (cmd);
		free(cmd);
		paths++;
	}
	return (NULL);
}

void	first_child(t_pipex pipex, char **argv, char **env)
{
	dup2(pipex.tube[1], 1);
	close(pipex.tube[1]);
	close(pipex.tube[0]);
	dup2(pipex.infile, 0);
	close(pipex.infile);
	pipex.cmd_args = ft_split(argv[2], ' ');
	if (pipex.cmd_args[0] && (access(pipex.cmd_args[0], X_OK) == 0))
		pipex.cmd = pipex.cmd_args[0];
	else
		pipex.cmd = check_cmd(pipex.paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
		exit ((ft_fd_printf(2, "%s: command not found\n", argv[2]) * 0) + 1);
	if (pipex.infile != 0)
		exit(1);
	execve(pipex.cmd, pipex.cmd_args, env);
}

void	second_child(t_pipex pipex, char **argv, char **env)
{
	dup2(pipex.tube[0], 0);
	close(pipex.tube[0]);
	close(pipex.tube[1]);
	dup2(pipex.outfile, 1);
	close(pipex.outfile);
	if (pipex.infile < 0)
		exit(1);
	pipex.cmd_args = ft_split(argv[3], ' ');
	if (pipex.cmd_args[0] && (access(pipex.cmd_args[0], X_OK) == 0))
		pipex.cmd = pipex.cmd_args[0];
	else
		pipex.cmd = check_cmd(pipex.paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
		ft_errors(argv[3], 1);
	execve(pipex.cmd, pipex.cmd_args, env);
}
