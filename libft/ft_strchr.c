/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisgutierreztw3nny <matisgutierreztw3    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:15:29 by marvin            #+#    #+#             */
/*   Updated: 2025/11/10 17:27:04 by matisgutier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include <stdio.h>

// trouve la 1ere occurence d'un char dans une str -> return l'adresse
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == ((char) c))
		return ((char *) &s[i]);
	return (0);
}
/*
int	main(void)
{
	const char	str[] = "Bonjour";
	int	c = 'j';
	printf("%s\n", strchr(str, c));
	return (0);
}*/
