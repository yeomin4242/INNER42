/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeomin <yeomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:36:00 by yeomin            #+#    #+#             */
/*   Updated: 2023/05/16 04:09:31 by yeomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*ft_strdup(const char *s1);
char	*ft_free_check(char **str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_nextline_check(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_bufdup(char *buf);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif