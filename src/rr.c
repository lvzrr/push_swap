/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:46:02 by jaicastr          #+#    #+#             */
/*   Updated: 2025/05/31 20:47:34 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_vec *a, t_vec *b)
{
	if ((!a && !b) || (!a->size && !b->size))
		return ;
	r(a, 0);
	r(b, 0);
	write(1, "rr\n", 3);
}

void	rr_extern(t_vec *a, t_vec *b, t_u8 *buffer)
{
	if ((!a && !b) || (!a->size && !b->size)
		|| !buffer)
		return ;
	r_extern(a, 0, buffer);
	r_extern(b, 0, buffer);
	write(1, "rr\n", 3);
}
