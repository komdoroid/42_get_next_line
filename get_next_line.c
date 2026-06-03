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

char	*get_next_line(int fd)
{
	char	*buf;
	char	*tmp;
	static char	*stash[OPEN_MAX];
	int	ret_code;
	int	line_break;


	if (fd == -1)
		return (NULL);
	ret_code = 0;
	line_break = -1;
	while (line_break == -1)
	{
		buf = malloc(sizeof(char) * BUFFER_SIZE);
		if (!buf)
			return (gnl_free(&stash[fd], &buf, &tmp))
		if (read(fd, buf, BUFFER_SIZE) == -1)
			return (gnl_free(&stash[fd], &buf, &tmp));
		tmp = ft_strjoin(stash[fd], buf);
		free(stash[fd]);
		stash[fd] = tmp;
		free(buf);
		free(tmp);
	}
	return (trim_stash(&stash[fd]));
}

char	*gnl_free(stash, buf, tmp)
{
	free(stash);
	free(buf);
	free(tmp);
	return (NULL);
}

char	*trim_stash(char *stash)
{
	while (stash[i] != '\n')
		i++;

int	main(int argc, char *argv[])
{
	FILE *fd;
	char	buffer[256];

	if (argc > 1)
	{
		fd = read();
		if (fd == NULL)
			return (1);
	}
	else 
		fd = stdin;
}
