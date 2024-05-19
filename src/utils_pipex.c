/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:28:16 by erigonza          #+#    #+#             */
/*   Updated: 2024/05/17 13:28:17 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void  ft_errors(char *str)
{
  perror(str);
  exit (1);
}

char  **ft_get_path(char **e)
{
  char    **res;

  while (ft_strncmp("PATH", *e, 4))
    e++;
  *e += 5;
  res = ft_split(*e, ':');
	return (res);
}