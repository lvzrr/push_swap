/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:06:59 by jaicastr          #+#    #+#             */
/*   Updated: 2025/05/30 18:08:32 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static inline t_u8	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!argv[i] || !argv[i][0]
			|| !ft_isnumeric(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

static inline t_u8	load(t_vec *v, int argc, char **argv)
{
	int		i;
	ssize_t	tmp;

	i = 1;
	while (i < argc)
	{
		if (!ft_strchr(argv[i], ' '))
		{
			tmp = ft_atol(argv[i++]);
			if (tmp > INT_MAX || tmp < INT_MIN || lookup(v, tmp))
				return (0);
			ft_vec_push(v, &tmp, 1);
		}
		else
			if (eat(argv[i++], v))
				return (0);
	}
	return (1);
}

void	dispatch(t_vec *a, t_vec *b)
{
	if (a->size == 2 && *(ssize_t *)ft_vec_get(a, 0)
		> *(ssize_t *)ft_vec_get(a, 1))
		s(a, 1);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_vec	v;
	t_vec	w;

	if (argc < 2 || !argv[1] || !argv[1][0])
		return (1);
	if (!check_args(argc, argv))
		return (write(2, "Error\n", 6), 1);
	v = ft_vec(500, sizeof(ssize_t));
	w = ft_vec(500, sizeof(ssize_t));
	if (!load(&v, argc, argv))
		return (ft_free(&v.data), write(2, "Error\n", 6), 1);
	ft_vec_rev(&v);
	if (check_sorted(&v))
		return (0);
	dispatch(&v, &w);
	ft_free(&v.data);
	ft_free(&w.data);
	return (0);
}
