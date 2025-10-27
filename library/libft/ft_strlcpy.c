/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:17:59 by skarayil          #+#    #+#             */
/*   Updated: 2025/05/31 12:33:04 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	index = ft_strlen(src);
	if (size == 0)
		return (index);
	while (size > 1 && *src)
	{
		*dst++ = *src++;
		size--;
	}
	*dst = '\0';
	return (index);
}
