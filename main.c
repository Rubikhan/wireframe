/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:23:59 by smaddux           #+#    #+#             */
/*   Updated: 2017/12/13 21:14:52 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	
	if (argc != 2)
		return (0);

	t_placeholder *first = malloc (sizeof(t_placeholder));

	char *str;
	int fd;

	read_entry(first, argv[1]);

	first->hajimari = mlx_init();
	first->win = mlx_new_window(first->hajimari, 600, 600, argv[1]);
//	first->img = mlx_new_image(first->hajimari, 600, 600);

	printf("width: %d height: %d\n", first->max_xwidth, first->max_yheight);

 	int x1 = 0; 
 	int x2 = 0;
	int y1 = 600;
	int y2 = 0;

 	while (x2 <= 600) 
 	{ 

 		draw_line(x1, x2, y1, y2, first, 0xCC2277); 
		x2 = x2 + 20;
		y1 = y1 - 20;

 	} 

	draw_all_lines(first);

	

/* 	draw_line(a, z, first, 0xCC2277); */




    mlx_key_hook (first->win, key_down_hook, first);
	mlx_loop(first->hajimari);

//	return(26);
}

/* void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color) {  */
/*     bool steep = false;  */
/*     if (std::abs(x0-x1)<std::abs(y0-y1)) {  */
/* 		std::swap(x0, y0);  */
/* 		std::swap(x1, y1);  */
/*         steep = true;  */
/*     }  */
/*     if (x0>x1) {  */
/* 		std::swap(x0, x1);  */
/* 		std::swap(y0, y1);  */
/*     }  */
/*     int dx = x1-x0;  */
/*     int dy = y1-y0;  */
/*     int derror2 = std::abs(dy)*2;  */
/*     int error2 = 0;  */
/*     int y = y0;  */
/*     for (int x=x0; x<=x1; x++) {  */
/*         if (steep) {  */
/*             image.set(y, x, color);  */
/*         } else {  */
/*             image.set(x, y, color);  */
/*         }  */
/*         error2 += derror2;  */
/*         if (error2 > dx) {  */
/*             y += (y1>y0?1:-1);  */
/*             error2 -= dx*2;  */
/*         }  */
/*     }  */
/* } */