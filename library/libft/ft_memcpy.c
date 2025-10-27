/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:17:24 by skarayil          #+#    #+#             */
/*   Updated: 2025/06/04 15:12:44 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*s;
	unsigned char	*d;

	if (src == NULL && dest == NULL)
		return (NULL);
	if ((dest > src && dest < src + n) || (src > dest && src < dest + n))
		return (ft_memmove(dest, src, n));
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	index = 0;
	while (index < n)
	{
		d[index] = s[index];
		index++;
	}
	return (dest);
}
