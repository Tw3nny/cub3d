/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisgutierreztw3nny <matisgutierreztw3    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 03:57:58 by matisgutier       #+#    #+#             */
/*   Updated: 2025/11/10 17:12:22 by matisgutier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

// compare 2 zones memoire sur une taille max donnée
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	size_t			i;

	i = 0;
	tmp1 = (unsigned char *) s1;
	tmp2 = (unsigned char *) s2;
	while (i < n)
	{
		if (tmp1[i] != tmp2[i])
			return ((unsigned char) tmp1[i] - (unsigned char) tmp2[i]);
		i++;
	}
	return (0);
}
