/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:42:05 by ybitton           #+#    #+#             */
/*   Updated: 2016/12/15 14:23:26 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *big, const char *little)
{
	const char *biggg;
	const char *littleee;

	if (*little == '\0')
		return ((char*)big);
	while (*big != '\0')
	{
		biggg = big;
		littleee = little;
		while (*littleee != '\0' && *biggg == *littleee)
		{
			biggg++;
			littleee++;
		}
		if (*littleee == '\0')
			return ((char*)big);
		big++;
	}
	return (NULL);
}
