/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:17:17 by kkomurat          #+#    #+#             */
/*   Updated: 2026/06/05 20:24:55 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# define OPEN_MAX 1024

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*gnl_free(char **stash, char **buf, char **tmp);
char	*extract_line(char **stash, int size);
void	update_stash(char **stash, int size);
int		ft_strlen(const char *str);
char	*gnl_strjoin(char const *s1, char const *s2);
int		gnl_strchr(const char *s, int c);
#endif
