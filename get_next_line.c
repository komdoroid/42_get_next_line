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
	void	*buf;
	static char	*stash[OPEN_MAX];


	if (fd == -1)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (NULL)
	if (read(fd, buf, BUFFER_SIZE) == -1)
		return (NULL);
	stash[fd] = ft_strjoin(stash[fd], buf);
	while(1)
	{
		while (stash[fd][i])
		{
			if (stash[fd][i] == '\n')

}

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
