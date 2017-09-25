/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 10:36:45 by ybitton           #+#    #+#             */
/*   Updated: 2017/05/23 14:06:28 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				prompt(void)
{
	int				i;
	char			prompt[1024];
	char			*new;

	i = 0;
	if ((getcwd(prompt, sizeof(prompt))) == NULL)
		return ;
	i = ft_strlen(prompt);
	while (i >= 0 && prompt[i] != '/')
		i--;
	new = ft_strdup(prompt + i + 1);
	ft_putstr_fd(FC_YELLOW, 1);
	ft_putstr_fd(new, 1);
	ft_putstr_fd(" $>  ", 1);
	ft_putstr_fd(FC_NOCOLOR, 1);
	free(new);
}

char				*remove_path_name(char *s, int t)
{
	int				i;
	int				v;
	char			*final;

	i = t;
	v = 0;
	final = ft_strnew(ft_strlen(s) - t);
	while (s[i])
		final[v++] = s[i++];
	return (final);
}

int					get_pos_egal(char *s)
{
	int				i;

	i = 0;
	while (s[i] != '=')
		i++;
	return (i);
}

int					del_split_tab(char **s)
{
	int				i;

	i = 0;
	while (s && s[i])
		free(s[i++]);
	free(s);
	s = NULL;
	return (1);
}

int					count_tab_col(char **args)
{
	int				i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}
