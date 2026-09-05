/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisgutierreztw3nny <matisgutierreztw3    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 19:00:06 by matisgutier       #+#    #+#             */
/*   Updated: 2026/01/23 17:24:53 by matisgutier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>

void	print_hex_lower(va_list args, int *count)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	putnbr_base((unsigned long) nb, "0123456789abcdef");
	*count += get_len_base((unsigned long) nb, "0123456789abcdef");
}
