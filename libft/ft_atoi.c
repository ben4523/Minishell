/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:21:31 by ybitton           #+#    #+#             */
/*   Updated: 2017/03/02 14:33:43 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int		is_nb(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int		get_sign(char c, char m, int *idx)
{
	if (c == '-' && is_nb(m))
	{
		*idx += 1;
		return (-1);
	}
	if (c == '+' && is_nb(m))
	{
		*idx += 1;
		return (1);
	}
	if (is_nb(c))
		return (1);
	else
		return (0);
}

int				ft_atoi(const char *str)
{
	int idx;
	int sign;
	int result;

	idx = 0;
	sign = 1;
	result = 0;
	while (str[idx] == ' ' || str[idx] == '\t' || str[idx] == '\n' || str[idx]
			== '\v' || str[idx] == '\r' || str[idx] == '\f')
		idx++;
	sign = get_sign(str[idx], str[idx + 1], &idx);
	while (is_nb(str[idx]))
	{
		result = result * 10 + str[idx] - '0';
		idx++;
	}
	return (result * sign);
}
