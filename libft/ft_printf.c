/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisgutierreztw3nny <matisgutierreztw3    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 23:33:49 by matisgutier       #+#    #+#             */
/*   Updated: 2026/01/23 17:24:27 by matisgutier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h> // va_list, va_start, va_arg, va_end
#include <stddef.h>
#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

/* va_list = la list des paramettres variables apres le dernier param fix(...)
   va_start = initialise va_list avant de l'utiliser
   (argc = list, format = param fix)
   va_arg(args, type) = recup un argument dans list et avance 
   (args = list, type = type d'argument attendu : int, char etc)
   va_end = liberer la memoire allouer par va_start (meme chose que free) */

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			treat_type(format[i], args, &count);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
