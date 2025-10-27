/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 09:54:35 by skarayil          #+#    #+#             */
/*   Updated: 2025/10/17 11:49:44 by skarayil         ###   ########.fr       */
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

void	ft_stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!stack || !new)
		return ;
	new->next = NULL;
	new->prev = NULL;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}

int	ft_stack_size(t_stack *stack)
{
	t_stack	*currr;
	int		len;

	if (!stack)
		return (0);
	currr = stack;
	len = 0;
	while (currr)
	{
		len++;
		currr = currr->next;
	}
	return (len);
}

t_stack	*ft_stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
