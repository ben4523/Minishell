/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 17:27:57 by ybitton           #+#    #+#             */
/*   Updated: 2017/05/23 14:41:56 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "libft/ft_printf.h"

typedef struct		s_mini_l
{
	char			*data;
	char			*name;
	struct s_mini_l	*next;
}					t_mini_l;

# define FC_NOCOLOR	"\033[0m"
# define FC_YELLOW	"\033[033m"

void				prompt(void);
int					check_args(char **args, t_mini_l *env_fake, char **path);
int					read_get_next(t_mini_l *env_fake);
char				**read_get_next1(void);
char				*get_good_path(t_mini_l *env_fake, char *excute);
char				*remove_path_name(char *s, int t);
int					get_pos_egal(char *s);
t_mini_l			*get_env(t_mini_l *env_fake, char **env);
char				*get_good_env(t_mini_l *env_fake, char *src);
int					get_exist_env(t_mini_l *env_fake, char *src);
void				del_env_fake_list(t_mini_l *env_fake);
t_mini_l			*put_n_list(char *env, t_mini_l *env_fake);
t_mini_l			*put_n_list_env(char *name, char *data, t_mini_l *env_fake);
char				*get_good_env(t_mini_l *env_fake, char *src);
t_mini_l			*get_env(t_mini_l *env_fake, char **env);
int					del_split_tab(char **s);
t_mini_l			*create_list_full(void);
void				exec_fork_exv(char *path, char **args, t_mini_l *env_fake);
int					env_function(t_mini_l *env_fake, char **args);
int					get_exist_env(t_mini_l *env_fake, char *src);
int					unsetenv_function(t_mini_l *env_fake, char **args);
int					echo_function(char **args);
int					check_stat_cd(char *chemin);
void				cd_exec_dir(t_mini_l *env_fake, char prompt[1024],
						char *dst);
void				cd_exec_dir_v1(t_mini_l *env_fake, char prompt[1024],
						char *dst);
int					cd_function(t_mini_l *env_fake, char **args);
int					setenv_function(t_mini_l *env_fake, char **args, int a);
void				free_list_elem(t_mini_l *tmp);
void				modif_env_exis(char *name, char *data, t_mini_l *env_fake);
int					compt_list_fake_env(t_mini_l *env_fake);
char				**env_fake_list_to_tab(t_mini_l *env_fake);
int					is_alpha_string(char *s);
void				get_good_path1(char	**path, char *excute);
void				setenv_function1(t_mini_l *env_fake, char **args);
int					getenv_function(t_mini_l *env_fake, char **args);
void				modif_env_exis_new(char *name, char *data,
						t_mini_l *env_fake);
int					env_ex_function(t_mini_l *env_fake, char **args);
void				env_add_function(t_mini_l *env_fake, char **args);
int					get_egal_pos_bf(char *s);
int					get_egal_pos_af(char *s);
char				**env_tab_cpy(char **args);
int					count_tab_col(char **args);
void				display_env_function(t_mini_l *cpy);
#endif
