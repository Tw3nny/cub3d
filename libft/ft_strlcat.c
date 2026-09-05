/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisgutierreztw3nny <matisgutierreztw3    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:55:11 by marvin            #+#    #+#             */
/*   Updated: 2025/11/10 17:26:31 by matisgutier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include <stdio.h>

// concatene 2 str avec taille max + NULL
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	j;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	j = 0;
	if (dstsize <= len_dst)
		return (dstsize + len_src);
	while (src[j] != '\0' && (len_dst + j) < dstsize - 1)
	{
		dst[len_dst + j] = src[j];
		j++;
	}
	dst[len_dst + j] = '\0';
	return (len_dst + len_src);
}
/*
int	main(void)
{
	char dst[17] = "ue ue ";
	char src[] = "sa dit quoi";
	printf("%ld", ft_strlcat(dst, src, 17));
	return (0);
}*/
