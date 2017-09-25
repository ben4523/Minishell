/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:27:16 by ybitton           #+#    #+#             */
/*   Updated: 2017/05/15 14:34:29 by ybitton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 9
# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_fd
{
	int				n_fd;
	char			*str;
	struct s_fd		*next;
}					t_fd;

typedef struct		s_lst
{
	int				fd;
	char			*reste;
	struct s_lst	*next;
}					t_lst;

int					get_next_line(const int fd, char **line);
#endif
