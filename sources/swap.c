/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:44:08 by skarayil          #+#    #+#             */
/*   Updated: 2025/10/12 22:29:22 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

static void	ft_swap(t_stack **stack, int size)
{
	t_stack	*i;
	t_stack	*j;
	t_stack	*k;

	if (!stack || !*stack || size < 2)
		return ;
	i = *stack;
	j = i->next;
	k = j->next;
	j->prev = NULL;
	j->next = i;
	i->prev = j;
	i->next = k;
	if (k)
		k->prev = i;
	*stack = j;
}

void	ft_sa(t_data *data, int print)
{
	ft_swap(&data->stack_a, data->size_a);
	if (print)
		ft_printf("sa\n");
}

void	ft_sb(t_data *data, int print)
{
	ft_swap(&data->stack_b, data->size_b);
	if (print)
		ft_printf("sb\n");
}

void	ft_ss(t_data *data, int print)
{
	ft_swap(&data->stack_a, data->size_a);
	ft_swap(&data->stack_b, data->size_b);
	if (print)
		ft_printf("ss\n");
}
