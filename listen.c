/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:17:41 by smaddux           #+#    #+#             */
/*   Updated: 2017/12/07 18:36:44 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

/* int	exit_hook(t_placeholder *screen) */
/* { */
/* 	mlx_destroy_window(screen->id, screen->win); */
/* 	exit(0); */
/* } */

int	key_down_hook(int kcode, t_placeholder *view)
{

/* 	static int a; */
/* 	static int b; */
/* 	static int c; */
/* 	static int color = 0x113366; */


/* 	while(c < 200) */
/* 	{ */
/* 		while (a < 500 && b < 500) */
/* 		{ */
/* 			mlx_pixel_put(view->hajimari, view->win, a, b, color); */
/* 			if (a % 2 == 0) */
/* 			{ */
/* 				a = a + 1; */
/* 			} */
/* 			else if(a % 3 == 0) */
/* 				a = a + 1; */
/* 			else */
/* 			{ */
/* 				b = b + 1; */
/* 				a = a + 1; */
/* 			} */
			
/* 		} */
/* 		color = color + 0x050505; */
/* 		c = c + 1; */
/* 		a = 0 + c; */
/* 		b = 0 + c; */
		
/* 	} */


	printf("kcode: %d\n", kcode);
	if (kcode == 53)
		exit(0);

	return (0);


}