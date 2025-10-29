/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 09:35:50 by skarayil          #+#    #+#             */
/*   Updated: 2025/10/29 15:19:29 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

static void	ft_initialize_stack(t_data *data, int ac, char **av)
{
	int	*nums;
	int	count;

	ft_bzero(data, sizeof(t_data));
	nums = ft_parse_numbers(ac, av, &count);
	ft_fill_stack(data, nums, count);
	free(nums);
}

static void	ft_prepare_sorting(t_data *data)
{
	int	*sorted_arr;

	sorted_arr = ft_sort_array(data->stack_a, data->size_a);
	if (!sorted_arr)
		ft_error_exit(data);
	ft_assign_indices(data->stack_a, sorted_arr, data->size_a);
	free(sorted_arr);
}

static void	ft_execute_sorting(t_data *data)
{
	if (data->size_a == 2)
		ft_handle_two(data);
	else if (data->size_a == 3)
		ft_handle_three(data);
	else if (data->size_a == 4 || data->size_a == 5)
		ft_handle_four_five(data);
	else
		ft_butterfly_algo(data);
}

int	main(int ac, char *av[])
{
	t_data	data;

	if (ac < 2)
		return (0);
	ft_initialize_stack(&data, ac, av);
	if (ft_is_sorted(data.stack_a))
	{
		ft_cleanup_data(&data);
		return (0);
	}
	ft_prepare_sorting(&data);
	ft_execute_sorting(&data);
	ft_cleanup_data(&data);
	return (0);
}
