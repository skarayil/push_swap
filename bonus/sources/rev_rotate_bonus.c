/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:59:33 by skarayil          #+#    #+#             */
/*   Updated: 2025/10/27 22:39:08 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

static void	ft_rev_rotate(t_stack **stack, int size)
{
	t_stack	*last;
	t_stack	*new_tail;
	t_stack	*head;

	if (!stack || !*stack || size <= 1)
		return ;
	new_tail = *stack;
	while (new_tail->next->next)
		new_tail = new_tail->next;
	last = new_tail->next;
	head = *stack;
	new_tail->next = NULL;
	last->prev = NULL;
	last->next = head;
	head->prev = last;
	*stack = last;
}

void	ft_rra(t_data *data, int print)
{
	ft_rev_rotate(&data->stack_a, data->size_a);
	if (print)
		ft_printf("rra\n");
}

void	ft_rrb(t_data *data, int print)
{
	ft_rev_rotate(&data->stack_b, data->size_b);
	if (print)
		ft_printf("rrb\n");
}

void	ft_rrr(t_data *data, int print)
{
	ft_rev_rotate(&data->stack_a, data->size_a);
	ft_rev_rotate(&data->stack_b, data->size_b);
	if (print)
		ft_printf("rrr\n");
}
