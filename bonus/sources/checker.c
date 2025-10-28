/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:16:49 by skarayil          #+#    #+#             */
/*   Updated: 2025/10/27 23:06:39 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "ft_printf.h"
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

static void	ft_executer(t_data *data, char *line)
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
	else if (ft_equal(line, "ra"))
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
		ft_error_exit(data);
}

static void	ft_checker(t_data *data)
{
	size_t	i;
	char	*line;

	i = 0;
	line = get_next_line(0);
	while (line[i])
	{
		if (!(line[i] != ' ' && line[i] != '\t' && line[i] != '\n'
				&& line[i] != '\r'))
			ft_executer(data, line);
		free(line);
		line = get_next_line(0);
		i++;
	}
	if (ft_is_sorted(data->stack_a) && !data->stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

static void	ft_parser_bonus(int ac, char **av, t_data *data)
{
	int	*nums;
	int	count;

	nums = ft_parse_numbers(ac, av, &count);
	ft_fill_stack(data, nums, count);
	free(nums);
	data->size_a = count;
	data->size_b = 0;
}

int	main(int ac, char *av[])
{
	t_data	data;

	if (ac < 2)
		return (0);
	ft_bzero(&data, sizeof(t_data));
	ft_parser_bonus(ac, av, &data);
	ft_checker(&data);
	ft_cleanup_data(&data);
	return (0);
}
