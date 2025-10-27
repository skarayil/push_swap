/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:04:31 by skarayil          #+#    #+#             */
/*   Updated: 2025/06/02 19:10:02 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	str1;
	size_t	str2;

	if (!s1 || !s2)
		return (NULL);
	str1 = ft_strlen(s1);
	str2 = ft_strlen(s2);
	join = malloc(str1 + str2 + 1);
	if (!join)
		return (NULL);
	ft_memcpy(join, s1, str1);
	ft_memcpy(join + str1, s2, str2);
	join[str1 + str2] = '\0';
	return (join);
}
