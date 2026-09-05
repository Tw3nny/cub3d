/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisgutierreztw3nny <matisgutierreztw3    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:37:57 by matiguti          #+#    #+#             */
/*   Updated: 2026/01/23 17:25:07 by matisgutier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>

void	print_pointer(va_list args, int *count)
{
	unsigned long	ptr;

	ptr = va_arg(args, unsigned long);
	if (ptr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		*count += 5;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		putnbr_base(ptr, "0123456789abcdef");
		*count += get_len_base(ptr, "0123456789abcdef") + 2;
	}
}
