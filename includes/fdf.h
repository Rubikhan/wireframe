/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:22:23 by smaddux           #+#    #+#             */
/*   Updated: 2017/12/17 23:56:01 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

typedef	struct		s_dl
{
	int steepbool;
	int xstart;
	int ystart;
	int xfin;
	int yfin;
	int tempstart;
	int tempfin;
	int tempx;
	int tempy;
	int dx;
	int dy;
	int derror;
	int error;
	int jy;
	int jx;
}					t_dl;

typedef	struct		s_daw
{
	int max_x;
	int max_y;
	int win_x;
	int win_y;
	int x0;
	int x1;
	int y0;
	int y1;
	int y2;
	int z0;
	int z1;
	int z2;
	int xstep;
	int ystep;
	int i;
	int j;
	int k;
	int cr;
}					t_daw;

typedef	struct		s_placeholder
{
	void	*win;
	void	*hajimari;
	char	*fullbuf;
	int		mxw;
	int		max_yheight;
	int		max_z;
	int		*xs;
	int		*ys;
	int		*zs;
	int		win_y;
	int		win_x;

}					t_placeholder;

int					key_down_hook(int kcode, t_placeholder *view);
int					draw_line(t_daw *daw, int y2, t_placeholder *view);
void				read_entry(t_placeholder *view, char *filename);
int					draw_all_lines(t_placeholder *view);
void				error_handling(int ecode);
t_dl				*dl_helper1(t_daw *daw, int y2);
void				dl_helper2(t_dl *a);
void				dl_helper3(t_dl *a);
void				dl_helper4(t_dl *a);

#endif
