/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:45:20 by davda-si          #+#    #+#             */
/*   Updated: 2023/10/13 15:28:34 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	ret_it(t_mapper *game)
{
	int	i;
	int	j;
	int	len;
	int	tmp;

	i = 0;
	j = 0;
	len = ft_strlen_solong(game->map[0]);
	while (game->map[i] && game->map[i][0] == '1')
		i++;
	while (j < i)
	{
		tmp = ft_strlen_solong(game->map[j]);
		if (tmp != len)
			return (0);
		j++;
	}
	return (1);
}

static void	add_bot(t_mapper *game, int i, int j)
{
	game->bot[game->b].x = j;
	game->bot[game->b].y = i;
	game->b++;
}

static int	check_pce(t_mapper *game)
{
	static int	i;
	int			j;

	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!ft_valid(game->map[i][j]))
				return (0);
			if (game->map[i][j] == 'P')
				add_player(game, i, j);
			if (game->map[i][j] == 'C')
				game->c++;
			if (game->map[i][j] == 'E')
				game->e++;
			if (game->map[i][j] == 'B')
				add_bot(game, i, j);
			j++;
		}
		i++;
	}
	if (game->p != 1 || game->e != 1 || game->c == 0)
		return (0);
	return (1);
}

static int	find_walls(t_mapper *game)
{
	int	i;

	i = 0;
	game->l = ft_strlen_solong(game->map[0]) - 1;
	while (i < game->h)
	{
		if ((game->map[i][0] != '1') || (game->map[i][game->l] != '1'))
			return (0);
		i++;
	}
	i = 0;
	while (i < game->l)
	{
		if ((game->map[0][i] != '1') || (game->map[game->h - 1][i] != '1'))
			return (0);
		i++;
	}
	return (1);
}

int	check_map(t_mapper *game)
{
	if (game->map[0] == NULL)
		return (0);
	if (find_walls(game) && check_pce(game) && ret_it(game))
		return (1);
	return (0);
}
