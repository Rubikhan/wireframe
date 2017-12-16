/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:22:23 by smaddux           #+#    #+#             */
/*   Updated: 2017/12/15 17:41:10 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>

#define COEF 10

typedef struct s_vector
{
	int x;
	int y;
	int z;
}			t_vector ; 

typedef struct s_placeholder
{
	void *win;
	void *hajimari;
	char *fullbuf;
	int		max_xwidth;
	int		max_yheight;
	int *xs;
	int *ys;
	int *zs;
	int win_y;
	int win_x;

}			t_placeholder ; 

int     key_down_hook(int kcode, t_placeholder *view);
int		draw_line(int x1, int x2, int y1, int y2, t_placeholder *view, int color);
void	read_entry(t_placeholder *view, char *filename);
int		draw_all_lines(t_placeholder *view);