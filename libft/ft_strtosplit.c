/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtosplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 14:19:04 by ybitton           #+#    #+#             */
/*   Updated: 2017/05/18 11:53:49 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int			ft_compte(char const *s, char c, char c_bis)
{
	unsigned int	i;
	int				compteur;

	i = 0;
	compteur = 0;
	while (s[i])
	{
		while (s[i] == c || s[i] == c_bis)
			i++;
		if (s[i] != '\0')
			compteur++;
		while (s[i] && (s[i] != c) && (s[i] != c_bis))
			i++;
	}
	return (compteur);
}

static char			**ft_split(char const *s, char c, char **str, char c_bis)
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
		while (s[i] == c || s[i] == c_bis)
			i++;
		len = i;
		while (s[len] && (s[len] != c) && (s[len] != c_bis))
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

char				**ft_strtwosplit(char const *s, char c, char c_bis)
{
	char	**str;

	if (s == NULL)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (ft_compte(s, c, c_bis) + 1));
	if (str == NULL)
		return (NULL);
	return (ft_split(s, c, str, c_bis));
}
