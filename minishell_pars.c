/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 10:27:56 by ybitton           #+#    #+#             */
/*   Updated: 2017/05/18 13:38:06 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mini_l			*get_env(t_mini_l *env_fake, char **env)
{
	int				i;

	env_fake = NULL;
	i = 0;
	if (!env[0])
		env_fake = create_list_full();
	while (env && env[i])
		env_fake = put_n_list(env[i++], env_fake);
	return (env_fake);
}

t_mini_l			*put_n_list(char *env, t_mini_l *env_fake)
{
	t_mini_l		*new;
	t_mini_l		*cpy;

	cpy = env_fake;
	new = ft_memalloc(sizeof(t_mini_l));
	new->name = ft_strndup(env, get_pos_egal(env));
	new->data = remove_path_name(env, get_pos_egal(env) + 1);
	new->next = NULL;
	if (env_fake)
	{
		while (cpy->next != NULL)
			cpy = cpy->next;
		cpy->next = new;
		return (env_fake);
	}
	else
		return (new);
}

t_mini_l			*put_n_list_env(char *name, char *data, t_mini_l *env_fake)
{
	t_mini_l		*new;
	t_mini_l		*cpy;

	cpy = env_fake;
	new = ft_memalloc(sizeof(t_mini_l));
	new->name = ft_strdup(name);
	if (data)
		new->data = ft_strdup(data);
	else
		new->data = NULL;
	new->next = NULL;
	if (env_fake)
	{
		while (cpy->next != NULL)
			cpy = cpy->next;
		cpy->next = new;
		return (env_fake);
	}
	else
		return (new);
}

int					read_get_next(t_mini_l *env_fake)
{
	char			*src;
	char			**args;

	while (42)
	{
		prompt();
		if ((args = read_get_next1()) == NULL)
			continue ;
		if ((check_args(args, env_fake, &src) == 0) && del_split_tab(args))
		{
			free(src);
			return (1);
		}
		if (src != NULL)
			exec_fork_exv(src, args, env_fake);
		del_split_tab(args);
	}
	return (1);
}

char				**read_get_next1(void)
{
	char			*src;
	char			**args;

	src = NULL;
	args = NULL;
	if (get_next_line(0, &src) == -1)
	{
		ft_putendl_fd("./minishell: get_next_line can't read stdin", 2);
		return (NULL);
	}
	if ((args = ft_strtwosplit(src, ' ', '\t')) == NULL || args[0] == NULL)
	{
		del_split_tab(args);
		free(src);
		return (NULL);
	}
	free(src);
	src = NULL;
	return (args);
}
