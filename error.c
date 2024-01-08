/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:53:23 by davda-si          #+#    #+#             */
/*   Updated: 2023/10/13 15:38:39 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	error_handle(int i, t_mapper *game)
{
	if (i == 0)
	{
		ft_printf("Error, no map detected\n");
		exit (0);
	}
	if (i == 1)
	{
		ft_printf("Not a valid file\n");
		exit (0);
	}
	if (i == 2)
	{
		ft_printf("Error, shutting the game down\n");
		if (game->map)
			free_map(game->map);
		exit (0);
	}
	exit (0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	map = NULL;
}
