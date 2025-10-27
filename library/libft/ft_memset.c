/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:16:35 by skarayil          #+#    #+#             */
/*   Updated: 2025/05/31 16:39:08 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			index;

	ptr = (unsigned char *)str;
	index = 0;
	while (n > index)
	{
		ptr[index] = (unsigned char)c;
		index++;
	}
	return (str);
}
