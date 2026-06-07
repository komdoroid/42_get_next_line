/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:52:35 by kkomurat          #+#    #+#             */
/*   Updated: 2026/06/05 22:14:05 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stash;
	int			read_ret;

	buf = NULL;
	read_len = BFFER_SIZE
	while (gnl_strchr(stash, '\n') && read_len > 0)
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		if (stash == NULL)
			stash = "";
		stash = gnl_strjoin(stash, buf);
	}
	ret = extract_line(stash);
	stash = update_stash();
	return (ret);
}

char	*extract_line(char *stash)
{
	int	i;
	int	size;
	char	*ret;

	i = 0;
	size = 0;
	while (stash[size] && stash[size] != '\n')
		size++;
	ret = (char *)malloc(size + 2);
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
	int	start;
	char	*ret

	start = 0;
	while (stash[start] && stash[start] != '\n')
		start++;
	ret = ft_substr(stash, start + 1, ft_strlen(stash));
	free(stash);
	return (ret);
}

// #include <fcntl.h>
// #include <stdio.h>
// 
// int	main(void)
// {
// 	int		fd;
// 	int		fd2;
// 	char	*line;
// 	char	*line2;
// 
// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("cant open\n");
// 		return (1);
// 	}
// 	fd2 = open("test2.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("cant open\n");
// 		return (1);
// 	}
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line != NULL)
// 			printf("%s", line);
// 		line2 = get_next_line(fd2);
// 		if (line2 != NULL)
// 			printf("%s", line2);
// 		if (line == NULL && line2 == NULL)
// 			break;
// 	}
// 	free(line);
// 	free(line2);
// 	close(fd);
// 	close(fd2);
// 	return (0);
// }
