/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:10:12 by skarayil          #+#    #+#             */
/*   Updated: 2025/10/29 00:28:25 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_data
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	int				size_a;
	int				size_b;
}					t_data;

void	ft_pa(t_data *data, int print);
void	ft_pb(t_data *data, int print);
void	ft_sa(t_data *data, int print);
void	ft_sb(t_data *data, int print);
void	ft_ss(t_data *data, int print);
void	ft_ra(t_data *data, int print);
void	ft_rb(t_data *data, int print);
void	ft_rr(t_data *data, int print);
void	ft_rra(t_data *data, int print);
void	ft_rrb(t_data *data, int print);
void	ft_rrr(t_data *data, int print);
void	ft_cleanup_data(t_data *data);
void	ft_error_exit(t_data *data);
void	ft_free_all(char **split, int *nums);
void	ft_free_split(char **split);
void	ft_assign_indices(t_stack *stack, int *arr, int size);
void	ft_fill_stack(t_data *data, int *nums, int count);
void	ft_stack_clear(t_stack **stack);
void	ft_stack_add_back(t_stack **stack, t_stack *new);
int		ft_is_sorted(t_stack *stack);
int		*ft_parse_numbers(int ac, char **av, int *count);
int		ft_is_number(char *str);
int		ft_is_duplicate(t_stack *stack, int value);
int		*ft_sort_array(t_stack *stack, int size);
int		ft_apply_exec(t_data *data, char *line);
long	ft_atol(const char *nptr);
t_stack	*ft_stack_new(int value);

#endif