/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:17:41 by smaddux           #+#    #+#             */
/*   Updated: 2017/12/18 10:22:26 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_down_hook(int kcode, t_placeholder *view)
{
	void *a;

	a = view;
	if (kcode == 53)
		exit(0);
	return (0);
}

t_dl	*dl_helper1(t_daw *daw, int y2)
{
	t_dl *a;

	a = malloc(sizeof(t_dl));
	a->steepbool = 0;
	a->xstart = daw->x0;
	a->ystart = daw->y0;
	a->xfin = daw->x1;
	a->yfin = y2;
	return (a);
}

void	dl_helper2(t_dl *a)
{
	a->tempstart = a->xstart;
	a->tempfin = a->xfin;
	a->xstart = a->ystart;
	a->xfin = a->yfin;
	a->ystart = a->tempstart;
	a->yfin = a->tempfin;
	a->steepbool = 1;
}

void	dl_helper3(t_dl *a)
{
	a->tempx = a->xfin;
	a->tempy = a->yfin;
	a->xfin = a->xstart;
	a->yfin = a->ystart;
	a->xstart = a->tempx;
	a->ystart = a->tempy;
}

void	dl_helper4(t_dl *a)
{
	a->dx = a->xfin - a->xstart;
	a->dy = a->yfin - a->ystart;
	a->derror = ft_abs(a->dy) * 2;
	a->error = 0;
	a->jy = a->ystart;
	a->jx = a->xstart;
}
