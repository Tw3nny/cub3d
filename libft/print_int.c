/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisgutierreztw3nny <matisgutierreztw3    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:31:37 by matisgutier       #+#    #+#             */
/*   Updated: 2026/01/23 17:25:02 by matisgutier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>

int	get_len(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		len++;
		nb = -nb;
	}
	if (nb == 0)
		len++;
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

void	print_int(va_list args, int *count)
{
	int	nb;

	nb = va_arg(args, int);
	ft_putnbr_fd(nb, 1);
	*count += get_len(nb);
}
