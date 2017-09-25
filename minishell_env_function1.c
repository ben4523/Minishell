/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_env_function1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:56:16 by ybitton           #+#    #+#             */
/*   Updated: 2017/05/23 14:33:25 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					unsetenv_function(t_mini_l *env_fake, char **args)
{
	t_mini_l		*cpy;
	t_mini_l		*current;
	t_mini_l		*previous;
	t_mini_l		*tmp;

	cpy = env_fake;
	current = cpy->next;
	previous = cpy;
	if (!args[1])
		ft_putendl_fd("Minishell : unsetenv: Too few arguments.", 2);
	else
		while (current != NULL && previous != NULL)
		{
			if (ft_strcmp(current->name, args[1]) == 0)
			{
				tmp = current;
				previous->next = current->next;
				free_list_elem(tmp);
				return (2);
			}
			current = current->next;
			previous = previous->next;
		}
	return (2);
}

int					getenv_function(t_mini_l *env_fake, char **args)
{
	t_mini_l		*cpy;

	cpy = env_fake;
	if (!args[1])
		return (2);
	while (cpy && ft_strcmp(cpy->name, args[1]))
		cpy = cpy->next;
	if (cpy != NULL)
	{
		ft_putstr(cpy->data);
		ft_putstr("\n");
	}
	else
		ft_putendl_fd("Minishell : getenv: variable not found.", 2);
	return (2);
}

int					echo_function(char **args)
{
	int				i;

	i = 1;
	if (!args[1])
		ft_putchar('\n');
	else if (args[1] && !ft_strcmp(args[1], "-n"))
	{
		while (args[i + 1])
		{
			ft_putstr(args[i++ + 1]);
			if (args[i + 1])
				ft_putchar(' ');
		}
	}
	else if (args[1])
	{
		while (args[i])
		{
			ft_putstr(args[i++]);
			if (args[i])
				ft_putchar(' ');
		}
		ft_putstr("\n");
	}
	return (2);
}

int					env_ex_function(t_mini_l *env_fake, char **args)
{
	char			*path;
	char			**tab;

	path = NULL;
	tab = NULL;
	tab = env_tab_cpy(args);
	path = get_good_path(env_fake, args[1]);
	if (path != NULL)
		exec_fork_exv(path, tab, env_fake);
	del_split_tab(tab);
	return (2);
}

void				env_add_function(t_mini_l *env_fake, char **args)
{
	char			**new;
	int				i;

	i = 1;
	new = malloc(sizeof(char **) * 3 + 1);
	while (args[i])
	{
		new[0] = NULL;
		new[1] = ft_strndup(args[i], get_egal_pos_bf(args[i]));
		new[2] = ft_strsdup(args[i], get_egal_pos_af(args[i]) + 1);
		i++;
		setenv_function(env_fake, new, 0);
		free(new[1]);
		free(new[2]);
	}
	free(new);
	new = NULL;
}
