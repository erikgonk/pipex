/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:54:07 by erigonza          #+#    #+#             */
/*   Updated: 2024/05/19 17:54:08 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char  *check_cmd(char **paths, char *argv)
{
  int     i;
  char    *cmd;
  char    *tmp;

  i = -1;
  while (paths)
  {
    tmp = ft_strjoin(*paths, "/");
    cmd = ft_strjoin(tmp, argv);
    free(tmp);
    if (access(cmd, X_OK) == 0)
      return (cmd);
    free(cmd);
    paths++;
  }
  return (NULL);  
}

void  first_child(t_pipex pipex, char **argv, char **env)
{
  dup2(pipex.tube[1], 1);
	close(pipex.tube[0]);
	close(pipex.tube[1]);
	dup2(pipex.infile, 0);
	close(pipex.infile);
  pipex.cmd_args = ft_split(argv[2], ' ');
  pipex.cmd = check_cmd(pipex.paths, argv[2]);
  if (!pipex.cmd)
    ft_errors("Path Not Found");
  execve(pipex.cmd, pipex.cmd_args, env);
}

void  second_child(t_pipex pipex, char **argv, char **env)
{
  dup2(pipex.tube[0], 0);
	close(pipex.tube[0]);
	close(pipex.tube[1]);
	dup2(pipex.outfile, 1);
	close(pipex.outfile);
  pipex.cmd_args = ft_split(argv[3], ' ');
  pipex.cmd = check_cmd(pipex.paths, argv[3]);
  if (!pipex.cmd)
    ft_errors("Path Not Found");
  execve(pipex.cmd, pipex.cmd_args, env);
}