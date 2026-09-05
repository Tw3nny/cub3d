/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisgutierreztw3nny <matisgutierreztw3    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 22:05:18 by marvin            #+#    #+#             */
/*   Updated: 2025/11/06 22:36:00 by matisgutier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

// recherche une valeur donnée dans une zone memoire -> return l'adresse
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;
	size_t			i;

	tmp = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (tmp[i] == (unsigned char ) c)
			return ((void *) &tmp[i]);
		i++;
	}
	return (NULL);
}
