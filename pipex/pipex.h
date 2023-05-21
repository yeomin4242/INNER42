/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeomin <yeomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:36:44 by yeomin            #+#    #+#             */
/*   Updated: 2023/05/22 04:05:13 by yeomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

typedef struct s_arg
{
	int		infile_fd;
	int		outfile_fd;
	char	**path;
	char	**cmd1;
	char	**cmd2;
	char	*front_cmd;
	char	*back_cmd;
	int		pipe_fds[2];
	char	*order1;
	char	*order2;
} t_arg;

size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);

#endif