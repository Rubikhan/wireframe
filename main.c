/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:23:59 by smaddux           #+#    #+#             */
/*   Updated: 2017/12/17 22:24:01 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_handling(int ecode)
{
	if (ecode == 0)
	{
		ft_putstr("usage: fdf map_file\n");
		exit(0);
	}
	if (ecode == 1)
	{
		ft_putstr("invalid file\n");
		exit(1);
	}
	else
	{
		ft_putstr("invalid ecode passed O_O\n");
		exit(-1);
	}
}

int		main(int argc, char *argv[])
{
	int				win_y;
	int				win_x;
	t_placeholder	*first;

	if (argc != 2)
		error_handling(0);
	first = malloc(sizeof(t_placeholder));
	first->max_yheight = 0;
	first->mxw = 0;
	read_entry(first, argv[1]);
	first->win_y = 1300;
	first->win_x = 1600;
	win_x = first->win_x;
	win_y = first->win_y;
	first->hajimari = mlx_init();
	first->win = mlx_new_window(first->hajimari, win_x, win_y, argv[1]);
	draw_all_lines(first);
	mlx_key_hook(first->win, key_down_hook, first);
	mlx_loop(first->hajimari);
}
