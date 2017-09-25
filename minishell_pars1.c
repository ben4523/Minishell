/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_pars1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 10:30:43 by ybitton           #+#    #+#             */
/*   Updated: 2017/05/23 14:41:46 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					check_args(char **args, t_mini_l *env_fake, char **path)
{
	*path = NULL;
	if (!ft_strcmp(args[0], "cd"))
		return (cd_function(env_fake, args));
	else if (!ft_strcmp(args[0], "echo"))
		return (echo_function(args));
	else if (!ft_strcmp(args[0], "setenv"))
		return (setenv_function(env_fake, args, 1));
	else if (!ft_strcmp(args[0], "unsetenv"))
		return (unsetenv_function(env_fake, args));
	else if (!ft_strcmp(args[0], "env"))
		return (env_function(env_fake, args));
	else if (!ft_strcmp(args[0], "getenv"))
		return (getenv_function(env_fake, args));
	else if (!ft_strcmp(args[0], "exit"))
		return (0);
	else
	{
		*path = get_good_path(env_fake, args[0]);
		return (1);
	}
}

char				*get_good_path(t_mini_l *env_fake, char *excute)
{
	int				i;
	char			**path;
	char			*result;

	if (ft_strchr(excute, '/') != NULL)
		if (!access(excute, F_OK))
			return (ft_strdup(excute));
	path = ft_strsplit(get_good_env(env_fake, "PATH"), ':');
	get_good_path1(path, excute);
	i = 0;
	while (path && path[i])
		if (!access(path[i], F_OK))
		{
			result = ft_strdup(path[i]);
			del_split_tab(path);
			return (result);
		}
		else
			i++;
	del_split_tab(path);
	ft_putendl_fd("minishell: No executable found", 2);
	return (NULL);
}

void				get_good_path1(char **path, char *excute)
{
	int				i;

	i = 0;
	while (path && path[i])
	{
		path[i] = ft_strjoin_free(path[i], "/", 1);
		path[i] = ft_strjoin_free(path[i], excute, 1);
		i++;
	}
}

void				exec_fork_exv(char *path, char **args, t_mini_l *env_fake)
{
	pid_t			father;
	char			**tab;

	father = fork();
	if (father == -1)
	{
		ft_putendl_fd("minishell: Fork error", 2);
		return ;
	}
	if (father > 0)
		waitpid(-1, 0, 0);
	if (father == 0)
	{
		tab = env_fake_list_to_tab(env_fake);
		if (execve(path, args, tab) == -1)
			ft_putendl_fd("minishell: Can't execut executable", 2);
		del_split_tab(tab);
	}
	if (path != NULL)
		free(path);
}

void				display_env_function(t_mini_l *cpy)
{
	if (cpy->data)
	{
		ft_putstr(cpy->name);
		ft_putstr("=");
		ft_putstr(cpy->data);
		ft_putstr("\n");
	}
	else
	{
		ft_putstr(cpy->name);
		ft_putstr("=");
		ft_putstr("\n");
	}
}
