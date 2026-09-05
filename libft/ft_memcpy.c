/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisgutierreztw3nny <matisgutierreztw3    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 23:44:32 by marvin            #+#    #+#             */
/*   Updated: 2025/11/10 17:28:25 by matisgutier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include <stdio.h>

// copie une zone memoire vers une autre
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	size_t			i;

	if (!dst && !src)
		return (dst);
	tmp1 = (unsigned char *) dst;
	tmp2 = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		tmp1[i] = tmp2[i];
		i++;
	}
	return (dst);
}
/*
int	main(void)
{
	char dst[17];
	char src[] = "ue ue sa dit quoi";
	printf("avant :%s\n", dst);
	ft_memcpy(dst,src, 17);
	printf("apres :%s", dst);
	return (0);

}*/
