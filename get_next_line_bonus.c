/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:52:35 by kkomurat          #+#    #+#             */
/*   Updated: 2026/06/07 15:52:17 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*ret;
	char		*tmp;

	stash = lead_to_stash(fd, stash);
	if (!stash || stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	ret = extract_line(stash);
	tmp = update_stash(stash);
	stash = tmp;
	return (ret);
}

char	*lead_to_stash(int fd, char *stash)
{
	char		*buf;
	int			read_len;
	char		*tmp;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	read_len = BUFFER_SIZE;
	while (!gnl_strchr(stash, '\n') && read_len > 0)
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len < 0)
		{
			free(buf);
			free(stash);
			return (NULL);
		}
		buf[read_len] = '\0';
		tmp = gnl_strjoin(stash, buf);
		free(stash);
		stash = tmp;
	}
	free(buf);
	return (stash);
}

char	*extract_line(char *stash)
{
	int		i;
	int		size;
	char	*ret;

	i = 0;
	size = 0;
	while (stash[size] && stash[size] != '\n')
		size++;
	ret = (char *)malloc(size + 2);
	if (!ret)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
	{
		ret[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		ret[i++] = '\n';
	ret[i] = '\0';
	return (ret);
}

char	*update_stash(char *stash)
{
	int		start;
	char	*ret;

	start = 0;
	while (stash[start] && stash[start] != '\n')
		start++;
	ret = ft_substr(stash, start + 1, ft_strlen(stash));
	if (!ret)
		return (NULL);
	free(stash);
	return (ret);
}

// #include <fcntl.h>
// #include <stdio.h>
// 
// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 
// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("cant open\n");
// 		return (1);
// 	}
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break;
// 		printf("%s", line);
// 		free(line);
// 		line = NULL;
// 	}
// 	close(fd);
// 	return (0);
// }
