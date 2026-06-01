/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomurat <kkomurat@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 17:37:32 by kkomurat          #+#    #+#             */
/*   Updated: 2026/05/31 17:40:49 by kkomurat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	append_and_show(char *new_data)
{
	static char *stash = NULL;

	if (stash == NULL)
		stash = strdup(new_data);
	else
	{
		char *tmp = malloc(strlen(stash) + strlen(new_data) + 1);
		strcpy(tmp, stash);
		strcat(tmp, new_data);
		free(stash);
		stash = tmp;
	}
	printf("now stash: [%s]\n", stash);
}

int	main(void)
{
	append_and_show("Hello");
	append_and_show(", ");
	append_and_show("World");
	return (0);
}
