/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cd_function.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 10:34:17 by ybitton           #+#    #+#             */
/*   Updated: 2017/05/23 14:21:39 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					check_stat_cd(char *chemin)
{
	struct stat		sb;

	if (lstat(chemin, &sb) == -1)
	{
		ft_putstr_fd("Minishell : cd: no such file or directory:", 2);
		ft_putendl_fd(chemin, 2);
		return (0);
	}
	return (1);
}

void				cd_exec_dir(t_mini_l *env_fake, char prompt[1024],
						char *dst)
{
	char			*env;

	if (ft_strcmp(dst, "HOME") == 0)
	{
		env = get_good_env(env_fake, "HOME");
		if (check_stat_cd(env))
			chdir(env);
		else
			return ;
		modif_env_exis("OLDPWD", prompt, env_fake);
		modif_env_exis("PWD", env, env_fake);
	}
	else if (ft_strcmp(dst, "OLDPWD") == 0)
	{
		env = get_good_env(env_fake, "OLDPWD");
		if (check_stat_cd(env))
			chdir(env);
		else
			return ;
		modif_env_exis("OLDPWD", prompt, env_fake);
		modif_env_exis("PWD", env, env_fake);
	}
	else
		cd_exec_dir_v1(env_fake, prompt, dst);
}

void				cd_exec_dir_v1(t_mini_l *env_fake, char prompt[1024],
						char *dst)
{
	char			prompt1[1024];

	modif_env_exis("OLDPWD", prompt, env_fake);
	chdir(dst);
	getcwd(prompt1, sizeof(prompt1));
	modif_env_exis("PWD", prompt1, env_fake);
}

int					cd_function(t_mini_l *env_fake, char **args)
{
	char			prompt[1024];

	if ((getcwd(prompt, sizeof(prompt))) == NULL)
		return (2);
	if (!args[1])
	{
		if (get_good_env(env_fake, "HOME") == NULL)
			ft_putendl_fd("Minishell : cd: No home directory.", 2);
		else
			cd_exec_dir(env_fake, prompt, "HOME");
	}
	else if (ft_strcmp(args[1], "-") == 0)
	{
		if (get_good_env(env_fake, "OLDPWD") == NULL)
			ft_putendl_fd("Minishell : cd: OLDPWD not set.", 2);
		else
			cd_exec_dir(env_fake, prompt, "OLDPWD");
	}
	else
	{
		if (check_stat_cd(args[1]))
			cd_exec_dir(env_fake, prompt, args[1]);
	}
	return (2);
}

char				**env_tab_cpy(char **args)
{
	int				i;
	int				y;
	char			**tab;

	i = 1;
	y = 0;
	tab = malloc(sizeof(char **) * count_tab_col(args) + 1);
	while (args[i])
	{
		tab[y] = ft_strdup(args[i]);
		i++;
		y++;
	}
	tab[y] = NULL;
	return (tab);
}
