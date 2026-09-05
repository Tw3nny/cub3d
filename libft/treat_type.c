/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisgutierreztw3nny <matisgutierreztw3    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:15:07 by matisgutier       #+#    #+#             */
/*   Updated: 2026/01/23 17:25:21 by matisgutier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>

void	treat_type(char type, va_list args, int *count)
{
	if (type == 'c')
		print_char(args, count);
	else if (type == 's')
		print_str(args, count);
	else if (type == 'd' || type == 'i')
		print_int(args, count);
	else if (type == 'u')
		print_unsigned(args, count);
	else if (type == 'x')
		print_hex_lower(args, count);
	else if (type == 'X')
		print_hex_upper(args, count);
	else if (type == 'p')
		print_pointer(args, count);
	else if (type == '%')
	{
		ft_putchar_fd('%', 1);
		*count += 1;
	}
}
