/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:01:01 by smaddux           #+#    #+#             */
/*   Updated: 2017/12/18 11:29:22 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		draw_line(t_daw *daw, int y2, t_placeholder *view)
{
	t_dl *a;

	a = dl_helper1(daw, y2);
	if (ft_abs(a->xstart - a->xfin) < ft_abs(a->ystart - a->yfin))
		dl_helper2(a);
	if (a->xstart > a->xfin)
		dl_helper3(a);
	dl_helper4(a);
	while (a->jx <= a->xfin)
	{
		if (a->steepbool)
			mlx_pixel_put(view->hajimari, view->win, a->jy, a->jx, daw->cr);
		else
			mlx_pixel_put(view->hajimari, view->win, a->jx, a->jy, daw->cr);
		a->error += a->derror;
		if (a->error > a->dx)
		{
			a->jy += (a->yfin > a->ystart ? 1 : -1);
			a->error -= a->dx * 2;
		}
		a->jx++;
	}
	return (1);
}

t_daw	*daw_helper(t_placeholder *view)
{
	t_daw *all;

	all = malloc(sizeof(t_daw));
	all->max_x = view->mxw;
	all->max_y = view->max_yheight;
	all->win_x = view->win_x;
	all->win_y = view->win_y;
	all->x0 = (all->win_x / 2) - (all->win_x / 4);
	all->y0 = (all->win_y / 2) + (all->win_y / 4) - 100;
	all->i = 0;
	all->j = 0;
	all->k = 0;
	all->cr = 0xFFFFFF;
	all->xstep = ((all->win_x - all->x0) / ((all->max_x + all->max_y))) * 3;
	all->ystep = ((all->win_y - all->y0) / (all->max_y)) * 2;
	all->xstep /= 4;
	all->ystep /= 4;
	if (all->ystep < 3)
		all->ystep = 3;
	if (all->xstep < 3)
		all->xstep = 4;
	all->z0 = view->zs[0] * (all->ystep / 2) * 3;
	return (all);
}

void	daw_loop_helper(t_daw *a)
{
	a->x0 = a->x1;
	a->y0 = a->y1;
	a->z0 = a->z1;
	a->i++;
	a->j++;
}

int		draw_all_lines(t_placeholder *view)
{
	t_daw *a;

	a = daw_helper(view);
	while (view->xs[a->j])
	{
		while (a->i < a->max_x)
		{
			a->z1 = view->zs[a->j + 1] * (a->ystep / 2) * 3;
			if ((a->j + a->max_x) < a->max_x * a->max_y)
				a->z2 = view->zs[a->j + a->max_x] * (a->ystep / 2) * 3;
			else
				a->z2 = a->z1;
			a->x1 = a->x0 + a->xstep;
			a->y1 = a->y0 - a->ystep - (a->z1 - a->z0);
			a->y2 = a->y0 + a->ystep - (a->z2 - a->z0);
			draw_line(a, a->y1, view);
			draw_line(a, a->y2, view);
			daw_loop_helper(a);
		}
		a->k++;
		a->x0 = (a->win_x / 2) - (a->win_x / 4) + a->xstep * a->k;
		a->y0 = (a->win_y / 2) + (a->win_y / 4) + a->ystep * a->k - 100;
		a->i = 0;
	}
	return (1);
}
