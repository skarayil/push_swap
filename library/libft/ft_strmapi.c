/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:06:21 by skarayil          #+#    #+#             */
/*   Updated: 2025/06/02 19:16:06 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*map;

	if (!s || !f)
		return (NULL);
	map = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!map)
		return (NULL);
	index = 0;
	while (s[index])
	{
		map[index] = f(index, s[index]);
		index++;
	}
	map[index] = '\0';
	return (map);
}
