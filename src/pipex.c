/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:06:47 by erigonza          #+#    #+#             */
/*   Updated: 2024/05/15 16:06:48 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int main(int argc, char **argv, char **env)
{
  t_pipex     pipex;

  if (argc != 5)
    ft_errors("4 Args Needed");
  pipex.paths = ft_get_path(env);
  pipex.infile = open(argv[1], O_RDONLY);
  if (pipex.infile < 0)
		ft_errors("Opening Infile");
	pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex.outfile < 0)
		ft_errors("Opening Outfile");
  if (pipe(pipex.tube) < 0)
    ft_errors("Pipe Function");
  pipex.pid1 = fork();
  if (pipex.pid1 == 0)
    first_child(pipex, argv, env);
  pipex.pid2 = fork();
  if (pipex.pid2 == 0)
    first_child(pipex, argv, env);
  // waitpid(pipex.pid1, NULL, 0);
	// waitpid(pipex.pid2, NULL, 0);
  exit (0);
}