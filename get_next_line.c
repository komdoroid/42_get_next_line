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
	static char	*stash[OPEN_MAX];
	int			read_ret;

	buf = NULL;
	read_len = BFFER_SIZE
	while (gnl_strchr(stash, '\n') && read_len > 0)
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		stash = gnl_strjoin();
	}
	ret = extract_line();
	stash = update_stash();
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
