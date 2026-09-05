/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisgutierreztw3nny <matisgutierreztw3    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:50:34 by matisgutier       #+#    #+#             */
/*   Updated: 2025/11/06 22:44:55 by matisgutier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

// alloue de la memoire et concatene 2 chaine dedans 
char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	join = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, len_s1 + len_s2 + 1);
	ft_strlcat(join, s2, len_s1 + len_s2 + 1);
	return (join);
}
/*
int	main(void)
{
	char	*join = ft_strjoin("ue ue ", "sa dit quoi");
	printf("%s", join);
	free(join);
	return (0);
}*/