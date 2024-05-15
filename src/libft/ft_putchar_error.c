/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:07:27 by erigonza          #+#    #+#             */
/*   Updated: 2024/04/14 13:04:11 by erigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_error(int fd, char c)
{
	return (write(fd, &c, 1));
}

// void	ft_bzero(void *s, size_t n)
// {
// 	while (n-- > 0)
// 		*((unsigned char *)s++) = 0;
// }
// 
// char	*ft_strchr2(const char *s, int c)
// {
// 	size_t		i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == (char)c)
// 			return ((char *)(s + i));
// 		i++;
// 	}
// 	if (s[i] == (char)c)
// 		return ((char *)(s + i));
// 	return (0);
// }
