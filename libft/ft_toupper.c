/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:52:44 by ybitton           #+#    #+#             */
/*   Updated: 2016/12/15 14:23:16 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_toupper(int c)
{
	if (ft_isalpha(c) && ('a' <= c && c <= 'z'))
		return (c - 'a' + 'A');
	else
		return (c);
}