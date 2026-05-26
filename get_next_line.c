/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:52:35 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/26 17:02:03 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	if (!fd)
		return (NULL);
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
