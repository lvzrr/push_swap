/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:33:15 by jaicastr          #+#    #+#             */
/*   Updated: 2025/06/10 20:34:54 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_sort_vec(t_vec *v)
{
	size_t		i;
	ssize_t		key;
	ssize_t		*data;
	ssize_t		j;

	if (!v || v->size <= 1)
		return ;
	data = (ssize_t *)v->data;
	i = 1;
	while (i < v->size)
	{
		key = data[i];
		j = i - 1;
		while (j != ((ssize_t) - 1) && data[j] > key)
		{
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = key;
		i++;
	}
}

t_u8	check_sorted(t_vec *v)
{
	size_t		i;
	ssize_t		*data;

	if (!v || v->size <= 1)
		return (1);
	data = (ssize_t *)v->data;
	i = 1;
	while (i < v->size)
	{
		if (data[i - 1] > data[i])
			return (0);
		i++;
	}
	return (1);
}
