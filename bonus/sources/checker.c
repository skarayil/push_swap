/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:16:49 by skarayil          #+#    #+#             */
/*   Updated: 2025/10/28 23:58:07 by skarayil         ###   ########.fr       */
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

// checker.c içine (ft_executer'ı da güncellemen GEREK)

// Önce ft_executer'ı int döndürecek şekilde GÜNCELLE
// Bu, geçersiz komutta "Error" vermeden önce 'line' değişkenini free etmemizi sağlar.
static int	ft_apply_exec(t_data *data, char *line)
{
	// "Enter"a basılırsa (boş satır) görmezden gel
	if (ft_equal(line, ""))
		return (1);
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
		return (0); // Geçersiz komut = HATA
	return (1); // Başarılı
}

// ŞİMDİ ft_checker'ı DÜZELT
static void	ft_checker(t_data *data)
{
	char	*line;
	int		status;

	line = get_next_line(0); // İlk satırı oku
	while (line) // Satır NULL olmadığı sürece dön
	{
		status = ft_apply_exec(data, line); // Komutu uygula

		// Eğer komut geçersizse (status == 0)
		if (status == 0)
		{
			free(line); // LEAK'i önle
			ft_error_exit(data); // Hata ver
		}

		free(line); // Satırı free et
		line = get_next_line(0); // YENİ satırı oku
	}

	// Döngü bitti (girdi sonlandı)
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
