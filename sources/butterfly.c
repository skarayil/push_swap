/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 03:34:24 by skarayil          #+#    #+#             */
/*   Updated: 2025/10/24 13:26:39 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_chunker(int size)
{
	int	chunk;

	if (size < 50)
		chunk = 3 + (size - 6) / 7;
	else if (size < 100)
		chunk = 10 + (size - 50) / 8;
	else if (size < 350)
		chunk = 18 + (size - 100) / 9;
	else if (size <= 500)
		chunk = 27 + (size - 350) / 15;
	else
		chunk = 37 + (size - 500) / 20;
	return (chunk);
}

static void	ft_find_pos(t_data *data, t_stack *max, int *pos)
{
	t_stack	*curr;

	curr = data->stack_b;
	*pos = 0;
	while (curr != max)
	{
		curr = curr->next;
		(*pos)++;
	}
}

static void	ft_extract_max(t_data *data)
{
	t_stack	*max;
	t_stack	*curr;
	int		pos;

	max = data->stack_b;
	curr = data->stack_b->next;
	while (curr)
	{
		if (curr->index > max->index)
			max = curr;
		curr = curr->next;
	}
	ft_find_pos(data, max, &pos);
	if (pos <= data->size_b / 2)
		while (pos-- > 0)
			ft_rb(data, 1);
	else
		while (pos++ < data->size_b)
			ft_rrb(data, 1);
	ft_pa(data, 1);
}

void	ft_butterfly_algo(t_data *data)
{
	int	chunk;
	int	counter;

	chunk = ft_chunker(data->size_a);
	counter = 0;
	while (data->size_a > 0)
	{
		if (data->stack_a->index <= counter)
		{
			ft_pb(data, 1);
			ft_rb(data, 1);
			counter++;
		}
		else if (data->stack_a->index <= counter + chunk)
		{
			ft_pb(data, 1);
			counter++;
		}
		else
			ft_ra(data, 1);
	}
	while (data->size_b > 0)
		ft_extract_max(data);
}
