/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeomin <yeomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 04:09:10 by yeomin            #+#    #+#             */
/*   Updated: 2023/05/16 04:09:21 by yeomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_size(int fd, char *buf)
{
	int		read_size;
	char	*new_line;

	read_size = -1;
	new_line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!new_line)
		return (ft_free_check(&buf));
	while (ft_nextline_check(buf, '\n') == 0 && read_size != 0)
	{
		read_size = read(fd, new_line, BUFFER_SIZE);
		if (read_size == -1)
		{
			ft_free_check(&new_line);
			return (ft_free_check(&buf));
		}
		new_line[read_size] = '\0';
		buf = ft_strjoin(buf, new_line);
		if (!buf)
		{
			ft_free_check(&new_line);
			return (ft_free_check(&buf));
		}
	}
	ft_free_check(&new_line);
	return (buf);
}

char	*ft_bufdup(char *buf)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!buf)
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
		dest[i++] = buf[j++];
	if (buf[i] == '\n')
		dest[i++] = buf[j++];
	dest[i] = '\0';
	return (dest);
}

char	*ft_leftovers_read(char *buf)
{
	char	*left_buf;
	int		i;
	int		j;

	i = 0;
	j = ft_nextline_check(buf, '\n');
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
		return (ft_free_check(&buf));
	left_buf = (char *)malloc(sizeof(char) * (ft_strlen(buf) - i));
	if (!left_buf)
		return (ft_free_check(&buf));
	i = 0;
	while (buf[j])
		left_buf[i++] = buf[j++];
	left_buf[i] = '\0';
	ft_free_check(&buf);
	return (left_buf);
}

char	*get_next_line(int fd)
{
	static char	*buf[4096];
	char		*new_line;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > 4096)
		return (NULL);
	buf[fd] = ft_read_size(fd, buf[fd]);
	if (!buf[fd])
	{
		buf[fd] = ft_strdup("");
		if (!buf[fd])
			return (ft_free_check(&buf[fd]));
	}
	if (!buf[fd][0])
		return (ft_free_check(&buf[fd]));
	new_line = ft_bufdup(buf[fd]);
	if (!new_line)
		return (ft_free_check(&buf[fd]));
	buf[fd] = ft_leftovers_read(buf[fd]);
	return (new_line);
}
