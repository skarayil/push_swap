/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:59:36 by skarayil          #+#    #+#             */
/*   Updated: 2025/10/27 22:10:10 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

static void	ft_rotate(t_stack **stack, int size)
{
	t_stack	*head;
	t_stack	*tail;

	if (!stack || !*stack || size <= 1)
		return ;
	tail = *stack;
	while (tail->next)
		tail = tail->next;
	head = *stack;
	*stack = head->next;
	(*stack)->prev = NULL;
	tail->next = head;
	head->prev = tail;
	head->next = NULL;
}

void	ft_ra(t_data *data, int print)
{
	ft_rotate(&data->stack_a, data->size_a);
	if (print)
		ft_printf("ra\n");
}

void	ft_rb(t_data *data, int print)
{
	ft_rotate(&data->stack_b, data->size_b);
	if (print)
		ft_printf("rb\n");
}

void	ft_rr(t_data *data, int print)
{
	ft_rotate(&data->stack_a, data->size_a);
	ft_rotate(&data->stack_b, data->size_b);
	if (print)
		ft_printf("rr\n");
}
