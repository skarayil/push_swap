/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 00:25:25 by skarayil          #+#    #+#             */
/*   Updated: 2025/10/29 00:31:57 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap_bonus.h"

static int	ft_equal(const char *line, const char *op)
{
	size_t	len;
	size_t	olen;

	if (!line || !op)
		return (0);
	len = ft_strlen(line);
	if (len && line[len - 1] == '\n')
		len--;
	olen = ft_strlen(op);
	if (olen != len)
		return (0);
	return (ft_strncmp(line, op, len) == 0);
}

static int	ft_apply_push_swap(t_data *data, char *line)
{
	if (ft_equal(line, "pa"))
		ft_pa(data, 0);
	else if (ft_equal(line, "pb"))
		ft_pb(data, 0);
	else if (ft_equal(line, "sa"))
		ft_sa(data, 0);
	else if (ft_equal(line, "sb"))
		ft_sb(data, 0);
	else if (ft_equal(line, "ss"))
		ft_ss(data, 0);
	else
		return (0);
	return (1);
}

static int	ft_apply_rotates(t_data *data, char *line)
{
	if (ft_equal(line, "ra"))
		ft_ra(data, 0);
	else if (ft_equal(line, "rb"))
		ft_rb(data, 0);
	else if (ft_equal(line, "rr"))
		ft_rr(data, 0);
	else if (ft_equal(line, "rra"))
		ft_rra(data, 0);
	else if (ft_equal(line, "rrb"))
		ft_rrb(data, 0);
	else if (ft_equal(line, "rrr"))
		ft_rrr(data, 0);
	else
		return (0);
	return (1);
}

int	ft_apply_exec(t_data *data, char *line)
{
	if (ft_equal(line, ""))
		return (0);
	if (ft_apply_push_swap(data, line))
		return (1);
	if (ft_apply_rotates(data, line))
		return (1);
	return (0);
}
