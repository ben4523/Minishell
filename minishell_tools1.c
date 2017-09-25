/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_tools1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 13:03:56 by ybitton           #+#    #+#             */
/*   Updated: 2017/05/23 13:43:35 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					is_alpha_string(char *s)
{
	int				i;

	i = 0;
	while (s[i])
	{
		if (('A' <= s[i] && s[i] <= 'Z') || ('a' <= s[i] && s[i] <= 'z'))
			i++;
		else
			return (0);
	}
	return (1);
}

void				free_list_elem(t_mini_l *tmp)
{
	free(tmp->name);
	free(tmp->data);
	ft_memdel((void **)&tmp);
}

t_mini_l			*create_list_full(void)
{
	char			prompt[1024];
	t_mini_l		*s1;
	t_mini_l		*s2;

	s1 = ft_memalloc(sizeof(t_mini_l));
	s2 = ft_memalloc(sizeof(t_mini_l));
	s1->next = s2;
	s2->next = NULL;
	s1->name = ft_strdup("PWD");
	s2->name = ft_strdup("SHLVL");
	if ((getcwd(prompt, sizeof(prompt))) == NULL)
		return (NULL);
	s1->data = ft_strdup(prompt);
	s2->data = ft_strdup("1");
	return (s1);
}

int					get_egal_pos_af(char *s)
{
	int				i;

	i = ft_strlen((char*)s);
	while (i >= 0)
	{
		if (s[i] == '=')
			return (i);
		i--;
	}
	return (0);
}

int					get_egal_pos_bf(char *s)
{
	int				y;
	int				i;

	i = 0;
	y = ft_strlen((char*)s);
	while (i < y)
	{
		if (s[i] == '=')
			return (i);
		i++;
	}
	return (0);
}
