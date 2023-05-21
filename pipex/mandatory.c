/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeomin <yeomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 08:29:43 by yeomin            #+#    #+#             */
/*   Updated: 2023/05/22 06:16:16 by yeomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putstr_fd(const char *s, int fd)
{
	size_t	i;

	i = 0;
	if (fd < 0)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && (i < n))
	{
		if ((unsigned const char)s1[i] != (unsigned const char)s2[i])
		{
			return ((unsigned const char) s1[i] - (unsigned const char) s2[i]);
		}
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	j = 0;
	if (!new_str)
		return (NULL);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}

char	**ft_path_finder(char *envp[])
{
	char	*path;

	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	path = *envp + 5;
	return (ft_split(path, ':'));
}

char	*ft_check_cmd(char **path, char *cmd)
{
	int		i;
	char	*path_cmd;
	char	*tmp;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	i = 0;
	while (path[i])
	{
		path_cmd = ft_strjoin("/", cmd);
		tmp = ft_strjoin(path[i], path_cmd);
		free(path_cmd);
		if (access(tmp, X_OK) == 0)
			return (tmp);
		free(tmp);
		i++;
	}
	return (NULL);
}

void	ft_first_child(t_arg *arg, int *fd, char *envp[])
{
	if (dup2(arg->infile_fd, 0) == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit(1);
	}
	if (dup2(fd[1], 1) == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit(1);
	}
	close(arg->infile_fd);
	close(fd[0]);
	close(fd[1]);
	if (execve(arg->front_cmd, arg->cmd1, envp) == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit(127);
	}
}

void	ft_last_child(t_arg *arg, int *fd, char *envp[])
{
	if (dup2(fd[0], 0) == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit(1);
	}
	if (dup2(arg->outfile_fd, 1) == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit(1);
	}
	close(arg->outfile_fd);
	close(fd[0]);
	close(fd[1]);
	if (execve(arg->back_cmd, arg->cmd2, envp) == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit(127);
	}
}

void	ft_make_pipe(t_arg *arg, char *envp[])
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];

	if (pipe(fd) < 0)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit(1);
	}
	pid1 = fork();
	if (pid1 == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit(1);
	}
	if (pid1 == 0)
		ft_first_child(arg, fd, envp);
	pid2 = fork();
	if (pid2 == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit(1);
	}
	if (pid2 == 0)
		ft_last_child(arg, fd, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, WNOHANG);
	waitpid(pid2, NULL, WNOHANG);
}

int	main(int ac, char *av[], char *envp[])
{
	t_arg	arg;

	if (ac == 5)
	{
		arg.infile_fd = open(av[1], O_RDONLY, 0644);
		if (arg.infile_fd == -1)
		{
			ft_putstr_fd(strerror(errno), 2);
		}
		arg.outfile_fd = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (arg.outfile_fd == -1)
		{
			ft_putstr_fd(strerror(errno), 2);
			exit(1);
		}
		if (!arg.outfile_fd | !arg.outfile_fd)
		{
			ft_putstr_fd(strerror(errno), 2);
			exit(1);
		}
		arg.path = ft_path_finder(envp);
		arg.cmd1 = ft_split(av[2], ' ');
		arg.cmd2 = ft_split(av[3], ' ');
		if (arg.cmd1 == NULL || arg.cmd2 == NULL)
		{
			ft_putstr_fd(strerror(errno), 2);
		}
		arg.front_cmd = ft_check_cmd(arg.path, arg.cmd1[0]);
		arg.back_cmd = ft_check_cmd(arg.path, arg.cmd2[0]);
		if (!arg.front_cmd || !arg.back_cmd)
			ft_putstr_fd(strerror(errno), 2);
		ft_make_pipe(&arg, envp);
		return (0);
	}
	else
	{	
		ft_putstr_fd(strerror(errno), 2);
		exit(1);
	}
}
