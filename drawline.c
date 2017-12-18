/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:01:01 by smaddux           #+#    #+#             */
/*   Updated: 2017/12/17 17:22:31 by smaddux          ###   ########.fr       */
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

t_daw	*daw_helper(t_placeholder *view)
{
	t_daw *all = malloc(sizeof(t_daw));
	all->max_x = view->max_xwidth; 
	all->max_y = view->max_yheight;
	all->win_x = view->win_x;
	all->win_y = view->win_y;
	all->x0 = (all->win_x / 2) - (all->win_x / 4);
	all->y0 = (all->win_y / 2) + (all->win_y / 4) - 100; 
	all->i = 0;
	all->j = 0;
	all->k = 0;
	all->color = 0xFFFFFF;
	all->xstep = ((all->win_x - all->x0) / ((all->max_x + all->max_y))) * 3;
	all->ystep = ((all->win_y - all->y0) / (all->max_y)) * 2;
	all->xstep /= 4;
	all->ystep /= 4;
	if (all->ystep < 3)
		all->ystep = 3;
	if (all->xstep < 3)
		all->xstep = 4;
	all->z0 = view->zs[0] * (all->ystep/2) * 3;
	return (all);
}

int draw_all_lines(t_placeholder *view)
{
	t_daw *a;
	a = daw_helper(view);
	while (view->xs[a->j])
	{
		while (a->i < a->max_x)
		{
 			if ((a->j + a->max_x) < a->max_x * a->max_y)
				a->z2 = view->zs[a->j + a->max_x] * (a->ystep/2) * 3;
			else
				a->z2 = a->z1;
			a->z1 = view->zs[a->j + 1] * (a->ystep/2) * 3;
			a->x1 = a->x0 + a->xstep;
			a->y1 = a->y0 - a->ystep - (a->z1 - a->z0);
			a->y2 = a->y0 - a->ystep - (a->z2 - a->z0);
			draw_line(a->x0, a->x1, a->y0, a->y1, view, a->color);  
			draw_line(a->x0, a->x1, a->y0, a->y2 + a->ystep*2, view, a->color);  
			a->x0 = a->x1;
			a->y0 = a->y1;
			a->z0 = a->z1;
			a->i++;
			a->j++;
		}
		a->k++;
		a->x0 = (a->win_x / 2) - (a->win_x/4) + a->xstep * a->k;
		a->y0 = (a->win_y / 2) + (a->win_y/4) + a->ystep * a->k - 100;
		a->i = 0;
	}
	return (1);
}
