/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:30:04 by ybitton           #+#    #+#             */
/*   Updated: 2017/05/17 14:18:24 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int			ft_compte(char const *s, char c)
{
	unsigned int	i;
	int				compteur;

	i = 0;
	compteur = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			compteur++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (compteur);
}

static char			**ft_split(char const *s, char c, char **str)
{
	int i;
	int count;
	int count2;
	int len;

	i = 0;
	count = 0;
	while (s[i])
	{
		count2 = 0;
		while (s[i] == c)
			i++;
		len = i;
		while (s[len] && s[len] != c)
			len++;
		if (len > i)
		{
			str[count] = (char *)malloc(sizeof(char) * (len - i + 1));
			while (i < len)
				str[count][count2++] = s[i++];
			str[count++][count2] = '\0';
		}
	}
	str[count] = NULL;
	return (str);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**str;

	if (s == NULL)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (ft_compte(s, c) + 1));
	if (str == NULL)
		return (NULL);
	return (ft_split(s, c, str));
}
