/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisgutierreztw3nny <matisgutierreztw3    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:15:20 by matisgutier       #+#    #+#             */
/*   Updated: 2025/11/11 15:31:01 by matisgutier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	treat_type(char type, va_list args, int *count);
void	print_char(va_list args, int *count);
void	print_str(va_list args, int *count);
void	print_int(va_list args, int *count);
void	print_unsigned(va_list args, int *count);
void	print_hex_lower(va_list args, int *count);
void	print_hex_upper(va_list args, int *count);
void	putnbr_base(unsigned long nb, char *base);
int		get_len_base(unsigned long nb, char *base);
void	print_pointer(va_list args, int *count);

#endif