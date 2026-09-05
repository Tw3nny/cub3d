/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tw3nny <tw3nny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 21:40:42 by tw3nny            #+#    #+#             */
/*   Updated: 2026/08/04 22:56:27 by tw3nny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_byte(char *str, int *i, unsigned int *value)
{
	unsigned int	n;
	int				start;

	n = 0;
	start = *i;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		n = n * 10 + (str[*i] - '0');
		if (n > 255)
			return (0);
		(*i)++;
	}
	if (*i == start)
		return (0);
	*value = n;
	return (1);
}

int	parse_color(char *str, unsigned int *color)
{
	unsigned int	rgb[3];
	unsigned int	j;
	int				i;

	i = 0;
	j = 0;
	while (j < 3)
	{
		if (!parse_byte(str, &i, &rgb[j]))
			return (0);
		if (j < 2)
		{
			if (str[i] != ',')
				return (0);
			i++;
		}
		j++;
	}
	if (str[i] != '\0')
		return (0);
	*color = rgb[0] * 65536 + rgb[1] * 256 + rgb[2];
	return (1);
}
