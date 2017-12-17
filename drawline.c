/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:01:01 by smaddux           #+#    #+#             */
/*   Updated: 2017/12/16 18:33:48 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int draw_line(int x1, int x2, int y1, int y2, t_placeholder *view, int color)
{
	int steepbool = 0;
	int xstart = x1;
	int ystart = y1;
	int xfin = x2;
	int yfin = y2;

	if (abs(xstart - xfin) < abs(ystart - yfin))
	{
		int tempstart = xstart;
		int tempfin = xfin;
		xstart = ystart;
		xfin = yfin;
		ystart = tempstart;
		yfin = tempfin;
		steepbool = 1;
	}

	if(xstart > xfin)
	{
		int tempx = xfin;
		int tempy = yfin;
		xfin = xstart;
		yfin = ystart;
		xstart = tempx;
		ystart = tempy;
	}
	//TRULY UGLY CODE amirite

	int dx = xfin - xstart;
	int dy = yfin - ystart;
	int derror = abs(dy) * 2;
	int error = 0;
	int justy = ystart;
	int justx = xstart;

	while(justx <= xfin)
	{
		if(steepbool)
		{
			mlx_pixel_put(view->hajimari, view->win, justy, justx, color); 
		}
		else
		{
			mlx_pixel_put(view->hajimari, view->win, justx, justy, color); 
		}
		error += derror;
		if(error > dx)
		{
			justy += (yfin > ystart ? 1 : -1);
			error -= dx*2;
		}
		justx++;
	}
	return (1);
}

/* 	shift by center of rotation (xc, yc) coordinates rotation  //center of rotation? */

/* 		shift back by xc and some yc (you might need another y-shift to align with screen edge) scale by y-axis */

/* 		sq = Sqrt(2)/2   //Cos and Sin of 45 */
/* 		x_new = xc + (x_old - xc) * sq - (y_old - yc) * sq */
/* 		y_new = 0.5 * (yc + (x_old - xc) * sq + (y_old - yc) * sq) */
/* 		(probably you have to change sign combination in brackets from (+-)(++) to (++)(-+) */

int draw_all_lines(t_placeholder *view)
{
	int max_x = view->max_xwidth; 
 	int max_y = view->max_yheight; 
	int win_x = view->win_x;
	int win_y = view->win_y;
	int x0 = (win_x / 2) - (win_x/4); // 
	int y0 = (win_y / 2 ) + (win_y / 4); //
	int xstep;
	int ystep;

	int x1;
	int y1;
	int y2;
	int i = 0;
	int j = 0;
	int k = 0;
 	int color = 0x00CC77; 
	int z0 = view->zs[j] * 10;
	int z1;
	int z2;

//THIS IS JUST BAD BAD BAD BAD SAM

	xstep = ((win_x - x0) / ((max_x + max_y))) * 3; 
	ystep = ((win_y - y0) / (max_y )) * 3;
	xstep /= 4;
	ystep /= 4;; 
	if (ystep == 0)
		ystep = 1;
	


//	ystep * max_y == lasty1 - firsty0


	while (view->xs[j])
	{
		while (i < max_x)
		{
 			if ((j + max_x) < max_x * max_y) // dont have this it freeeeeezes 
				z2 = view->zs[j + max_x] * 10;

			z1 = view->zs[j + 1] * 10;
			x1 = x0 + xstep;
			y1 = y0 - ystep - (z1 - z0);
			y2 = y0 - ystep - (z2 - z0);

			
			printf("x0: %d | x1: %d | y0: %d | y1: %d\n", x0, x1, y0, y1);
			draw_line(x0, x1, y0, y1, view, color);  
			draw_line(x0, x1, y0, y2 + ystep*2, view, color);  

			x0 = x1;
			y0 = y1;
			z0 = z1;

			i++;
			j++;
 			color = color + 0x203040; 
		}
		k++;
//		printf("\n- k: %d -", k);
		x0 = (win_x / 2) - (win_x/4) + xstep * k;
//		printf("\n x0: %d", x0);
		y0 = (win_y / 2) + (win_y/4) + ystep * k; //why is this plus ystep * k? WHY
//		printf("\n y0: %d", y0);
		i = 0;
	}
	return (1);
}

//######################################################
//#############COEFFICIENTS#############################
//######################################################
/* { */
	
/* 	int max_x = view->max_xwidth; */
/* 	int max_y = view->max_yheight; */
/* 	int xstep = 20; //18 */
/* 	int ystep = 10; // 9 */
/* 	int winx = 500; */
/* 	int winy = 1000; */
/* 	int i = 0; */
/* 	int j = 0; */
/* 	int thisx = (winx - (xstep/2)*max_x); */

/* 	int nexty; */
/* 	int nextx; */
/* 	int color = 0x00CC77; */
/* 	int thisz = view->zs[j] * 20; */
/* 	int thisy = (winy - xstep*max_y) - thisz; */
/* 	int nextz; */
/* 	int nexty2; */
/* 	int anotherz = view->zs[0 + max_x]; */

