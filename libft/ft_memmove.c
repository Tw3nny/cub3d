/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisgutierreztw3nny <matisgutierreztw3    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 23:59:53 by marvin            #+#    #+#             */
/*   Updated: 2025/11/10 17:10:48 by matisgutier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include <stdio.h>

// copie une zone memoire meme si chevauchement
// 1ere boucle = copie a l'envers si dst est apres src
// 2eme boucle = si dst est avant src aucun pb on copie normalement
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	if (tmp_dst > tmp_src)
	{
		i = len;
		while (i-- > 0)
			tmp_dst[i] = tmp_src[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			tmp_dst[i] = tmp_src[i];
			i++;
		}
	}
	return (dst);
}

/*
int	main(void)
{
	char dst[] ="12345678901234567890";
	char src[] = "ue ue sa dit quoi";
	printf("avant : %s\n", dst);
	ft_memmove(dst,src, 17);
	printf("apres : %s", dst);
	return (0);

}*/
