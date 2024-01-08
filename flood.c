/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:05:16 by davda-si          #+#    #+#             */
/*   Updated: 2023/10/13 15:50:31 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	ft_flood(t_mapper *game, int x, int y, char **n_map)
{
	if (n_map[y][x] == '1' || n_map[y][x] == 'F' || n_map[y][x] == 'B')
		return ;
	else if (n_map[y][x] == 'C')
		game->cp--;
	else if (n_map[y][x] == 'E')
	{
		game->ep = 1;
		return ;
	}
	n_map[y][x] = 'F';
	ft_flood(game, x - 1, y, n_map);
	ft_flood(game, x + 1, y, n_map);
	ft_flood(game, x, y - 1, n_map);
	ft_flood(game, x, y + 1, n_map);
}

void	cpy_map(t_mapper *game)
{
	int		i;
	char	**n_map;

	game->cp = game->c;
	n_map = (char **)ft_calloc(sizeof(char *), (game->h + 1));
	if (!n_map)
		return ;
	i = 0;
	while (game->map[i])
	{
		n_map[i] = ft_strdup(game->map[i]);
		i++;
	}
	n_map[i] = NULL;
	ft_flood(game, game->p_x, game->p_y, n_map);
	free_map(n_map);
	if (game->cp != 0 || game->ep != 1)
	{
		ft_printf("Error, map not winnable\n");
		free_map(game->map);
		exit(1);
	}
}