/* 	while (view->xs[j]) */
/* 	{ */
/* 		while (i < max_x) */
/* 		{ */
/* 			if ((j + max_x) < max_x * max_y) // dont have this it freeeeeezes */
/* 				anotherz = view->zs[j + max_x] * 20; */

/* 			nextz = view->zs[j + 1] * 20 ; // */
/* 			nexty = thisy - ystep - (nextz - thisz); // on to something */
/* 			nexty2 = thisy - ystep - (anotherz - thisz); // on to something */
/* 			nextx = thisx + xstep; */

/* 			draw_line(thisx, nextx, thisy, nexty, view, color);  */
/* 			draw_line(thisx, nextx, thisy, ((nexty2 + 2*ystep) /\* - anotherz *\/), view, color); */
/* 			color = color + 0x203040; */

/* 			thisx = nextx; */
/* 			thisy = nexty ;   //  */
/* 			thisz = nextz; //  */

/* 			i++; */
/* 			j++; */
/* 		} */
/* 		thisx = (winx -((xstep/2) *max_x) + j ); */
/* 		thisy = (winy -xstep*max_y + (j / 2)); // //need to incorporate z somehow? */
/* 		i = 0; */
		
/* 	} */

	
	

	

/* 	return (1); */

/* } */
//#########################################
//### CLOSE BUT NO CIGAR ##################
//#########################################
/* 	int xstart = xarr[0]; */
/*     int ystart = yarr[0]; */
/* 	int x = xarr[1]; */
/* 	int y = yarr[1]; */

/* 	if (xstart > x) */
/* 	{ */
/* 		int tempx = x; */
/* 		x = xstart; */
/* 		xstart = tempx; */
/* 	} */
/* 	if (ystart > y) */
/* 	{ */
/* 		int tempy = y; */
/* 		y = ystart; */
/* 		ystart = tempy; */
/* 	} */

/*     float calc = 0; */
/*     float jeb = 0; */
/*     if (x > y) */
/*         calc = (float)y / (float)x; */
/*     else if (y > x) */
/*         calc = (float)x / (float)y; */

/*     while(xstart < x && ystart < y) */
/*     { */
/*         mlx_pixel_put(view->hajimari, view->win,  xstart, ystart, color); */
/*         if (x > y) */
/*         { */
/*             xstart = xstart + 1; */
/*             jeb = jeb + calc; */
/*             if (((int)jeb / 1) > ((int)(jeb - calc) / 1)) // This cast on second jeb - calc may not be necessary */
/*                 ystart = ystart + 1; */
/*         } */
/*         else if (x < y) */
/*         { */
/*             ystart = ystart + 1; */
/*             jeb = jeb + calc; */
/*             if(((int)jeb / 1) > ((int)(jeb - calc) / 1)) */
/*                 xstart = xstart + 1; */
/*         } */
/*         else */
/*         { */
/*             xstart = xstart + 1; */
/*             ystart = ystart + 1; */
/*         } */
        
/*     } */
/*     return (1); */




//#########################################
//########ABSOLUTELY NOT GOOD #############
//#########################################


/* 	int xstart = xarr[0]; */
/* 	int ystart = yarr[0]; */
/* 	int x = xarr[1]; */
/* 	int y = yarr[1]; */
/* 	float calc = 0; */
/* 	float jeb = 0; */
/* 	if (x > y) */
/* 		calc = (float)y / (float)x; */
/* 	else if (y > x) */
/* 		calc = (float)x / (float)y; */

/* 	while(xstart != x && ystart != y) */
/* 	{ */
/* 		mlx_pixel_put(view->hajimari, view->win,  xstart,  ystart, color); */
/* 		if (x > y) */
/* 		{ */
/* 			xstart = xstart + 1; */
/* 			jeb = jeb + calc; */
/* 			if (((int)jeb / 1) > ((int)(jeb - calc) / 1)) // This cast on second jeb - calc may not be necessary */
/* 			{ */
/* 				if (ystart < y) */
/* 				{ */
/* 					ystart = ystart + 1; */
/* 				} */
/* 				else if(ystart > y) */
/* 				{ */
/* 					ystart = ystart - 1; */
/* 				} */
/* 			} */
/* 		} */
/* 		else if (x < y) */
/* 		{ */
/* 			ystart = ystart + 1; */
/* 			jeb = jeb + calc; */
/* 			if(((int)jeb / 1) > ((int)(jeb - calc) / 1)) */
/* 			{ */
/* 				if (xstart < x) */
/* 				{ */
/* 					xstart = xstart + 1; */
/* 				} */
/* 				else if (xstart > x) */
/* 				{ */
/* 					xstart = xstart - 1; */
/* 				} */
/* 			} */
/* 		} */
/* 		else */
/* 		{ */
/* 			if (xstart < x && ystart < y) */
/* 			{ */
/* 			xstart = xstart + 1; */
/* 			ystart = ystart + 1; */
/* 			} */
/* 			else */
/* 			{ */
/* 				xstart = xstart - 1; */
/* 				ystart = ystart - 1; */
/* 			} */
/* 		} */
		
/* 	} */
/* 	return (1); */