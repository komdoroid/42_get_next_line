/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:17:17 by kkomurat          #+#    #+#             */
/*   Updated: 2026/06/07 16:47:42 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# define OPEN_MAX 1024

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*lead_to_stash(int fd, char *stash);
char	*extract_line(char *stash);
char	*update_stash(char *stash);
int		ft_strlen(const char *str);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*gnl_strchr(char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
#endif
