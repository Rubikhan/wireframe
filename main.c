/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:23:59 by smaddux           #+#    #+#             */
/*   Updated: 2017/12/10 19:50:50 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//#include <stdio.h>

int main(int argc, char *argv[])
{
	
	if (argc != 2)
		return (0);

	t_placeholder *first = malloc (sizeof(t_placeholder));

	first->hajimari = mlx_init();
	first->win = mlx_new_window(first->hajimari, 600, 600, argv[1]);
	first->img = mlx_new_image(first->hajimari, 600, 600);

	int z = 0;
	int a = 600;

	while (z <= 600 && a >= 0)
	{

		draw_line(a, z, first, 0xCC2277);

		z += 15;
		a -= 15;
	}

		draw_line(a, z, first, 0xCC2277);

    mlx_key_hook (first->win, key_down_hook, first);
	mlx_loop(first->hajimari);

//	return(26);
}