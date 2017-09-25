/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:44:02 by ybitton           #+#    #+#             */
/*   Updated: 2016/12/15 19:07:44 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <string.h>

static size_t			ft_trimlen(char *s)
{
	size_t				i;
	size_t				spaces;
	size_t				len;

	len = ft_strlen(s);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i++;
	}
	spaces = i;
	if (s[i] != '\0')
	{
		i = len - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			i--;
			spaces++;
		}
	}
	return (len - spaces);
}

char					*ft_strtrim(char const *s)
{
	char				*str;
	size_t				i;
	size_t				j;
	size_t				trim_len;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	trim_len = ft_trimlen((char *)s);
	str = (char *)malloc(sizeof(*str) * (trim_len + 1));
	if (str == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (j < trim_len)
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}
