/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisgutierreztw3nny <matisgutierreztw3    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:58:38 by matisgutier       #+#    #+#             */
/*   Updated: 2026/01/23 17:24:49 by matisgutier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>

void	print_char(va_list args, int *count)
{
	int	c;

	c = va_arg(args, int);
	ft_putchar_fd(c, 1);
	(*count)++;
}
