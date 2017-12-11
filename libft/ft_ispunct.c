/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaddux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 13:24:29 by smaddux           #+#    #+#             */
/*   Updated: 2017/10/13 13:36:21 by smaddux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ispunct(int c)
{
	if (ft_isprint(c) != 1)
		return (0);
	if (ft_isalnum(c) == 1 || c == ' ')
		return (0);
	else
		return (1);
}
