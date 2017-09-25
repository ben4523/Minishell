/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_env_function.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 10:35:13 by ybitton           #+#    #+#             */
/*   Updated: 2017/05/23 14:41:37 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					setenv_function(t_mini_l *env_fake, char **args, int a)
{
	char			*resp;

	if (args[1] == NULL)
		env_function(env_fake, args);
	else if (a && !is_alpha_string(args[1]))
		ft_putendl_fd("setenv: Variable name must alphanumeric characters", 2);
	else if (get_exist_env(env_fake, args[1]))
	{
		resp = get_good_env(env_fake, args[1]);
		if (args[2])
		{
			if (resp != NULL && !ft_strcmp(args[2], resp))
				return (2);
			else
				modif_env_exis(args[1], args[2], env_fake);
		}
		else
			modif_env_exis(args[1], NULL, env_fake);
	}
	else
		setenv_function1(env_fake, args);
	return (2);
}

void				setenv_function1(t_mini_l *env_fake, char **args)
{
	if (args[2])
		env_fake = put_n_list_env(args[1], args[2], env_fake);
	else
		env_fake = put_n_list_env(args[1], NULL, env_fake);
}

void				modif_env_exis(char *name, char *data, t_mini_l *env_fake)
{
	t_mini_l		*cpy;

	cpy = env_fake;
	while (cpy && ft_strcmp(cpy->name, name))
		cpy = cpy->next;
	if (cpy != NULL)
	{
		if (data)
		{
			if (cpy->data)
			{
				free(cpy->data);
				cpy->data = NULL;
			}
			cpy->data = ft_strdup(data);
		}
		else
		{
			free(cpy->data);
			cpy->data = NULL;
		}
	}
	else
		modif_env_exis_new(name, data, env_fake);
}

void				modif_env_exis_new(char *name, char *data,
						t_mini_l *env_fake)
{
	t_mini_l		*cpy;
	t_mini_l		*new;

	cpy = env_fake;
	while (cpy->next != NULL)
		cpy = cpy->next;
	new = malloc(sizeof(t_mini_l));
	new->data = ft_strdup(data);
	new->name = ft_strdup(name);
	new->next = NULL;
	cpy->next = new;
}

int					env_function(t_mini_l *env_fake, char **args)
{
	t_mini_l		*cpy;

	cpy = env_fake;
	if (args[1] && !ft_strcmp(args[1], "-i"))
		return (2);
	else if (args[1] && !ft_strchr(args[1], '='))
		return (env_ex_function(env_fake, args));
	else if (args[1] && ft_strchr(args[1], '='))
		env_add_function(env_fake, args);
	while (cpy)
	{
		display_env_function(cpy);
		cpy = cpy->next;
	}
	return (2);
}
