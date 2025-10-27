/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 09:54:02 by skarayil          #+#    #+#             */
/*   Updated: 2025/10/23 05:01:07 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	ft_insertion_sort(int *arr, int size)
{
	int	last;
	int	i;

	if (size <= 1)
		return ;
	ft_insertion_sort(arr, size - 1);
	last = arr[size - 1];
	i = size - 2;
	while (i >= 0 && arr[i] > last)
	{
		arr[i + 1] = arr[i];
		i--;
	}
	arr[i + 1] = last;
}

int	ft_is_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	ft_assign_indices(t_stack *stack, int *arr, int size)
{
	t_stack	*curr;
	int		i;

	curr = stack;
	while (curr)
	{
		i = 0;
		while (i < size)
		{
			if (curr->value == arr[i])
			{
				curr->index = i;
				break ;
			}
			i++;
		}
		curr = curr->next;
	}
}

void	ft_fill_stack(t_data *data, int *nums, int count)
{
	int		i;
	t_stack	*new;

	data->stack_a = NULL;
	data->stack_b = NULL;
	data->size_a = 0;
	data->size_b = 0;
	i = -1;
	while (++i < count)
	{
		if (ft_is_duplicate(data->stack_a, nums[i]))
		{
			free(nums);
			ft_cleanup_data(data);
			ft_error_exit(NULL);
		}
		new = ft_stack_new(nums[i]);
		ft_stack_add_back(&data->stack_a, new);
		data->size_a++;
	}
}

int	*ft_sort_array(t_stack *stack, int size)
{
	int		*arr;
	int		i;
	t_stack	*temp;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = -1;
	temp = stack;
	while ((temp) && ++i < size)
	{
		arr[i] = temp->value;
		temp = temp->next;
	}
	ft_insertion_sort(arr, size);
	return (arr);
}
