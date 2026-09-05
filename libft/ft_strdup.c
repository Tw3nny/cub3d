/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisgutierreztw3nny <matisgutierreztw3    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 00:56:44 by matisgutier       #+#    #+#             */
/*   Updated: 2025/11/10 17:26:54 by matisgutier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

//alloue et copie une str
char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*dup;

	size = ft_strlen(s1) + 1;
	dup = malloc(sizeof(char) * size);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s1, size);
	return (dup);
}
/*
int	main(void)
{
	char *dst = "";
	char *s1 = "ue ue sa dit quoi"; 
	printf("avant %s\n", dst);
	dst = ft_strdup(s1);
	printf("apres %s\n", dst);
	free(dst);
	return (0);
}*/
