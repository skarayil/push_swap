/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caterpillar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 09:54:07 by skarayil          #+#    #+#             */
/*   Updated: 2025/10/24 12:17:49 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_move_target(t_data *data, int index)
{
	t_stack	*curr;
	int		pos;
	int		rev;

	pos = 0;
	curr = data->stack_a;
	while (curr && curr->index != index)
	{
		curr = curr->next;
		pos++;
	}
	if (pos <= data->size_a / 2)
	{
		while (pos-- > 0)
			ft_ra(data, 1);
	}
	else
	{
		rev = data->size_a - pos;
		while (rev-- > 0)
			ft_rra(data, 1);
	}
	ft_pb(data, 1);
}

void	ft_handle_two(t_data *data)
{
	if (data->stack_a->value > data->stack_a->next->value)
		ft_sa(data, 1);
}

void	ft_handle_three(t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = data->stack_a->value;
	j = data->stack_a->next->value;
	k = data->stack_a->next->next->value;
	if (i < j && j < k)
		return ;
	else if (i > j && j < k && i < k)
		ft_sa(data, 1);
	else if (i > j && j < k && i > k)
		ft_ra(data, 1);
	else if (i < j && j > k && i > k)
		ft_rra(data, 1);
	else if (i < j && j > k && i < k)
	{
		ft_sa(data, 1);
		ft_ra(data, 1);
	}
	else if (i > j && j > k)
	{
		ft_sa(data, 1);
		ft_rra(data, 1);
	}
}

void	ft_handle_four_five(t_data *data)
{
	int	size;
	int	index;

	size = data->size_a;
	index = -1;
	while (++index < size - 3)
		ft_move_target(data, index);
	ft_handle_three(data);
	index = -1;
	while (++index < size - 3)
		ft_pa(data, 1);
}
