/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:23:59 by smaddux           #+#    #+#             */
/*   Updated: 2017/12/16 17:40:34 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int get_max_z(int *zarr)
{
	int i;
	i = 1;
	int store;
	store = zarr[0]; 

	while (zarr[i])
	{
		if (store < zarr[i])
			store = zarr[i];
		i++;
	}

	return (store);
}

int main(int argc, char *argv[])
{
	
	if (argc != 2)
		return (0);

	t_placeholder *first = malloc (sizeof(t_placeholder));

	char *str;
	int fd;

	read_entry(first, argv[1]);

	int max_x = first->max_xwidth;	
	int max_y = first->max_yheight;
	int max_z = get_max_z(first->zs);
	
//THIS IS JUST BAD SAM YOU KNOW IT

	first->win_y = 900;
	first->win_x = 1600;

	int win_x = first->win_x;
	int win_y = first->win_y;


	first->hajimari = mlx_init();
	first->win = mlx_new_window(first->hajimari, win_x  , win_y  , argv[1]);
//	first->img = mlx_new_image(first->hajimari, 600, 600);

	printf("width: %d height: %d\n", first->max_xwidth, first->max_yheight);

 	int x1 = 0; 
 	int x2 = 0;
	int y1 = first->win_y;
	int y2 = 0;

 	while (x2 <= first->win_x) 
 	{ 

 		draw_line(x1, x2, y1, y2, first, 0xCC2277); 
		x2 = x2 + COEF;
		y1 = y1 - COEF;

 	} 

	draw_all_lines(first);

	printf("MAX Z: %d\n", max_z);

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