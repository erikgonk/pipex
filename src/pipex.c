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

void	ft_errors(char *str, int error)
{
	perror(str);
	exit (error);
}

char	**ft_get_path(char **e, t_pipex pipex)
{
	char		**res;

	while (*e && ft_strncmp("PATH", *e, 4))
	{
		e++;
		printf("%s\n", *e);
		if (!*e)
			ft_errors(*e, 1);
	}	
	*e += 5;
	res = ft_split(*e, ':');
	return (res);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex		pipex;

	if (argc != 5)
		ft_errors("args", 128);
	pipex.paths = ft_get_path(env, pipex);
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		ft_errors("Opening Infile", 1);
	pipex.outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex.outfile < 0)
		ft_errors("Opening Outfile", 1);
	if (pipe(pipex.tube) < 0)
		ft_errors("Pipe Function", 1);
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		first_child(pipex, argv, env);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		second_child(pipex, argv, env);
	waitpid(pipex.pid1, NULL, -1);
	waitpid(pipex.pid2, NULL, -1);
	close(pipex.infile);
	close(pipex.outfile);
	exit (0);
}