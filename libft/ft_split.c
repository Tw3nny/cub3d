/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matisgutierreztw3nny <matisgutierreztw3    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 02:57:54 by matisgutier       #+#    #+#             */
/*   Updated: 2025/11/24 14:09:44 by matisgutier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

// return un tableau de mot sans les separateurs
// compte le nb de mots 
static int	count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

// calcul la taille des mots  
static int	word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

// libere la memoire alloué en cas d'erreur
static void	ft_free(char **s, size_t nb_words)
{
	size_t	i;

	i = 0;
	while (i < nb_words)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

// rempli le tableau avec les mots donnés
static char	**fill_word(char **result, char const *s, char c, size_t nb_words)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (i < nb_words)
	{
		while (*s == c)
			s++;
		len = word_len(s, c);
		result[i] = ft_substr(s, 0, len);
		if (!result[i])
		{
			ft_free(result, i);
			return (NULL);
		}
		s = s + len;
		i++;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	nb_words;

	if (!s)
		return (NULL);
	nb_words = count_word(s, c);
	result = malloc(sizeof(char *) * (nb_words + 1));
	if (!result)
		return (NULL);
	result = fill_word(result, s, c, nb_words);
	return (result);
}
/*
int	main(void)
{
	size_t	i = 0;
	char	**result = ft_split("ue:ue:sa:dit:quoi", ':');
	while (result[i])
	{
		printf("%s", result[i]);
		i++;
	}
	i = 0;
	while (result[i])
	{
    	free(result[i]);
    	i++;
	}
	free(result);
	return (0);
}*/
