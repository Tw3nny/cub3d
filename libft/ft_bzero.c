/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisgutierreztw3nny <matisgutierreztw3    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 19:14:37 by marvin            #+#    #+#             */
/*   Updated: 2025/11/06 22:31:26 by matisgutier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

// rempli une zone memoire de 0 = memset(..., 0, ...)
void	ft_bzero(void *s, size_t n)
{
	char		*temp;
	size_t		i;

	temp = (char *) s;
	i = 0;
	while (i < n)
	{
		temp[i] = 0;
		i++;
	}
}
