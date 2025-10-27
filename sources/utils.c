/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:06:04 by skarayil          #+#    #+#             */
/*   Updated: 2025/10/18 15:07:01 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_is_number(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = (*str == '-' || *str == '+');
	if (!str[i])
		return (0);
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}

int	ft_is_sorted(t_stack *stack)
{
	t_stack	*curr;

	if (!stack || !stack->next)
		return (1);
	curr = stack;
	while (curr && curr->next)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

long	ft_atol(const char *nptr)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	if (!ft_isdigit(*nptr))
		return (0);
	while (ft_isdigit(*nptr))
	{
		res = res * 10 + (*nptr - '0');
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && - res < INT_MIN))
			return (0);
		nptr++;
	}
	if (*nptr)
		return (0);
	return (res * sign);
}

void	ft_error_exit(t_data *data)
{
	if (data)
	{
		ft_stack_clear(&data->stack_a);
		ft_stack_clear(&data->stack_b);
	}
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_free_all(char **split, int *nums)
{
	ft_free_split(split);
	free(nums);
	ft_error_exit(NULL);
}
