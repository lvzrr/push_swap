/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:03:22 by jaicastr          #+#    #+#             */
/*   Updated: 2025/05/31 13:07:52 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_vec *stack, t_u8 name)
{
	if (!stack || stack->size < 2)
		return ;
	ft_memswap((t_u8 *)(stack->data) + (stack->sizeof_type * (stack->size - 1)),
		(t_u8 *)stack->data + (stack->sizeof_type * (stack->size - 2)),
		stack->sizeof_type);
	if (name == 1)
		write(1, "sa\n", 3);
	else if (name == 2)
		write(1, "sb\n", 3);
}
