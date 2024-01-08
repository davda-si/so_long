/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alct_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:06:42 by davda-si          #+#    #+#             */
/*   Updated: 2023/10/13 15:23:51 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	count_lines(char *argv)
{
	int		i;
	int		fd;
	char	c;

	i = 0;
	c = '\0';
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error opening file\n");
		return (0);
	}
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			i++;
	}
	if (c != '\n')
		i++;
	close(fd);
	return (i);
}

int	alct_map(t_mapper *game, char *argv)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(argv, O_RDONLY);
	game->h = count_lines(argv);
	if (game->h == 1)
	{
		ft_printf("Not a valid file\n");
		return (0);
	}
	game->map = (char **)malloc(sizeof(char *) * (game->h + 1));
	if (!game->map)
		return (0);
	while (i <= game->h)
	{
		game->map[i] = get_next_line(fd);
		if (!game->map[i])
			break ;
		i++;
	}
	game->map[i] = NULL;
	close(fd);
	return (1);
}
