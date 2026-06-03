/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:52:35 by kkomurat          #+#    #+#             */
/*   Updated: 2026/06/02 23:33:41 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*buf;
	char	*tmp;
	static char	*stash[OPEN_MAX];
	int	read_ret;

	buf = NULL;
	tmp = NULL;
	if (fd == -1)
		return (NULL);
	while (gnl_strchr(stash[fd], '\n') == -1 && read_ret!= 0)
	{
		buf = malloc(sizeof(char) * BUFFER_SIZE);
		if (!buf)
			return (gnl_free(&stash[fd], &buf, &tmp));
		read_ret = read(fd, buf, BUFFER_SIZE);
		if (read_ret == -1 || read_ret == 0)
			return (gnl_free(&stash[fd], &buf, &tmp));
		tmp = gnl_strjoin(stash[fd], buf);
		free(stash[fd]);
		stash[fd] = tmp;
		free(buf);
	}
	return (extract_line(&stash[fd], gnl_strchr(stash[fd], '\n')));
}

char	*gnl_free(char **stash, char **buf, char **tmp)
{
	free(*stash);
	*stash = NULL;
	free(*buf);
	free(*tmp);
	return (NULL);
}

char	*extract_line(char **stash, int size)
{
	char	*ret;
	int	i;

	if (!*stash || (*stash)[0] == '\0')
		return (NULL);
	if (size == -1)
		size = ft_strlen(*stash);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ret[i] = (*stash)[i];
		i++;
	}
	ret[i] = '\0';
	update_stash(stash, size);
	return (ret);
}

void	update_stash(char **stash, int size)
{
	char	*ret;
	int	i;
	int	total;

	total = ft_strlen(*stash);
	ret = (char *)malloc(sizeof(char) * (total - size + 1));
	if (!ret)
		return ;
	i = 0;
	while (i + size < total)
	{
		ret[i] = (*stash)[i + size];
		i++;
	}
	ret[i] = '\0';
	free(*stash);
	*stash = ret;
}

#include <fcntl.h>

int	main(void)
{
	int	fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("cant open\n");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
