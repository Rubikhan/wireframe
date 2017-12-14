/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 19:59:14 by smaddux           #+#    #+#             */
/*   Updated: 2017/12/12 20:17:21 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void print_arrval(t_placeholder *view)
{
	int i = 0;
	while (i < view->max_xwidth * view->max_yheight)
	{
		
		printf("(%d, %d, %d) \n", view->xs[i], view->ys[i], view->zs[i]);
		i++;
	}
}

void get_line_points(t_placeholder *view, char **str, int callcount)
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
	int w;
	int h;
	int i;
	int fd;
	char *line;
	char **str;
	
	i = 0;
	w = view->max_xwidth;
	h = view->max_yheight;
	printf("FROM GET_POINTS\nw: %d h: %d\n", w, h);
	fd = open(filename, O_RDONLY);
	while (i < h)
	{
		get_next_line(fd, &line);
		str = ft_strsplit(line, ' ');
		get_line_points(view, str, i);
//		free (str);
		i++;
		line = NULL;
	}
	print_arrval(view);
	close(fd);
}

void	pre_points(t_placeholder *view, char *filename)
{
	//I hope my atoi is up to this
	// I guess I could open close in here? idk
	view->xs = ft_memalloc(sizeof(int) * ((view->max_yheight * view->max_xwidth) + 1));
	view->ys = ft_memalloc(sizeof(int) * ((view->max_yheight * view->max_xwidth) + 1));
	view->zs = ft_memalloc(sizeof(int) * ((view->max_yheight * view->max_xwidth) + 1));
	get_points(view, filename);
	

}

void	read_entry(t_placeholder *view, char *filename)
{
	int fd;
	char *line;
	char **jeb;
	int w = 0;
	int h = 0;
	int i;
	view->max_xwidth = 0;
	view->max_yheight = 0;
	
	if((fd = open(filename, O_RDONLY)) == -1)
	{
		printf("file discriptor error");
		exit(0);
	}

	
 	while(get_next_line(fd, &line))  //account for read errors perhaps?
 	{ 
		jeb = ft_strsplit(line, ' ');
		while (jeb[w])
		{
			i = 0;
			while(jeb[w][i]) //This while loop detects non-numeric (invalid) z values
			{
				if(ft_isdigit(jeb[w][i]) != 1)
				{
					printf("Rudolph's nose brings all the does out to the yard");
					exit(0);
				}
				i++;
			}
			w++;
		}
		if(view->max_xwidth != 0 && ((view->max_xwidth < w - 1) || (view->max_xwidth > w - 1))) // we gucci?
		{
			printf("tis the season to pass invalid files");
			exit (0);
		}
		view->max_xwidth = w - 1; //
		h++;
		w = 0;
 		free(line); 
		free(jeb); //yo this worked without freeing jeb wtf
 	} 
	view->max_yheight = h - 1; //
	close (fd);
	pre_points(view, filename);
}




//###JUST PROOF OF READ/RETURN CONCEPT###
/* 	while(get_next_line(fd, &line)) */
/* 	{ */
/* 		if(!fullbuf) */
/* 		{ */
/* 			fullbuf = ft_strdup(line); */
/* 			fullbuf = ft_strjoinf(fullbuf, "\n"); */
/* 		} */
/* 		else */
/* 		{ */
/* 			fullbuf = ft_strjoinf(fullbuf, line); */
/* 			fullbuf = ft_strjoinf(fullbuf, "\n"); */
/* 		} */
/* 		free(line); */
/* 	} */

/* 	return(fullbuf); */
//###JUST PROOF OF READ/RETURN CONCEPT###