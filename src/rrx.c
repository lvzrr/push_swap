/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 00:07:59 by jaicastr          #+#    #+#             */
/*   Updated: 2025/06/01 00:07:59 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrx(t_vec *v, t_u8 t)
{
	t_u8	buffer[sizeof(ssize_t)];

	if (!v || v->size <= 1)
		return ;
	if (v->size == 2)
	{
		s(v, t);
		return ;
	}
	ft_memtake(buffer, v->data, v->sizeof_type);
	ft_memmove(v->data,
		(t_u8 *)v->data + v->sizeof_type,
		(v->size - 1) * v->sizeof_type);
	ft_memcpy(ft_vec_peek_last(v), buffer, v->sizeof_type);
	if (t == 1)
		write(1, "rra\n", 4);
	else if (t == 2)
		write(1, "rrb\n", 4);
}
