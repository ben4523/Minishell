/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 17:24:02 by ybitton           #+#    #+#             */
/*   Updated: 2017/05/17 11:03:34 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					main(int argc, char **argv, char **env)
{
	t_mini_l		*env_fake;

	env_fake = NULL;
	if (argc != 1)
	{
		ft_putstr_fd("minishell: illegal option -- ", 2);
		ft_putendl_fd(argv[1], 2);
		ft_putendl_fd("usage: minishell", 2);
		return (-1);
	}
	env_fake = get_env(env_fake, env);
	read_get_next(env_fake);
	del_env_fake_list(env_fake);
	return (1);
}
