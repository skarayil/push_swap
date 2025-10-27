/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:59:31 by skarayil          #+#    #+#             */
/*   Updated: 2025/10/27 22:39:00 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf.h"
#include "push_swap.h"

static void	ft_push_to_stack(t_stack **src, t_stack **dst, int *src_size,
		int *dst_size)
{
	t_stack	*temp;

	if (!src || !*src || *src_size == 0)
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	temp->next = *dst;
	if (*dst)
		(*dst)->prev = temp;
	*dst = temp;
	(*src_size)--;
	(*dst_size)++;
}

void	ft_pa(t_data *data, int print)
{
	ft_push_to_stack(&data->stack_b, &data->stack_a, &data->size_b,
		&data->size_a);
	if (print)
		ft_printf("pa\n");
}

void	ft_pb(t_data *data, int print)
{
	ft_push_to_stack(&data->stack_a, &data->stack_b, &data->size_a,
		&data->size_b);
	if (print)
		ft_printf("pb\n");
}
