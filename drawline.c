/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:01:01 by smaddux           #+#    #+#             */
/*   Updated: 2017/12/10 19:45:11 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int draw_line(int x, int y, t_placeholder *view, int color)
{
	int xstart = 0;
	int ystart = 0;
	float calc = 0;
	float jeb = 0;
	if (x > y)
		calc = (float)y / (float)x;
	else if (y > x)
		calc = (float)x / (float)y;

	while(xstart < x && ystart < y)
	{
		mlx_pixel_put(view->hajimari, view->win,  xstart, y - ystart, color);
		if (x > y)
		{
			xstart = xstart + 1;
			jeb = jeb + calc;
			if (((int)jeb / 1) > ((int)(jeb - calc) / 1)) // This cast on second jeb - calc may not be necessary
				ystart = ystart + 1;
		}
		else if (x < y)
		{
			ystart = ystart + 1;
			jeb = jeb + calc;
			if(((int)jeb / 1) > ((int)(jeb - calc) / 1))
				xstart = xstart + 1;
		}
		else
		{
			xstart = xstart + 1;
			ystart = ystart + 1;
		}
		
	}
	return (1);
}