/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 20:01:35 by umoff             #+#    #+#             */
/*   Updated: 2019/05/21 14:34:23 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_words(char const *s, char c)
{
	size_t w;

	w = 0;
	while (*s)
	{
		if (*s != c)
			w++;
		while (*s != c && *(s + 1))
			s++;
		s++;
	}
	return (w);
}

static size_t	ft_letter(char const **s, char c)
{
	size_t l;

	if (*s == '\0')
		return (0);
	l = 0;
	while (**s != '\0' && **s == c)
		(*s)++;
	while (**s != '\0' && **s != c)
	{
		(*s)++;
		l++;
	}
	return (l);
}

static void		ft_fresh_str(char ***s)
{
	while (**s != '\0')
	{
		free(**s);
		s++;
	}
	free(*s);
	*s = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array_str;
	size_t	i;
	size_t	count_word;
	size_t	len_word;

	if (!s)
		return (0);
	count_word = ft_words(s, c);
	if (!(array_str = (char**)malloc(sizeof(char*) * (count_word + 1))))
		return (0);
	i = 0;
	while (i < count_word)
	{
		len_word = ft_letter(&s, c);
		if (len_word == 0)
			return (0);
		if (!(array_str[i] = ft_strndup(s - len_word, len_word)))
		{
			ft_fresh_str(&array_str);
			return (0);
		}
		i++;
	}
	array_str[count_word] = NULL;
	return (array_str);
}
