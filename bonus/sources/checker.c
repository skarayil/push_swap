/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:16:49 by skarayil          #+#    #+#             */
/*   Updated: 2025/10/29 00:30:31 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "ft_printf.h"
#include "libft.h"
#include "push_swap_bonus.h"

static void	ft_checker(t_data *data)
{
	char	*line;
	int		status;

	line = get_next_line(0);
	while (line)
	{
		status = ft_apply_exec(data, line);
		if (status == 0)
		{
			free(line);
			ft_error_exit(data);
		}
		free(line);
		line = get_next_line(0);
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
