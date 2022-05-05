/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggobert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:11:35 by ggobert           #+#    #+#             */
/*   Updated: 2022/05/05 11:11:37 by ggobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(void)
{
	char	*f = "3 -27 59 289 186 66 429 256 96 200 103 295 477 127 364 220 81 41 109 42 404 235 342 351 208 345 419 440 75 6 442 250 -74 414 332 270 291 416 -30 90 248 -20 94 -83 -69 266 79 155 360 304 317 89 343 93 -14 348 -40 207 -62 -55 -94 290 51 279 39 -52 71 107 252 315 48 -33 185 378 376 2 320 143 188 152 237 213 27 1 172 -53 422 464 -87 383 258 308 175 380 296 282 147 314 5 495";
	t_list1	*a = reader(f);
	t_list1	*b = 0;
	int		*m = parsing_int(f);
	int		len = 0;
	int		*lis;

	ft_printlst(a);
	printf("\nLIS a :\n\n");
	ret_lis(&lis, m, nbr_of(f));
	len += push_lis(&a, &b, nbr_of(f), lis);
	ft_printlst(a);
	printf("\nlist b :\n\n");
	ft_printlst(b);
	printf("..........\n");
	push_swap(&a, &b);
	while (a->content != smallest_lst(a))
		rotate(&a);
	ft_printlst(a);
	printf("len = %d\n", len);
}
