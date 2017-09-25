/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_list_tools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 10:31:54 by ybitton           #+#    #+#             */
/*   Updated: 2017/05/17 10:39:04 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				del_env_fake_list(t_mini_l *env_fake)
{
	t_mini_l		*tmp;

	while (env_fake)
	{
		free(env_fake->name);
		if (env_fake->data)
			free(env_fake->data);
		tmp = env_fake->next;
		ft_memdel((void **)&env_fake);
		env_fake = tmp;
	}
}

char				*get_good_env(t_mini_l *env_fake, char *src)
{
	t_mini_l		*cpy;

	cpy = env_fake;
	while (cpy && ft_strcmp(cpy->name, src))
		cpy = cpy->next;
	if (cpy != NULL)
		return (cpy->data);
	else
		return (NULL);
}

char				**env_fake_list_to_tab(t_mini_l *env_fake)
{
	char			**tab;
	t_mini_l		*cpy;
	int				i;

	cpy = env_fake;
	i = 0;
	tab = ft_memalloc(sizeof(char**) * compt_list_fake_env(env_fake) + 1);
	while (cpy)
	{
		tab[i] = ft_strjoin(cpy->name, "=");
		tab[i] = ft_strjoin_free(tab[i], cpy->data, 1);
		cpy = cpy->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int					compt_list_fake_env(t_mini_l *env_fake)
{
	int				i;
	t_mini_l		*cpy;

	cpy = env_fake;
	i = 0;
	while (cpy)
	{
		cpy = cpy->next;
		i++;
	}
	return (i);
}

int					get_exist_env(t_mini_l *env_fake, char *src)
{
	t_mini_l		*cpy;

	cpy = env_fake;
	while (cpy && ft_strcmp(cpy->name, src))
		cpy = cpy->next;
	if (cpy != NULL)
		return (1);
	return (0);
}
