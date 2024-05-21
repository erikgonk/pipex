/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:55:00 by erigonza          #+#    #+#             */
/*   Updated: 2024/05/15 18:55:04 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// write, read, close, access, pipe, dup, dup2, execve, fork
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
// malloc, free, exit
# include <stdlib.h>
// open, unlink
# include <fcntl.h>
// waitpid, wait
# include <sys/wait.h>
// strerror 
# include <string.h>
// perror
# include <stdio.h>
// Lift 
# include "../src/libft/libft.h"

typedef struct s_pipex
{
	pid_t     pid1;
	pid_t     pid2;
	int       tube[2];
	int       infile;
	int       outfile;
	char			*cmd;
	char			**cmd_args;
	char      **paths;
}           t_pipex;

// main

// utils
void				ft_errors(char *str, int error);
char				**ft_get_path(char **e, t_pipex pipex);
// Childs
char  *check_cmd(char **paths, char *argv);
void  first_child(t_pipex pipex, char **argv, char **env);
void  second_child(t_pipex pipex, char **argv, char **env);

#endif
