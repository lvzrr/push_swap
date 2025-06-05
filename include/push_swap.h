/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:02:05 by jaicastr          #+#    #+#             */
/*   Updated: 2025/05/30 18:02:07 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lft.h"

// PIPELINE:

t_u8	eat(char *s, t_vec *v);

// OPS:
void	s(t_vec *a, t_u8 opt);
void	ss(t_vec *a, t_vec *b);
void	p(t_vec *a, t_vec *b, t_u8 t);
void	r(t_vec *s, t_u8 t);
void	r_extern(t_vec *s, t_u8 t, t_u8 *buffer);
void	rr(t_vec *a, t_vec *b);
void	rr_extern(t_vec *a, t_vec *b, t_u8 *buf);
void	rrx(t_vec *a, t_u8 t);
void	rrx_extern(t_vec *a, t_u8 t, t_u8 *buf);
void	rrr(t_vec *a, t_vec *b);
void	rrr_extern(t_vec *a, t_vec *b, t_u8 *buf);
t_u8	lookup(t_vec *v, ssize_t n);
void	*get_min(t_vec *v);
#endif
