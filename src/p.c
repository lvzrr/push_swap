/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:44:05 by jaicastr          #+#    #+#             */
/*   Updated: 2025/05/31 15:46:53 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	p(t_vec *dst, t_vec *src, t_u8 t)
{
	if (!dst || !dst->alloc_size || !src
		|| dst->size == dst->alloc_size
		|| !src->size)
		return ;
	ft_vec_popmv((void *)((t_u8 *)dst->data + dst->size * dst->sizeof_type),
		src);
	dst->size++;
	if (t == 1)
		write(1, "pb\n", 3);
	else if (t == 2)
		write(1, "pa\n", 3);
}
