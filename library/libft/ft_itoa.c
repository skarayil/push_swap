/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:05:55 by skarayil          #+#    #+#             */
/*   Updated: 2025/05/30 19:02:08 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_char_len(int n)
{
	int		len;
	long	nbr;

	nbr = n;
	len = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	else if (nbr == 0)
	{
		len++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nbr;

	len = ft_char_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	nbr = n;
	str[len--] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	else if (nbr == 0)
	{
		str[0] = '0';
	}
	while (nbr > 0)
	{
		str[len--] = nbr % 10 + 48;
		nbr = nbr / 10;
	}
	return (str);
}
