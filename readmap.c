/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 19:59:14 by smaddux           #+#    #+#             */
/*   Updated: 2017/12/17 16:30:14 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_line_points(t_placeholder *view, char **str, int callcount)
{
	int i;
	int j;
	int k;

	k = 0;
	i = callcount * view->max_xwidth;
	j = i - view->max_xwidth;
	while (j < i)
	{
		view->xs[j + view->max_xwidth] = k + 1;
		view->ys[j + view->max_xwidth] = callcount + 1;
		view->zs[j + view->max_xwidth] = ft_atoi(str[k++]);
		j++;
	}
}

void	get_points(t_placeholder *view, char *filename)
{
	int		w;
	int		i;
	int		fd;
	char	*line;
	char	**str;

	i = 0;
	w = view->max_xwidth;
	fd = open(filename, O_RDONLY);
	while (i < view->max_yheight)
	{
		get_next_line(fd, &line);
		str = ft_strsplit(line, ' ');
		get_line_points(view, str, i);
		i++;
		line = NULL;
	}
	close(fd);
}

void	pre_points(t_placeholder *view, char *filename)
{
	int mh;
	int mw;

	mh = view->max_yheight;
	mw = view->max_xwidth;
	view->xs = ft_memalloc(sizeof(int) * ((mh * mw) + 1));
	view->ys = ft_memalloc(sizeof(int) * ((mh * mw) + 1));
	view->zs = ft_memalloc(sizeof(int) * ((mh * mw) + 1));
	get_points(view, filename);
}

void	check_isdigit(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) != 1)
			error_handling(1);
		i++;
	}
}

/*
**consider accounting for get_next_line read error
*/

void	read_entry(t_placeholder *view, char *filename)
{
	int		fd;
	char	*line;
	char	**jeb;
	int		w;
	int		h;

	h = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		error_handling(1);
	while (get_next_line(fd, &line))
	{
		w = 0;
		jeb = ft_strsplit(line, ' ');
		while (jeb[w])
			check_isdigit(jeb[w++]);
		if (view->max_xwidth != 0 && ((view->max_xwidth < w - 1) || (view->max_xwidth > w - 1)))
			error_handling(1);
		view->max_xwidth = w - 1;
		h++;
		free(line);
		free(jeb);
	}
	view->max_yheight = h - 1;
	close(fd);
	pre_points(view, filename);
}
