/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:10:19 by jaicastr          #+#    #+#             */
/*   Updated: 2025/06/01 13:18:14 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_u8	eat(char *s, t_vec *v)
{
	char	**split;
	size_t	i;
	int		x;

	split = ft_split(s, ' ');
	if (!split)
		return (1);
	i = 0;
	while (split[i])
	{
		x = ft_atoi(split[i++]);
		ft_vec_push(v, &x, 1);
		ft_free((void **)&split[i - 1]);
	}
	return (ft_free_array((void ***)&split), 0);
}
