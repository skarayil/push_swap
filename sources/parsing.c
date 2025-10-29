/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:34:42 by skarayil          #+#    #+#             */
/*   Updated: 2025/10/29 15:49:42 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

static int	ft_validate(int *nums, char *str, int index)
{
	long	num;
	int		i;

	if (!ft_is_number(str))
		return (0);
	num = ft_atol(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	if (num == 0)
	{
		i = 0;
		if (str[i] == '+' || str[i] == '-')
			i++;
		while (str[i])
		{
			if (str[i] != '0')
				return (0);
			i++;
		}
	}
	nums[index] = (int)num;
	return (1);
}

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	*ft_single(char *arg, int *count)
{
	char	**split;
	int		*nums;
	int		index;
	int		split_count;

	split = ft_split(arg, ' ');
	if (!split)
		ft_error_exit(NULL);
	index = 0;
	while (split[index])
		index++;
	split_count = index;
	nums = malloc(sizeof(int) * split_count);
	if (!nums)
		ft_error_exit(NULL);
	index = 0;
	while (index < split_count)
	{
		if (!ft_validate(nums, split[index], index))
			ft_free_all(split, nums);
		index++;
	}
	ft_free_split(split);
	*count = split_count;
	return (nums);
}

static int	*ft_multiple(int ac, char **av, int *count)
{
	int	*nums;
	int	i;

	nums = malloc(sizeof(int) * (ac - 1));
	if (!nums)
		ft_error_exit(NULL);
	i = 1;
	while (i < ac)
	{
		if (!ft_validate(nums, av[i], i - 1))
		{
			free(nums);
			ft_error_exit(NULL);
		}
		i++;
	}
	*count = ac - 1;
	return (nums);
}

int	*ft_parse_numbers(int ac, char **av, int *count)
{
	int	*nums;

	nums = NULL;
	*count = 0;
	if (ac == 2 && ft_strchr(av[1], ' '))
		nums = ft_single(av[1], count);
	else
	{
		nums = ft_multiple(ac, av, count);
	}
	return (nums);
}
