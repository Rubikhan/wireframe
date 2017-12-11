/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:22:23 by smaddux           #+#    #+#             */
/*   Updated: 2017/12/10 20:02:50 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <math.h>

typedef struct s_placeholder
{
	void *win;
	void *hajimari;
	void *img;
	//win
}			t_placeholder ; 

int     key_down_hook(int kcode, t_placeholder *view);
int		draw_line(int x, int y, t_placeholder *view, int color);