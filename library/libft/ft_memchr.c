/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:22:48 by skarayil          #+#    #+#             */
/*   Updated: 2025/05/31 12:25:05 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*res;
	unsigned char	*ptr;

	res = NULL;
	ptr = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		if (ptr[index] == (unsigned char)c)
		{
			res = &ptr[index];
			break ;
		}
		index++;
	}
	return (res);
}
