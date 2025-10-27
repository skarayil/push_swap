/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 22:33:27 by skarayil          #+#    #+#             */
/*   Updated: 2025/10/27 22:33:34 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	ft_cleanup_data(t_data *data)
{
	ft_stack_clear(&data->stack_a);
	ft_stack_clear(&data->stack_b);
	data->size_a = 0;
	data->size_b = 0;
}

void	ft_stack_clear(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*next;

	if (!stack || !*stack)
		return ;
	curr = *stack;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	*stack = NULL;
}
