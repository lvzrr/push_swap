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

static inline void	load(t_vec *v, int argc, char **argv)
{
	int		i;
	int		tmp;

	i = 1;
	while (i < argc)
	{
		if (!ft_strchr(argv[i], ' '))
		{
			tmp = ft_atoi(argv[i++]);
			ft_vec_push(v, &tmp, 1);
		}
		else
			eat(argv[i++], v);
	}
}

int	main(int argc, char **argv)
{
	t_vec	v;

	if (argc < 2 || !argv[1] || !argv[1][0])
		return (1);
	if (!check_args(argc, argv))
		return (write(2, "Error\n", 6), 1);
	v = ft_vec(500, sizeof(int));
	load(&v, argc, argv);
	ft_vec_rev(&v);
	for (size_t i = 0; i < v.size; i++)
		printf("%d\n", *((int *)ft_vec_get(&v, i)));
	// TODO
	ft_free(&v.data);
	return (0);
}
