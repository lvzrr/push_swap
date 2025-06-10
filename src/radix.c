/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:02:53 by jaicastr          #+#    #+#             */
/*   Updated: 2025/06/10 21:03:19 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_bit_count(size_t size)
{
	int	bits;

	bits = 0;
	while ((1U << bits) < size)
		bits++;
	return (bits);
}

static void	pass_radix(t_vec *a, t_vec *b, int bit, size_t size)
{
	ssize_t	num;
	size_t	i;

	i = 0;
	while (i++ < size)
	{
		num = *(ssize_t *)ft_vec_peek_last(a);
		if (!((num >> bit) & 1))
			p(b, a, 1);
		else
			r(a, 1);
	}
	while (b->size)
		p(a, b, 2);
}

void	radix_sort(t_vec *a, t_vec *b)
{
	size_t	size;
	int		bit;
	int		max_bits;

	normalize_indices(a);
	size = a->size;
	max_bits = get_bit_count(size);
	bit = -1;
	while (++bit < max_bits)
		pass_radix(a, b, bit, size);
}
