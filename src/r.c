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
	t_u8	buffer[sizeof(ssize_t)];
	size_t	i;

	if (!v || v->size <= 1)
		return ;
	if (v->size == 2)
	{
		s(v, t);
		return ;
	}
	ft_memtake(buffer, ft_vec_peek_last(v), v->sizeof_type);
	i = v->size - 1;
	while (i > 0)
	{
		ft_memcpy(ft_vec_get_mut(v, i), ft_vec_get(v, i - 1), v->sizeof_type);
		i--;
	}
	ft_memcpy(v->data, buffer, v->sizeof_type);
	if (t == 1)
		write(1, "ra\n", 3);
	else if (t == 2)
		write(1, "rb\n", 3);
}
