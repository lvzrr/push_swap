/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 19:53:53 by jaicastr          #+#    #+#             */
/*   Updated: 2025/05/31 20:06:24 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r(t_vec *v, t_u8 t)
{
	t_u8	buffer[sizeof(int)];

	if (!v || v->size <= 1)
		return ;
	if (v->size == 2)
	{
		s(v, t);
		return ;
	}
	ft_memtake(buffer, ft_vec_peek_last(v), v->sizeof_type);
	ft_memmove((t_u8 *)v->data + v->sizeof_type, v->data,
		v->size * v->sizeof_type);
	ft_memcpy(v->data, buffer, v->sizeof_type);
	if (t == 1)
		write(1, "ra\n", 3);
	else if (t == 2)
		write(1, "rb\n", 3);
}

void	r_extern(t_vec *v, t_u8 t, t_u8 *buffer)
{
	if (!v || v->size <= 1 || !buffer)
		return ;
	if (v->size == 2)
	{
		s(v, t);
		return ;
	}
	ft_memtake(buffer, ft_vec_peek_last(v), v->sizeof_type);
	ft_memmove((t_u8 *)v->data + v->sizeof_type, v->data,
		v->size * v->sizeof_type);
	ft_memcpy(v->data, buffer, v->sizeof_type);
	if (t == 1)
		write(1, "ra\n", 3);
	else if (t == 2)
		write(1, "rb\n", 3);
}
