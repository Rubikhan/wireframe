/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:01:01 by smaddux           #+#    #+#             */
/*   Updated: 2017/12/14 14:28:29 by smaddux          ###   ########.fr       */
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

int draw_all_lines(t_placeholder *view)
{
	
	int max_x = view->max_xwidth;
	int max_y = view->max_yheight;
	int xstep = 18;
	int ystep = 9;
	int winx = 300;
	int winy = 600;
	int i = 0;
	int j = 0;
	int thisx = (winx - (xstep/2)*max_x);

	int nexty;
	int nextx;
	int color = 0x007722;
	int thisz = view->zs[j] * 20;
	int thisy = (winy - xstep*max_y) - thisz;
	int nextz;
	int nexty2;
	int anotherz = view->zs[0 + max_x];

	while (view->xs[j])
	{
		while (i < max_x)
		{
			if ((j + max_x) < max_x * max_y) // dont have this it freeeeeezes
				anotherz = view->zs[j + max_x] * 20;

			nextz = view->zs[j + 1] * 20 ; //
			nexty = thisy - ystep - (nextz - thisz); // on to something
			nexty2 = thisy - ystep - (anotherz - thisz); // on to something
			nextx = thisx + xstep;

			draw_line(thisx, nextx, thisy, nexty, view, color); 
			draw_line(thisx, nextx, thisy, ((nexty2 + 2*ystep) /* - anotherz */), view, color);
			color = color + 0x203040;

			thisx = nextx;
			thisy = nexty ;   // 
			thisz = nextz; // 

			i++;
			j++;
		}
		thisx = (winx -((xstep/2) *max_x) + j );
		thisy = (winy -xstep*max_y + (j / 2)); // //need to incorporate z somehow?
		i = 0;
		
	}

	
	

	

	return (1);

}


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