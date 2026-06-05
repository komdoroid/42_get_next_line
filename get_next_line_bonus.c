/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:52:35 by kkomurat          #+#    #+#             */
/*   Updated: 2026/06/05 20:31:56 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	char		*tmp;
	static char	*stash[OPEN_MAX];
	int			read_ret;

	buf = NULL;
	tmp = NULL;
	if (fd == -1 || BUFFER_SIZE < 0)
		return (NULL);
	read_ret = 1;
	while (gnl_strchr(stash[fd], '\n') == -1 && read_ret != 0)
	{
		buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buf)
			return (gnl_free(&stash[fd], &buf, &tmp));
		read_ret = read(fd, buf, BUFFER_SIZE);
		if (read_ret == -1 || read_ret == 0)
			return (gnl_free(&stash[fd], &buf, &tmp));
		buf[read_ret] = '\0';
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
	int		i;

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
	int		i;
	int		total;

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
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		fd2;
	char	*line;
	char	*line2;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("cant open\n");
		return (1);
	}
	fd2 = open("test2.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("cant open\n");
		return (1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line != NULL)
			printf("%s", line);
		line2 = get_next_line(fd2);
		if (line2 != NULL)
			printf("%s", line2);
		if (line == NULL && line2 == NULL)
			break;
	}
	free(line);
	free(line2);
	close(fd);
	close(fd2);
	return (0);
}
